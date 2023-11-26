#ifndef ANIMATION_H
#define ANIMATION_H
#include <iostream>
#include "SFML/Graphics.hpp"


class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imgCount, float switchTime);
	Animation();
	~Animation();

	void update(int row, float deltaTime, bool faceRight);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imgCount;
	sf::Vector2u imgCur;

	float totalTime;
	float switchTime;
};

#endif