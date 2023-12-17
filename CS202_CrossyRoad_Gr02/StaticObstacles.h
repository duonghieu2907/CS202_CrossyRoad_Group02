#pragma once

#include "Animation.h"

class StaticObstacles
{
private:
	sf::RectangleShape shape;
	Animation animation;

	unsigned int row = 0;
	float deltaTime = 0.f;
public:
	StaticObstacles(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime);
	StaticObstacles(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime, sf::Vector2f pos);
	~StaticObstacles();

	const sf::Vector2f getPos();
	sf::RectangleShape& getShape();
	void setPosition(sf::Vector2f pos);

	void update();
	void drawTo(sf::RenderTarget& target);
};

