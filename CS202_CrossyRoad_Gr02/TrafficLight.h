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
	void setTextureRed(sf::Texture* t);
	void setTextureGreen(sf::Texture* t);
	bool getRight();
	bool canGo();
	void setPosition(sf::Vector2f cur);
	sf::RectangleShape& getShape();
	void reflect()
	{
		faceRight = !faceRight;
		sf::Vector2f distance;
		distance.y = 0;
		distance.x = abs(box.getPosition().x) + 1440;
	}
	void update();
	void drawTo(sf::RenderTarget& target);
};

