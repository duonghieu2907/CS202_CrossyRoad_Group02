#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imgCount, float switchTime) :
	imgCount(imgCount),
	switchTime(switchTime),
	totalTime(0)
{
	imgCur.x = 0;
	uvRect.width = texture->getSize().x / float(imgCount.x);
	uvRect.height = texture->getSize().y / float(imgCount.y);
}

Animation::Animation()
{}

Animation::~Animation()
{

}

void Animation::update(int row, float deltaTime, bool faceRight)
{
	imgCur.y = row;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		++imgCur.x;
		if (imgCur.x >= imgCount.x)
		{
			imgCur.x = 0;
		}
	}

	uvRect.top = imgCur.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = imgCur.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (imgCur.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}

}