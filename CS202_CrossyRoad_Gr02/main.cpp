#pragma once
#include "main.h"
#include "Screen.h"

Application::Application() :
	videoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	screenCtrl(window),
	customCursor(),
	curScreenState(ScreenState::MainScreen)
{
	initWindow();
	// Load loading screen background from file
	if (!loadingScreenTex.loadFromFile("Material/Backgrounds/LoadingScreen.png"))
		std::cout << "LoadingScreen not found!\n";
	loadingScreenTex.setSmooth(true);
	loadingScreen.setTexture(loadingScreenTex);
	float scaleX = static_cast<float>(window.getSize().x) / loadingScreenTex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / loadingScreenTex.getSize().y;
	loadingScreen.setScale(scaleX, scaleY);
}

Application::~Application()
{
	
}

void Application::initWindow()
{
	sf::Vector2i centerWindow(
		(sf::VideoMode::getDesktopMode().width / 2) - 600,
		(sf::VideoMode::getDesktopMode().height / 2) - 450
	);
	window.setPosition(centerWindow);
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(120);
}

void Application::run()
{
	window.draw(loadingScreen);
	window.display();

	// hide cursor 
	window.setMouseCursorVisible(false);



	while (window.isOpen())
	{
		handleEvent();
		update();
		updateCursor();
		render();
	}
}

void Application::handleEvent()
{
	curScreen = screenCtrl.getScreen(curScreenState);
	//Event Loop:
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		else
		{
			bool endScreen = false;
			curScreen->setEndScreen(endScreen);
			curScreen->handleEvent(event, window, curScreenState, endScreen);
			if (endScreen) 
			{
				curScreen = screenCtrl.getScreen(curScreenState);
				curScreen->setEndScreen(false);
			}
		}
	}
}

void Application::updateCursor()
{
	customCursor.update(window);
	customCursor.setCustomCursorVisible(window,false); 
	customCursor.setCustomCursorScale(window,0.3f, 0.3f);
}



void Application::update()
{
	curScreen->update(window);
	if (curScreen -> getRestart())
	{
		Data* tmp = curScreen->dataCtrl.data;
		curScreen->setRestart(0);
		screenCtrl.pop();
		screenCtrl.addInGameScreen(window);
		curScreen = screenCtrl.getScreen(ScreenState::InGameScreen);
		curScreen->dataCtrl.data = tmp;
	}
	if (!curScreen->visibleCursor())
	{
		customCursor.setVisible(0);
	}
	else customCursor.setVisible(1);

	if (screenCtrl.getScreen(ScreenState::GamePlayScreen)->updateAccount())
	{
		curScreen->setUpdateAccount(0);
		screenCtrl.getScreen(ScreenState::LogInScreen)->setUpdateAccount(1);
		screenCtrl.getScreen(ScreenState::GamePlayScreen)->setUpdateAccount(0);
	}
}

void Application::render()
{
	curScreen->render(window);
	customCursor.render(window);
	window.display();
}


