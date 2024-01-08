#include "MainScreen.h"

sf::Sound MainScreen::introSound;
sf::SoundBuffer MainScreen::introBuff;
sf::Sound& MainScreen::getIntroSound() {
	return introSound;
}
bool MainScreen::musicEnabledMain = true;

MainScreen::MainScreen(sf::RenderWindow& window) :
	Screen(window),
	playButton("", { 180, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & playButtonTex),
	instructionButton("", { 400, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & intButtonTex),
	settingButton("", { 300, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & settingButtonTex),
	exitButton("", { 140, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & exitButtonTex),
	introFrames(0),
	currentIntroImage(0)
{
	initBackground(window);
	initPlayButton();
	initInstructionButton();
	initSettingButton();
	initExitButton();
	initIntroSound();
	introSoundPlayed = false;

	for (int i = 1; i < 46; ++i) {
		sf::Texture introTexture;
		if (introTexture.loadFromFile("Material/Backgrounds/IntroScreen/intro" + std::to_string(i) + ".png")) {
			introTextures.push_back(introTexture);
		}
		else {
			std::cout << "Intro" << i << ".png not found!\n";
		}
	}
}

void MainScreen::initBackground(sf::RenderWindow& window)
{
	// Load main screen background from file
	if (!mainScreen1Tex.loadFromFile("Material/Backgrounds/MainScreens/MainScreen1.png"))
		std::cout << "MainScreen1 not found!\n";
	mainScreen1Tex.setSmooth(true);
	if (!mainScreen2Tex.loadFromFile("Material/Backgrounds/MainScreens/MainScreen2.png"))
		std::cout << "MainScreen1 not found!\n";
	mainScreen2Tex.setSmooth(true);
	// Random from 2 backgrounds
	srand(time(0));
	if (!(rand() % 50))
		mainScreen.setTexture(mainScreen2Tex);
	else
		mainScreen.setTexture(mainScreen1Tex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / mainScreen1Tex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / mainScreen1Tex.getSize().y;
	mainScreen.setScale(scaleX, scaleY);

	// Play button
	if (!playButtonTex.loadFromFile("Material/Buttons/Play.png"))
		std::cout << "Play not found!\n";
	playButtonTex.setSmooth(true);

	// Instruction button
	if (!intButtonTex.loadFromFile("Material/Buttons/Instruction.png"))
		std::cout << "Instruction not found!\n";
	intButtonTex.setSmooth(true);

	// Setting button
	if (!settingButtonTex.loadFromFile("Material/Buttons/Settings.png"))
		std::cout << "Settings not found!\n";
	settingButtonTex.setSmooth(true);

	// Exit button
	if (!exitButtonTex.loadFromFile("Material/Buttons/Exit.png"))
		std::cout << "Exit not found!\n";
	exitButtonTex.setSmooth(true);
}

void MainScreen::initPlayButton()
{
	playButton.setFont(font);
	playButton.setPosition({ 677, 300 });
	playButton.setOutlineThickness(2);
	playButton.setBackgroundAnimation(&playButtonTex);
}

void MainScreen::initInstructionButton()
{
	instructionButton.setFont(font);
	instructionButton.setPosition({ 570, 400 });
	instructionButton.setOutlineThickness(2);
	instructionButton.setBackgroundAnimation(&intButtonTex);
}

void MainScreen::initSettingButton()
{
	settingButton.setFont(font);
	settingButton.setPosition({ 610, 500 });
	settingButton.setOutlineThickness(2);
	settingButton.setBackgroundAnimation(&settingButtonTex);
}

void MainScreen::initExitButton()
{
	exitButton.setFont(font);
	exitButton.setPosition({ 690, 600 });
	exitButton.setOutlineThickness(2);
	exitButton.setBackgroundAnimation(&exitButtonTex);
}

void MainScreen::initIntroSound()
{
	if (!introSound.getBuffer())
	{
		if (!introBuff.loadFromFile("Sound/Intro.wav"))
			std::cout << "intro.wav not found!\n";
		introSound.setBuffer(introBuff);
	}
}

void MainScreen::setMusicState(bool musicState) {
	musicEnabledMain = musicState;

	// Stop or play music based on the state
	if (musicEnabledMain) {
		getIntroSound().play();
	}
	else {
		getIntroSound().stop();
	}
}

void MainScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (playButton.isMouseOver(window))
		{
			currentScreen = ScreenState::LogInScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (instructionButton.isMouseOver(window))
		{
			currentScreen = ScreenState::InstructionScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (settingButton.isMouseOver(window))
		{
			currentScreen = ScreenState::SettingScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (exitButton.isMouseOver(window))
		{
			window.close();
		}
	}
}

void MainScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		if (introFrames < 46 * 13)  // Assuming 8 seconds of intro with 60 frames per second //46 * 13
		{
			// Display intro images
			window.clear();
			sf::Sprite introSprite(introTextures[currentIntroImage]);
			introSprite.setScale(window.getSize().x / introSprite.getLocalBounds().width,
				window.getSize().y / introSprite.getLocalBounds().height);
			window.draw(introSprite);
			window.display();
			sf::sleep(sf::milliseconds(16));
			introFrames++;

			// Move to the next intro image every 60 frames
			if (introFrames % 13 == 0) {
				currentIntroImage++;
				if (currentIntroImage >= introTextures.size()) {
					// Intro has finished, switch to the main menu
					introFrames = 46 * 13;  
				}
			}
			return;
		}

		playButton.update(window);
		instructionButton.update(window);
		settingButton.update(window);
		exitButton.update(window);
	}
	else
	{

	}
}

void MainScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.draw(mainScreen);
		playButton.drawTo(window);
		instructionButton.drawTo(window);
		settingButton.drawTo(window);
		exitButton.drawTo(window);
	}
}