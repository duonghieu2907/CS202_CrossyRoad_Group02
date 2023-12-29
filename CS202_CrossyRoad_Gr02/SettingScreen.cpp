#include "SettingScreen.h"
#include "MainScreen.h"
#include "Button.h"
#include "Character.h"


SettingScreen::SettingScreen(sf::RenderWindow& window) :
	Screen(window),
	backButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex),
	saveButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & saveButtonTex),
	musicOnButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & musicOnButtonTex1),
	musicOffButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & musicOffButtonTex1),
	controlsOnButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & controlsOnButtonTex1),
	controlsOffButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & controlsOffButtonTex1),
	musicEnabled(true),
	musicEnabledMain(true),
	useWASDControls(true)

{
	initBackground(window);
	initBackButton();
	initSaveButton();
	initMusicButton();
	initControlsButton();
	stopAllSounds();
	toggleMusicState();
	toggleControls();
}

void SettingScreen::initBackground(sf::RenderWindow& window)
{
	// Load setting screen background from file
	if (!settingScreen1Tex.loadFromFile("Material/Backgrounds/SettingScreens/SettingScreen1.png"))
		std::cout << "SettingScreen1 not found!\n";
	settingScreen1Tex.setSmooth(true);
	if (!settingScreen2Tex.loadFromFile("Material/Backgrounds/SettingScreens/SettingScreen2.png"))
		std::cout << "SettingScreen1 not found!\n";
	settingScreen2Tex.setSmooth(true);
	// Random from 2 backgounds
	srand(time(0));
	if (!(rand() % 50))
		settingScreen.setTexture(settingScreen2Tex);
	else
		settingScreen.setTexture(settingScreen1Tex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / settingScreen1Tex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / settingScreen1Tex.getSize().y;
	settingScreen.setScale(scaleX, scaleY);

	//Instruction Music
	HeaderMusicText.setFont(font);
	HeaderMusicText.setCharacterSize(40);
	HeaderMusicText.setFillColor(sf::Color::Black);
	HeaderMusicText.setPosition(400, 250);
	HeaderMusicText.setString("Music");
	HeaderMusicText.setFont(font);

	//Instruction Controls
	HeaderControlsText.setFont(font);
	HeaderControlsText.setCharacterSize(40);
	HeaderControlsText.setFillColor(sf::Color::Black);
	HeaderControlsText.setPosition(400, 400);
	HeaderControlsText.setString("Use WASD control");
	HeaderControlsText.setFont(font);


	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back.png"))
		std::cout << "Back not found!\n";
	backButtonTex.setSmooth(true);

	// Save button
	if (!saveButtonTex.loadFromFile("Material/Buttons/Save.png"))
		std::cout << "Save hover not found!\n";
	saveButtonTex.setSmooth(true);

	// music on button
	if (!musicOnButtonTex1.loadFromFile("Material/Buttons/On_clicked.png") ||
		!musicOnButtonTex2.loadFromFile("Material/Buttons/On.png"))
		std::cout << "Failed to load on button textures!\n";
	musicOnButtonTex1.setSmooth(true);
	musicOnButtonTex2.setSmooth(true);

	//music off button
	if (!musicOffButtonTex1.loadFromFile("Material/Buttons/Off.png") ||
		!musicOffButtonTex2.loadFromFile("Material/Buttons/Off_clicked.png"))
		std::cout << "Failed to load off button textures!\n";
	musicOffButtonTex1.setSmooth(true);
	musicOffButtonTex2.setSmooth(true);

	//constrols on button
	if (!controlsOnButtonTex1.loadFromFile("Material/Buttons/On_clicked.png") ||
		!controlsOnButtonTex2.loadFromFile("Material/Buttons/On.png"))
		std::cout << "Failed to load on button textures!\n";
	controlsOnButtonTex1.setSmooth(true);
	controlsOnButtonTex2.setSmooth(true);

	//controls off button
	if (!controlsOffButtonTex1.loadFromFile("Material/Buttons/Off.png") ||
		!controlsOffButtonTex2.loadFromFile("Material/Buttons/Off_clicked.png"))
		std::cout << "Failed to load off button textures!\n";
	controlsOffButtonTex1.setSmooth(true);
	controlsOffButtonTex2.setSmooth(true);

}

void SettingScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 510, 600 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void SettingScreen::initSaveButton()
{
	saveButton.setFont(font);
	saveButton.setPosition({ 810, 600 });
	saveButton.setOutlineThickness(2);
	saveButton.setBackgroundAnimation(&saveButtonTex);
}


void SettingScreen::initMusicButton()
{
	//khoi tao on button music
	
	musicOnButton.setFont(font);
	musicOnButton.setPosition({ 600, 320 });
	musicOnButton.setOutlineThickness(2);
	musicOnButton.setBackgroundAnimation(&musicOnButtonTex1);

	// khoi tao off button music
	
	musicOffButton.setFont(font);
	musicOffButton.setPosition({ 800, 320 });
	musicOffButton.setOutlineThickness(2);
	musicOffButton.setBackgroundAnimation(&musicOffButtonTex1);
}

void SettingScreen::initControlsButton()
{

	//khoi tao on button controls
	controlsOnButton.setFont(font);
	controlsOnButton.setPosition({ 600, 480 });
	controlsOnButton.setOutlineThickness(2);
	controlsOnButton.setBackgroundAnimation(&controlsOnButtonTex1);

	// khoi tao off button controls

	controlsOffButton.setFont(font);
	controlsOffButton.setPosition({ 800, 480 });
	controlsOffButton.setOutlineThickness(2);
	controlsOffButton.setBackgroundAnimation(&controlsOffButtonTex1);
}


void SettingScreen::stopAllSounds() {
	if (Button::getButtonSound().getStatus() == sf::Sound::Playing) {
		Button::getButtonSound().stop();
	}

	if (MainScreen::getIntroSound().getStatus() == sf::Sound::Playing) {
		MainScreen::getIntroSound().stop();
	}
}

void SettingScreen::toggleControls()
{
	useWASDControls = !useWASDControls;
}

void SettingScreen::toggleMusicState() {
	if (musicEnabled) {
		MainScreen::getIntroSound().play();
		Button::getButtonSound().play();
	}
	else {
		stopAllSounds();
	}
	musicEnabledMain = musicEnabled;
}


void SettingScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (backButton.isMouseOver(window))
		{
			currentScreen = ScreenState::MainScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if ((musicOnButton.isMouseOver(window)) /*&& (musicEnabled == false)*/)
		{
			musicOffButton.setBackgroundAnimation(&musicOffButtonTex1);
			musicOnButton.setBackgroundAnimation(&musicOnButtonTex1);
			musicEnabled = true;  // turn on button music
			toggleMusicState();
		}
		else if ((musicOffButton.isMouseOver(window)) /*&& (musicEnabled == true)*/)
		{
			musicOnButton.setBackgroundAnimation(&musicOnButtonTex2);
			musicOffButton.setBackgroundAnimation(&musicOffButtonTex2);
			musicEnabled = false;  // turn off button music 
			toggleMusicState();
		}
		else if ((controlsOnButton.isMouseOver(window))/* && (useWASDControls == false)*/)
		{
			controlsOnButton.setBackgroundAnimation(&controlsOnButtonTex1);
			controlsOffButton.setBackgroundAnimation(&controlsOffButtonTex1);
			useWASDControls = true;  // turn on button controls
		}
		else if ((controlsOffButton.isMouseOver(window))/* && (useWASDControls == true)*/)
		{
			controlsOnButton.setBackgroundAnimation(&controlsOnButtonTex2);
			controlsOffButton.setBackgroundAnimation(&controlsOffButtonTex2);
			useWASDControls = false;  // turn off button controls
		}
		else
		{
			currentScreen = ScreenState::MainScreen;
			endScreen = true;
			isEndScreen = endScreen;
			MainScreen::setMusicState(musicEnabledMain);
			Character::setControlsState(useWASDControls);
		}

	}
}


void SettingScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		backButton.update(window);
		saveButton.update(window);
		musicOnButton.update(window);
		musicOffButton.update(window);
		controlsOnButton.update(window);
		controlsOffButton.update(window);
	}
	else
	{

	}
}

void SettingScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen) 
	{
		window.draw(settingScreen);
		backButton.drawTo(window);
		saveButton.drawTo(window);
		window.draw(HeaderMusicText);
		window.draw(HeaderControlsText);
		musicOnButton.drawTo(window);
		musicOffButton.drawTo(window);
		controlsOnButton.drawTo(window);
		controlsOffButton.drawTo(window);
	}
}