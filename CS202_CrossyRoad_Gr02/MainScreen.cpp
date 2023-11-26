#include "MainScreen.h"

MainScreen::MainScreen(sf::RenderWindow& window) :
	Screen(window),
	playButton("", { 180, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & playButtonTex),
	instructionButton("", { 400, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & intButtonTex),
	settingButton("", { 300, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & settingButtonTex),
	exitButton("", { 140, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & exitButtonTex)
{
	initBackground(window);
	initPlayButton();
	initInstructionButton();
	initSettingButton();
	initExitButton();
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

void MainScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (playButton.isMouseOver(window))
		{
			currentScreen = ScreenState::GamePlayScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (instructionButton.isMouseOver(window))
		{

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
		playButton.update(window);
		instructionButton.update(window);
		settingButton.update(window);
		exitButton.update(window);
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