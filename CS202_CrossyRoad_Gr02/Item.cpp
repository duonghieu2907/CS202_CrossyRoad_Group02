#include "Item.h"

Item::Item(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime, int n)
	:animation(texture, imgCount, switchTime)
{
	this->type = n;
	this->shape.setSize(size);
	this->shape.setOrigin(size.x / 2, size.y / 2);
	this->shape.setTexture(texture);
}

Item::Item(sf::Vector2f size, sf::Texture* texture, sf::Vector2u imgCount, float switchTime, sf::Vector2f pos, int n)
	:animation(texture, imgCount, switchTime)
{
	this->type = n;
	this->shape.setSize(size);
	this->shape.setOrigin(size.x / 2, size.y / 2);
	this->shape.setTexture(texture);
	this->shape.setPosition(pos);
}

Item::~Item()
{

}


const sf::Vector2f Item::getPos()
{
	return shape.getPosition();
}

sf::RectangleShape& Item::getShape()
{
	return this->shape;
}

void Item::setPosition(sf::Vector2f pos)
{
	shape.setPosition(pos);
}

int Item::getType()
{
	return this->type;
}

void Item::update()
{
	animation.update(row, deltaTime, true);
	shape.setTextureRect(animation.uvRect);
}

void Item::drawTo(sf::RenderTarget& target)
{
	target.draw(shape);
}




