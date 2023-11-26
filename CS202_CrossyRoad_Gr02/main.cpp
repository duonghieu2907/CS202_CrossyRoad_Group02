#pragma once
#include "main.h"


Application::Application() :
	videoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	screenCtrl(window),
	curScreenState(ScreenState::MainScreen)
{
	initWindow();
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
}

void Application::run()
{
	//window.draw(loadingScreen);
	//window.display();
	while (window.isOpen())
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			searchBar.setSelected(true);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			searchBar.setSelected(false);*/

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
			if (endScreen) {
				curScreen = screenCtrl.getScreen(curScreenState);
				curScreen->setEndScreen(false);
			}
		}
	}
}



void Application::update()
{
	curScreen->update(window);
}

void Application::render()
{
	curScreen->render(window);
	window.display();
}
