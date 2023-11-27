#include "Road.h"

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

void Road::addLight(TrafficLight tmp)
{
	light.push_back(tmp);
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
	obstacle::setPosition(getShape().getPosition() + getSpeed());

	for (int i = 0;i < car.size();i++) {
		car[i].getShape().move(getSpeed());
		car[i].update(0.1f, car[i].getRight());
	}

	for (int i = 0;i < light.size();i++) {
		light[i].update();
		light[i].getShape().move(getSpeed());
	}
}

void Road::drawTo(sf::RenderWindow& target)
{
	target.draw(getShape());
	std::cout << car.size() << "\n";
	for (int i = 0;i < car.size();i++) {
		car[i].drawTo(target);
		//std::cout << i << "\n" << car[i].getShape().getPosition().x << " " << car[i].getShape().getPosition().y << "\n";
	}

	for (int i = 0;i < light.size();i++) {
		target.draw(light[i].getShape());
	}
}



