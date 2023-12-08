#ifndef POPMENU_H
#define POPMENU_H
#pragma once

#include <cstdlib>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"

class PopMenu {
public:
	PopMenu(sf::RenderWindow& window);
	PopMenu();
	virtual ~PopMenu();

	virtual void update(sf::RenderWindow& window);
	virtual void render(sf::RenderWindow& window);

protected:
	sf::Font font;

private:
	void initFont();
	void initBackground(sf::RenderWindow& window);
	void initContainer(sf::RenderWindow& window);

private:
	sf::RectangleShape background;

	sf::Texture containerTex;
	sf::RectangleShape container;

};

#endif

