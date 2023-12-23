#pragma once

#include "Animation.h"

class Item
{
private:
	sf::RectangleShape shape;
	Animation animation;

	unsigned int row = 0;
	float deltaTime = 0.0014f;

	// This is to check what type of Item is
	// 1. Star
	// 2. small Bottle
	// 3. big Bottle
	// Gift part
	// 4. banhmi
	// 5. comtam
	// 6. conma
	int type;

	float timeload = 0;
public:

	bool render = 0;

	Item(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime, int n);
	Item(sf::Vector2f size,sf::Texture* texture, sf::Vector2u imgCount, float switchTime,sf::Vector2f pos,int n);
	~Item();

	const sf::Vector2f getPos();
	sf::RectangleShape& getShape();
	void setPosition(sf::Vector2f pos);
	int getType();
	void setTexture(sf::Texture* tmp);
	void changedeltaTime(float n);
	bool IsRender();
	float getTimeLoad();
	void increaseLoad(float n);

	void update();
	void drawTo(sf::RenderTarget& target);

};

