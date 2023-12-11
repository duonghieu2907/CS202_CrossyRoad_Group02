#pragma once
#include"SFML/Graphics.hpp"
#include"Animation.h"

class truck
{
public:
	truck(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right);

	void setPosition(sf::Vector2f pos);// for the truck
	bool getRight();
	sf::RectangleShape& getShape();
	void setState(bool x);
	bool getState();
	void update(float deltaTime, bool faceRight);
	void drawTo(sf::RenderTarget& target);
private:
	sf::RectangleShape car;
	Animation animation;
	bool isGo = 1;
	unsigned int row = 0;
	float carSpeed;
	bool faceRight; // truck may go from left and right
};