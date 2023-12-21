#pragma once

#include"obstacle.h"
#include"TrafficLight.h"
#include"truck.h"
#include"Item.h"
#include"StaticObstacles.h"

#include<vector>

class Road : public obstacle
{
public:
	std::vector<TrafficLight> light;
	std::vector<truck> car;
	std::vector<Item> item;
	std::vector<StaticObstacles> obj;
	std::vector<Item> gift;

public:

	bool ghost = false;

	Road(float width, sf::Vector2f speed, sf::Texture* texture);
	~Road();

	void addCar(truck tmp, sf::Vector2f pos);
	void addLight(TrafficLight tmp, sf::Vector2f pos);
	void addItem(Item tmp, sf::Vector2f pos);
	void addObj(StaticObstacles tmp, sf::Vector2f pos);
	void addGift(Item tmp, sf::Vector2f pos);

	void setPosition(sf::Vector2f pos) override;
	bool isCollision(Character& player);
	void isGetItem(Character& player);
	void ObjCollision(Character& player);
	void GiftCollision(Character& player);

	bool isGhostCollision();
	//
	void printCarpos();
	int getCarnum() {
		return car.size();
	}
	void clear() override
	{
		car.clear();
		light.clear();
	}
	truck getCar(int index);
	void reflect();
	void update() override;
	void drawTo(sf::RenderWindow& target) override;
};

