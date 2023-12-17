#pragma once
#include "main.h"
#include "Screen.h"

Application::Application() :
	videoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	screenCtrl(window),
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

	while (window.isOpen())
	{
		handleEvent();
		update();
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
			//curScreen = screenCtrl.getScreen(curScreenState);
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



void Application::update()
{
	curScreen->update(window);
	if (curScreen -> getRestart())
	{
		curScreen->setRestart(0);
		screenCtrl.pop();
		screenCtrl.addInGameScreen(window);
	}
}

void Application::render()
{
	curScreen->render(window);
	window.display();
}
