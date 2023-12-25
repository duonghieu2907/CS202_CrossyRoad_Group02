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
	//sf::Clock timing;
	sf::Time start;
	sf::Time ended;
	bool end = false;
public:
	ghost(){};

	void initText();
	
	ghost(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right);
	
	void setTexture(sf::Texture* pic);
	void setPosition(sf::Vector2f pos);
	
	bool getRight();
	void setEnd(bool tmp);
	bool getEnd();
	
	sf::RectangleShape& getShape();
	
	void setState(bool x);// appear or not

	void update(float deltaTime, bool faceRight, Character& player, sf::Time time);
	
	void drawTo(sf::RenderTarget& target);
	
};