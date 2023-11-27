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

	void update(float deltaTime, bool faceRight);
	void drawTo(sf::RenderTarget& target);
private:
	sf::RectangleShape car;
	Animation animation;
	unsigned int row;
	float carSpeed;
	bool faceRight; // truck may go from left and right
};