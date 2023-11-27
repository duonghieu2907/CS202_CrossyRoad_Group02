#pragma once

#include"obstacle.h"
#include"TrafficLight.h"
#include"truck.h"
#include<vector>

class Road : public obstacle
{
public:
	std::vector<TrafficLight> light;
	std::vector<truck> car;

public:
	Road(float width, sf::Vector2f speed, sf::Texture* texture);
	~Road();

	void addCar(truck tmp, sf::Vector2f pos);
	void addLight(TrafficLight tmp);
	void setPosition(sf::Vector2f pos) override;

	//
	void printCarpos();
	int getCarnum() {
		return car.size();
	}

	truck getCar(int index);

	void update() override;
	void drawTo(sf::RenderWindow& target) override;
};

