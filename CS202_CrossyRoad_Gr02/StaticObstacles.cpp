#include "StaticObstacles.h"

StaticObstacles::StaticObstacles(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime)
	:animation(texture, imgCount, switchTime)
{
	this->shape.setSize(size);
	this->shape.setOrigin(size.x / 2, size.y / 2);
	this->shape.setTexture(texture);
}

StaticObstacles::StaticObstacles(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime, sf::Vector2f pos)
	:animation(texture, imgCount, switchTime)
{
	this->shape.setSize(size);
	this->shape.setOrigin(size.x / 2, size.y / 2);
	this->shape.setTexture(texture);
	this->shape.setPosition(pos);
}

StaticObstacles::~StaticObstacles()
{

}

const sf::Vector2f StaticObstacles::getPos()
{
	return this->shape.getPosition();
}

sf::RectangleShape& StaticObstacles::getShape()
{
	return this->shape;
}

void StaticObstacles::setPosition(sf::Vector2f pos)
{
	this->shape.setPosition(pos);
}

void StaticObstacles::update()
{
	animation.update(row, deltaTime, true);
	shape.setTextureRect(animation.uvRect);
}

void StaticObstacles::drawTo(sf::RenderTarget& target)
{
	target.draw(this->shape);
}





