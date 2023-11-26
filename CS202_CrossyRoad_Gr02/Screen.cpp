#include "Screen.h"
#include "MainScreen.h"
#include "GamePlayScreen.h"
#include "SettingScreen.h"
#include "InGameScreen.h"

ScreenControl::ScreenControl(sf::RenderWindow& window)
{
	Screen* tmp;
	tmp = new MainScreen(window);
	screens.push_back(tmp);
	tmp = new GamePlayScreen(window);
	screens.push_back(tmp);
	tmp = new SettingScreen(window);
	screens.push_back(tmp);;
	tmp = new InGameScreen(window);
	screens.push_back(tmp);
}

ScreenControl::~ScreenControl()
{
	for (auto screen : screens) delete screen;
	screens.clear();
}

Screen* ScreenControl::getScreen(ScreenState state) 
{
	switch (state) {
	case ScreenState::MainScreen:
		return screens[0];
	case ScreenState::GamePlayScreen:
		return screens[1];
	case ScreenState::SettingScreen:
		return screens[2];
	case ScreenState::InGameScreen:
		return screens[3];
	}
}

// SCREEN

void Screen::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}