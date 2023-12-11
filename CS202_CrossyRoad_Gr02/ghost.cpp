#include "ghost.h"

void ghost::initText()
{
	sf::Texture* tmp1 = new sf::Texture();
	if (!tmp1->loadFromFile("Material/Animations/ghost flight.png")) {
		std::cout << "ERROR::LOADING ghost flight\n";
	}
	flight = tmp1;

	sf::Texture* tmp2 = new sf::Texture();
	if (!tmp2->loadFromFile("Material/Animations/ghost dead.png")) {
		std::cout << "ERROR::LOADING ghost dead\n";
	}
	death = tmp2;
}

ghost::ghost(sf::Vector2f sizeTruck, sf::Texture* truckPic, sf::Vector2u imgCount, float switchTime, float speed, bool Right)
:animation(truckPic, imgCount, switchTime)
{
	initText();

	//body.setPosition(sf::Vector2f(0, 0));
	this->body.setSize(sizeTruck);
	this->speed = speed;
	this->faceRight = Right;
	this->body.setOrigin(sizeTruck.x / 2, sizeTruck.y / 2);
	this->body.setTexture(truckPic);
	body.setPosition(sf::Vector2f(0, 0));
}

 void ghost::setTexture(sf::Texture* pic)
{
	body.setTexture(pic);
}

 void ghost::setPosition(sf::Vector2f pos)
 {
	 body.setPosition(pos);
 }

 bool  ghost::getRight()
 {
	 return faceRight;
 }
 sf::RectangleShape& ghost::getShape()
 {
	 return body;
 }
 void  ghost::setState(bool x)
 {
	 isGo = x;
 }// appear or not
 void  ghost::update(float deltaTime, bool faceRight, Character& player)
 {
	 int i = static_cast<unsigned>(rand() % 10000 + 1); // alter percentage see ghost at here

	 if (!isGo)
	 {
		 //std::cout << i << std::endl;
		 if (i == 1) { //  see a ghost
			 isGo = 1;
			 timing.restart();

		 }

	 }
	 if (isGo)
	 {
		 this->body.setTexture(flight);
		 float a = player.getPosition().x;
		 float b = player.getPosition().y;
		 if (timing.getElapsedTime().asSeconds() <= 2)
		 {
			 body.move((a - body.getPosition().x) * 0.001, (b - body.getPosition().y) * 0.001);
		 }
		 else body.move((a - body.getPosition().x) * speed, (b - body.getPosition().y) * speed);

		 if (timing.getElapsedTime().asSeconds() >= 8)
		 {
			 body.setTexture(death);
		 }
		 animation.update(row, deltaTime, faceRight);
		 body.setTextureRect(animation.uvRect);
		 if (timing.getElapsedTime().asSeconds() >= 10)
		 {
			 isGo = 0;
			 timing.restart();
		 }
	 }

	 if (isGo)
	 {
		 if (abs(body.getPosition().x - player.getPosition().x) <= body.getSize().x/3
			 && abs(body.getPosition().y - player.getPosition().y) <= body.getSize().y/3
			 && timing.getElapsedTime().asSeconds() < 8)
			 player.loadgetDamage();
	 }
 }
 void  ghost::drawTo(sf::RenderTarget& target)
 {
	 if (isGo)
		 target.draw(body);
 }