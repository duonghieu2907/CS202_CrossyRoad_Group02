#pragma once
#include "truck.h"
#include "Character.h"
#include "obstacle.h"
class truck: public obstacle
{
public:
	truck(float OBSwidth, sf::Vector2f OBSspeed, sf::Texture *OBStext, sf::Vector2f sizeTruck, sf::Texture* truckPic,
		sf::Vector2u imgCount, float switchTime, float speed);
	void setPosition(sf::Vector2f pos);// for the truck
//	bool isCollision(Character player) override;
private:
	sf::RectangleShape car;
	Animation animation;
	unsigned int row;
	float carSpeed;
	bool faceRight; // truck may go from left and right
};