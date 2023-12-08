#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "Character.h"
#include <math.h>
class ghost
{
private:
	sf::RectangleShape body;
	Animation animation;
	bool isGo = 0;
	unsigned int row = 0;
	float speed;
	bool faceRight;
	sf::Texture* flight;
	sf::Texture* death;
	sf::Clock timing;
public:
	ghost()
	{};

	void initText();
	
	ghost(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right);
	
	void setTexture(sf::Texture* pic);
	void setPosition(sf::Vector2f pos);
	
	bool getRight();
	
	sf::RectangleShape& getShape();
	
	void setState(bool x);// appear or not

	void update(float deltaTime, bool faceRight, Character& player);
	
	void drawTo(sf::RenderTarget& target);
	
};