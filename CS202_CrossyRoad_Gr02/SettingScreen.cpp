#include "SettingScreen.h"

SettingScreen::SettingScreen(sf::RenderWindow& window) :
	Screen(window),
	backButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex),
	saveButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & saveButtonTex)
{
	initBackground(window);
	initBackButton();
	initSaveButton();
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

	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back.png"))
		std::cout << "Back not found!\n";
	backButtonTex.setSmooth(true);

	// Save button
	if (!saveButtonTex.loadFromFile("Material/Buttons/Save.png"))
		std::cout << "Save hover not found!\n";
	saveButtonTex.setSmooth(true);
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
		else
		{

		}
	}
}



void SettingScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		backButton.update(window);
		saveButton.update(window);
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
	}
}