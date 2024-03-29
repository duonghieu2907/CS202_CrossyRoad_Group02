#include "ghost.h"

void ghost::initText()
{
	sf::Texture* tmp1 = new sf::Texture();
	if (!tmp1->loadFromFile("Material/Animations/Entity/ghost flight.png")) {
		std::cout << "ERROR::LOADING ghost flight\n";
	}
	flight = tmp1;

	sf::Texture* tmp2 = new sf::Texture();
	if (!tmp2->loadFromFile("Material/Animations/Entity/ghost dead.png")) {
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
 void ghost::setEnd(bool tmp)
 {
	 this->end = tmp;
 }
 bool ghost::getEnd()
 {
	 return this->end;
 }
 sf::RectangleShape& ghost::getShape()
 {
	 return body;
 }
 void  ghost::setState(bool x)
 {
	 isGo = x;
 }// appear or not
 void  ghost::update(float deltaTime, bool faceRight, Character& player, sf::Time time)
 {
	 int i = 1;

	 if (!isGo)
	 {
		 //std::cout << i << std::endl;
		 if (i == 1) { //  see a ghost
			 isGo = 1;
			 body.setPosition(75, 75);
			 start = time;
		 }

	 }
	 if (isGo)
	 {
		// body.setPosition(0, 0);
		 this->body.setTexture(flight);
		 float a = player.getPosition().x;
		 float b = player.getPosition().y;
		 ended = time;

		 if (ended.asSeconds() - start.asSeconds() <= 2)
		 {
			 body.move((a - body.getPosition().x) * 0.001, (b - body.getPosition().y) * 0.001);
		 }
		 else body.move((a - body.getPosition().x) * speed, (b - body.getPosition().y) * speed);

		 if (ended.asSeconds() - start.asSeconds() >= 8)
		 {
			 body.setTexture(death);
		 }
		 animation.update(row, deltaTime, faceRight);
		 body.setTextureRect(animation.uvRect);
		 if (ended.asSeconds() - start.asSeconds() >= 10)
		 {
			 end = true;
			 isGo = 0;
			 start = time;
		 }
	 }

	 if (isGo)
	 {
		 if (abs(body.getPosition().x - player.getPosition().x) <= body.getSize().x/3
			 && abs(body.getPosition().y - player.getPosition().y) <= body.getSize().y/3
			 && ended.asSeconds() - start.asSeconds() < 8)
			 player.loadgetDamage();
	 }
 }
 void  ghost::drawTo(sf::RenderTarget& target)
 {
	 if (isGo)
		 target.draw(body);
 }