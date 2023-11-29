#include "truck.h"

truck::truck(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right)
	:animation(truckPic, imgCount, switchTime)
{
	this->car.setSize(sizeTruck);
	this->carSpeed = speed;
	this->faceRight = Right;
	this->car.setOrigin(sizeTruck.x / 2, sizeTruck.y / 2);
	this->car.setTexture(truckPic);
}

void truck::setPosition(sf::Vector2f pos)
{
	this->car.setPosition(pos);
}

bool truck::getRight()
{
	return faceRight;
}

sf::RectangleShape& truck::getShape()
{
	return this->car;
}
void truck::setState(bool x)
{
	isGo = x;
}
void truck::update(float deltaTime, bool faceRight)
{
	animation.update(row, deltaTime, faceRight);
	car.setTextureRect(animation.uvRect);
	if (isGo)
	{
		if (faceRight) {
			car.move(this->carSpeed * deltaTime, 0);
		}
		else {
			car.move(-(this->carSpeed * deltaTime), 0);
		}
	}
}

void truck::drawTo(sf::RenderTarget& target)
{
	target.draw(this->car);
}
