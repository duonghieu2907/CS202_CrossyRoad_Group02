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

void Road::upSpeed()
{
	obstacle::upSpeed();
	for (int i = 0; i < car.size(); i++)
	{
		car[i].upSpeed();
	}
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

void Road::addObj(StaticObstacles tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	obj.push_back(tmp);
}


void Road::addGift(Item tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	gift.push_back(tmp);
}

void Road::addBridge(sf::RectangleShape tmp, sf::Vector2f pos)
{
	tmp.setPosition(pos);
	bridge.push_back(tmp);
}

void Road::setPosition(sf::Vector2f pos)
{
	sf::Vector2f distance = pos - getShape().getPosition();
	obstacle::setPosition(pos);
	// Car
	for (int i = 0;i < car.size();i++) {
		car[i].getShape().move(distance);
	}
	// Traffic light
	for (int i = 0;i < light.size();i++) {
		light[i].getShape().move(distance);
	}
	// Item 
	for (int i = 0;i < item.size();i++) {
		item[i].getShape().move(distance);
	}
	// Static Obstacle
	for (int i = 0;i < obj.size();i++) {
		obj[i].getShape().move(distance);
	}

	// Gift
	for (int i = 0;i < gift.size();i++) {
		gift[i].getShape().move(distance);
	}

	// Bridge
	for (int i = 0;i < bridge.size();i++) {
		bridge[i].move(distance);
	}
}

bool Road::isCollision(Character& player)
{
	for (int i = 0;i < car.size();i++) {
		if (abs(this->car[i].getShape().getPosition().x - player.getBody().getPosition().x) <= car[i].getShape().getSize().x * 0.5)
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
			if (abs(player.getPosition().x - item[i].getPos().x) < 40.f && abs(player.getPosition().y - item[i].getPos().y) < 40.f) {
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

void Road::ObjCollision(Character& player)
{
	if (obj.size() == 0) {
		return;
	}
	else {
		for (int i = 0;i < obj.size();i++) {
			if (abs(player.getPosition().x - obj[i].getPos().x) < 50.f && abs(player.getPosition().y - obj[i].getPos().y) < 50.f) {
				if (player.getPosition().x >= obj[i].getPos().x) {
					player.setPosition(sf::Vector2f(player.getPosition().x + 2.f, player.getPosition().y));
				}
				if (player.getPosition().x <= obj[i].getPos().x) {
					player.setPosition(sf::Vector2f(player.getPosition().x - 2.f, player.getPosition().y));
				}
				if (player.getPosition().y >= obj[i].getPos().y) {
					player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y + 2.f));
				}
				if (player.getPosition().y <= obj[i].getPos().y) {
					player.setPosition(sf::Vector2f(player.getPosition().x, player.getPosition().y - 2.f));
				}
			}
		}
	}
}

void Road::GiftCollision(Character& player)
{
	if (gift.size() == 0) {
		return;
	}
	else {
		for (int i = 0;i < gift.size();i++) {
			if (abs(player.getPosition().x - gift[i].getPos().x) < 50.f && abs(player.getPosition().y - gift[i].getPos().y) < 50.f) {
				gift[i].render = 1;

				if (gift[i].getType() == 4) {
					player.incHp(1);
					player.incStamina(2);
				}
				else if (gift[i].getType() == 5) {
					player.incHp(2);
					player.incStamina(3);
				}
				else if (gift[i].getType() == 6) { // the ghost here
					ghost = 1;
				}
			}
		}
	}
}

void Road::RiverCollision(Character& player)
{
	if (bridge.size() == 0) {
		return;
	}
	else {
		for (int i = 0;i < bridge.size();i++) {
			sf::FloatRect curBridge = bridge[i].getGlobalBounds();
			sf::FloatRect curPlayer = player.getBounds();
			if ((curPlayer.left - curBridge.left) < -50.f && 
				(curPlayer.top - curBridge.top) > 0.f &&
				(curPlayer.top - curBridge.top - 110.f) < 0.f) {
				player.setPosition(bridge[i].getPosition());
				player.getDamage();
				player.loadgetDamage();
			} else if ((curPlayer.left - curBridge.left - curBridge.width) > -45.f &&
				(curPlayer.top - curBridge.top) > 0.f &&
				(curPlayer.top - curBridge.top - 110.f) < 0.f) {
				player.setPosition(bridge[i].getPosition());
				player.getDamage();
				player.loadgetDamage();
			}
		}
	}
}

bool Road::isGhostCollision()
{
	return ghost;
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
		if (i == 0)
		{
			car[i].getShape().move(getSpeed());
			for (int j = 0; j < light.size();j++)
			{
				if (abs(car[i].getShape().getPosition().x - light[j].getShape().getPosition().x) < car[i].getShape().getSize().x * 0.7 && light[i].canGo() == 0
					&& (car[i].getRight() xor light[i].getRight()))
				{
					car[i].setState(0);
				}
				else if
					(abs(car[i].getShape().getPosition().x - light[j].getShape().getPosition().x) < car[i].getShape().getSize().x * 0.7 && light[i].canGo() == 1
						&& (car[i].getRight() xor light[i].getRight()))
				{
					car[i].setState(1);
				}
			}
			car[i].update(0.01f, car[i].getRight());
		}
		else
		{
			car[i].getShape().move(getSpeed());
			if (car[0].getState() == 0) car[i].setState(0);
			else if (car[0].getState() == 1) car[i].setState(1);
			car[i].update(0.01f, car[i].getRight());
			//if(car[i - 1])
		}
	}

	for (int i = 0;i < obj.size();i++) {	
		obj[i].getShape().move(getSpeed());
		obj[i].update();
	}

	for (int i = 0;i < light.size();i++) {
		light[i].getShape().move(getSpeed());
		light[i].update();
	}

	for (int i = 0;i < item.size();i++) {
		item[i].getShape().move(getSpeed());
		item[i].update();
	}

	for (int i = 0;i < gift.size();i++) {
		gift[i].getShape().move(getSpeed());
		if (gift[i].IsRender() == 1) {
			gift[i].changedeltaTime(0.001);
			gift[i].update();
		}
		else {
			gift[i].changedeltaTime(0);
			gift[i].update();
		}
	}

	for (int i = 0;i < bridge.size();i++) {
		bridge[i].move(getSpeed());
	}
}

void Road::beginUpdate()
{
	for (int i = 0;i < item.size();i++) {
		//item[i].getShape().move(getSpeed());
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

	for (int i = 0;i < gift.size();i++) {
		target.draw(gift[i].getShape());
		if (gift[i].IsRender()) {
			if (gift[i].getTimeLoad() > 8960.f) {
				gift.erase(gift.begin() + i);
			}
			else {
				gift[i].increaseLoad(30.f);
			}
		}
	}

	for (int i = 0;i < item.size();i++) {
		target.draw(item[i].getShape());
	}

	for (int i = 0;i < car.size();i++) {
		target.draw(car[i].getShape());
	}

	for (int i = 0;i < light.size();i++) {
		target.draw(light[i].getShape());
	}

	for (int i = 0;i < obj.size();i++) {
		target.draw(obj[i].getShape());
	}

	for (int i = 0;i < obj.size();i++) {
		target.draw(obj[i].getShape());
	}

	for (int i = 0;i < bridge.size();i++) {
		target.draw(bridge[i]);
	}
}



