#include "TrafficLight.h"

void TrafficLight::initTexture()
{
	sf::Texture* tmp1 = new sf::Texture();
	if (!tmp1->loadFromFile("Material/Animations/Lane Object/dendo.png")) {
		std::cout << "ERROR::LOADING TRAFFIC LIGHT\n";
	}
	Red = tmp1;

	sf::Texture* tmp2 = new sf::Texture();
	if (!tmp2->loadFromFile("Material/Animations/Lane Object/denxanh.png")) {
		std::cout << "ERROR::LOADING TRAFFIC LIGHT\n";
	}
	Green = tmp2;
}

TrafficLight::TrafficLight(float timeRed, float timeGreen, bool right)
{
	initTexture();
	this->box.setPosition(0.f, 0.f);
	this->box.setSize(sf::Vector2f(60,60));
	this->timeRed = timeRed; // time for Red line
	this->timeGreen = timeGreen; // time for green line
	this->current = 0.f; // check the current time of the light
	this->state = true;  // this is Green light
	this->faceRight = right; // True is right
	this->box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);
}

TrafficLight::~TrafficLight()
{
	//delete Red and Green cause Bug?
}

bool TrafficLight::getRight()
{
	return this -> faceRight;
}

bool TrafficLight::canGo()
{
	if (state) {
		return true;
	}
	else {
		return false;
	}
}

void TrafficLight::setPosition(sf::Vector2f cur)
{
	box.setPosition(cur);
}

sf::RectangleShape& TrafficLight::getShape()
{
	return this->box;
}

void TrafficLight::update()
{
	if (state && current < timeGreen) {
		current += 0.05f;
	}
	else if (state && current >= timeGreen) {
		current = 0.f;
		state = false;
	}
	else if (!state && current < timeRed) {
		current += 0.05f;
	}
	else if (!state && current >= timeRed) {
		current = 0.f;
		state = true;
	}
	if (state) {
		box.setTexture(this->Green);
	}
	else {
		box.setTexture(this->Red);
	}
}

void TrafficLight::drawTo(sf::RenderTarget& target)
{
	target.draw(box);
}
