#pragma once
#include"SFML/Graphics.hpp"
#include"Animation.h"
#include<math.h>

class truck
{
public:
	truck(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right);

	void setPosition(sf::Vector2f pos);// for the truck
	bool getRight();
	sf::RectangleShape& getShape();
	void setState(bool x);
	bool getState();
	void upSpeed();
	void update(float deltaTime, bool faceRight);
	void refelect()
	{
		faceRight = !faceRight;
		sf::Vector2f distance;
		distance.y = 0;
		distance.x = abs(car.getPosition().x) + 1440;
		car.move(distance);

	}
	void drawTo(sf::RenderTarget& target);
private:
	sf::RectangleShape car;
	Animation animation;
	bool isGo = 1;
	unsigned int row = 0;
	float carSpeed;
	bool faceRight; // truck may go from left and right
};