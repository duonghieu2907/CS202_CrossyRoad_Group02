#include "TrafficLight.h"

void TrafficLight::initTexture()
{
	sf::Texture* tmp1 = new sf::Texture();
	if (!tmp1->loadFromFile("")) {
		std::cout << "ERROR::LOADING TRAFFIC LIGHT\n";
	}
	this->Red = tmp1;

	sf::Texture* tmp2 = new sf::Texture();
	if (!tmp2->loadFromFile("")) {
		std::cout << "ERROR::LOADING TRAFFIC LIGHT\n";
	}
	this->Green = tmp2;
}

TrafficLight::TrafficLight(float timeRed, float timeGreen, bool right)
{
	initTexture();
	this->box.setPosition(0.f, 0.f);
	this->timeRed = timeRed; // time for Red line
	this->timeGreen = timeGreen; // time for green line
	this->current = 0.f; // check the current time of the light
	this->state = true;  // this is Green light
	this->faceRight = right; // True is right
	this->box.setOrigin(box.getSize().x / 2, box.getSize().y / 2);
}

TrafficLight::~TrafficLight()
{
	if (Red) {
		delete Red;
	}
	if (Green) {
		delete Green;
	}
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

sf::RectangleShape TrafficLight::getShape()
{
	return this->box;
}

void TrafficLight::update()
{
	if (state && current < timeGreen) {
		current += 1.f;
	}
	else if (state && current >= timeGreen) {
		current = 0.f;
		state = false;
	}
	else if (!state && current < timeRed) {
		current += 1.f;
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
