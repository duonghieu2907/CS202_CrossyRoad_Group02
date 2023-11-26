#ifndef DATA_H
#define DATA_H
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Data {
public:
	Data(sf::RenderWindow& window);
	Data() {}
	~Data() {}

	void setFont() {}
	virtual void setBackground() {}
	virtual void setText() {}
	
	virtual void update(sf::RenderWindow& window) {}
	virtual void drawTo(sf::RenderWindow& window) {}

private:
	sf::Text text;
	sf::RectangleShape background;

};

#endif