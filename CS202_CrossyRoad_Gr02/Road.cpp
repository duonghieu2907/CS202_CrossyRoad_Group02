#pragma once
#include "Road.h"
#include <math.h>
Road::Road(float width, sf::Vector2f speed, sf::Texture* texture)
	:obstacle(width, speed, texture)
{
}

Road::~Road()
{
}

void Road::addCar(truck tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	car.push_back(tmp);
}

void Road::addLight(TrafficLight tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	light.push_back(tmp);
}

void Road::addItem(Item tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	item.push_back(tmp);
}

void Road::setPosition(sf::Vector2f pos)
{
	sf::Vector2f distance = pos - getShape().getPosition();
	obstacle::setPosition(pos);
	//std::cout << distance.x << " " << distance.y << "\n";
	for (int i = 0;i < car.size();i++) {
		car[i].getShape().move(distance);
	}
	for (int i = 0;i < light.size();i++) {
		light[i].getShape().move(distance);
	}

	for (int i = 0;i < item.size();i++) {
		item[i].getShape().move(distance);
	}
}

bool Road::isCollision(Character& player)
{

	for (int i = 0;i < car.size();i++) {
		//if (this->car[i].getShape().getGlobalBounds().intersects(player.getBounds())) {
		//	return true;
		//}
		if (abs(this->car[i].getShape().getPosition().x - player.getBody().getPosition().x) <= 40)
		{
			return true;
		}
	}
	return false;
}

void Road::isGetItem(Character& player)
{
	if (item.size() == 0) {
		return;
	}
	else {
		for (int i = 0;i < item.size();i++) {
			if (item[i].getShape().getGlobalBounds().intersects(player.getBounds())) {
				if (item[i].getType() == 1) {
					player.incPoint();
				}
				else if (item[i].getType() == 2) {
					player.incStamina(2);
				}
				else if (item[i].getType() == 3) {
					player.incStamina(3);
				}
				item.erase(item.begin() + i);
			}
		}
	}
}

void Road::printCarpos()
{
	for (int i = 0;i < car.size();i++) {
		std::cout << i << " " << car[i].getShape().getPosition().x << " " << car[i].getShape().getPosition().y << "\n";
	}
}

truck Road::getCar(int index)
{
	return car[index];
}

void Road::update()
{
	obstacle::update();
	obstacle::setPosition(getShape().getPosition() + getSpeed());
	for (int i = 0;i < car.size();i++) 
	{
		car[i].getShape().move(getSpeed());
		for (int j = 0; j < light.size();j++)
		{
			if (abs(car[i].getShape().getPosition().x - light[j].getShape().getPosition().x) < 70 && light[i].canGo() == 0
				&& (car[i].getRight() xor light[i].getRight()))
			{
				car[i].setState(0);
			}
			else if
				(abs(car[i].getShape().getPosition().x - light[j].getShape().getPosition().x) < 70 && light[i].canGo() == 1
					&& (car[i].getRight() xor light[i].getRight()))
			{
				car[i].setState(1);
			}
		}
		car[i].update(0.01f, car[i].getRight());
	}

	for (int i = 0;i < light.size();i++) {
		light[i].getShape().move(getSpeed());
		light[i].update();
	}

	for (int i = 0;i < item.size();i++) {
		item[i].getShape().move(getSpeed());
		item[i].update();
	}
}

void Road::reflect()
{
	for (int i = 0;i < car.size();i++) {
		car[i].refelect();
	}
	for (int i = 0; i < light.size(); i++)
	{
		light[i].reflect();
	}
}

void Road::drawTo(sf::RenderWindow& target)
{
	target.draw(getShape());
	//std::cout << car.size() << "\n";
	for (int i = 0;i < car.size();i++) {
		target.draw(car[i].getShape());
	}

	for (int i = 0;i < light.size();i++) {
		target.draw(light[i].getShape());
	}

	for (int i = 0;i < item.size();i++) {
		target.draw(item[i].getShape());
	}
}



