#pragma once

#include"obstacle.h"
#include"TrafficLight.h"
#include"truck.h"
#include "Item.h"
#include<vector>

class Road : public obstacle
{
public:
	std::vector<TrafficLight> light;
	std::vector<truck> car;
	std::vector<Item> item;

public:
	Road(float width, sf::Vector2f speed, sf::Texture* texture);
	~Road();

	void addCar(truck tmp, sf::Vector2f pos);
	void addLight(TrafficLight tmp, sf::Vector2f pos);
	void addItem(Item tmp, sf::Vector2f pos);

	void setPosition(sf::Vector2f pos) override;
	bool isCollision(Character& player);
	void isGetItem(Character& player);
	//
	void printCarpos();
	int getCarnum() {
		return car.size();
	}

	truck getCar(int index);

	void update() override;
	void drawTo(sf::RenderWindow& target) override;
};

