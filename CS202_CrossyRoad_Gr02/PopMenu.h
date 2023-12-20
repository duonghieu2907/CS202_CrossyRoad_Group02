#ifndef POPMENU_H
#define POPMENU_H
#pragma once

#include <cstdlib>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
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
	virtual void initContainer(sf::RenderWindow& window);
	sf::Texture containerTex;
	sf::RectangleShape container;

private:
	void initFont();
	void initBackground(sf::RenderWindow& window);

private:
	sf::RectangleShape background;


};

#endif

