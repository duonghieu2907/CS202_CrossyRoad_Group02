#pragma once

#include"Animation.h"

class TrafficLight
{
private:
	sf::RectangleShape box;
	sf::Texture* Red;
	sf::Texture* Green;

	bool state;
	float current;
	float timeRed;
	float timeGreen;
	bool faceRight;
public:
	void initTexture();
	TrafficLight(float timeRed, float timeGreen, bool right);
	~TrafficLight();

	bool canGo();
	void setPosition(sf::Vector2f cur);
	sf::RectangleShape getShape();

	void update();
	void drawTo(sf::RenderTarget& target);
};

