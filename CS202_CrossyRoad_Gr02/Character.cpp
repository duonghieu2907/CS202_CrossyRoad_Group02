#include "Character.h"

Character::Character() : animation()
{}

Character::Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed) :
	animation(texture, imgCount, switchTime),
	speed(speed),
	row(0),
	faceRight(false)
{
	this->normal = texture;

	sf::Texture* t = new sf::Texture;
	if (!t->loadFromFile("Material/Animations/getDamage with Idle.png")) {
		std::cout << "ERROR can't not load player get damage\n";
	}
	this->getDamageTex = t;

	this->hpMax = 3;
	this->hp = this->hpMax;

	this->staminaMax = 10;
	this->stamina = this->staminaMax;

	this->invisibleMax = 300.f;
	this->invisible = this->invisibleMax;

	checkMove = 0;
	moveCounterMax = 10;
	moveCounter = 0;

	this->point = 0;

	body.setSize(sf::Vector2f(80.0f, 80.0f));
	body.setPosition(sf::Vector2f(200.0f, 200.0f));
	body.setTexture(this->normal);
	body.setOrigin(40.f, 40.f);
}

Character::Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed, sf::Vector2f pos) :
	animation(texture, imgCount, switchTime),
	speed(speed),
	row(0),
	faceRight(false)
{
	this->normal = texture;

	sf::Texture* t = new sf::Texture;
	if (!t->loadFromFile("Material/Animations/getDamage with Idle.png")) {
		std::cout << "ERROR can't not load player get damage\n";
	}
	this->getDamageTex = t;

	this->hpMax = 3;
	this->hp = this->hpMax;

	this->staminaMax = 10;
	this->stamina = this->staminaMax;

	this->invisibleMax = 300.f;
	this->invisible = this->invisibleMax;

	this->checkMove = 0;
	this->moveCounterMax = 1000;
	this->moveCounter = 0;
	
	this->point = 0;

	body.setSize(sf::Vector2f(80.0f, 80.0f));
	//body.setPosition(sf::Vector2f(200.0f, 200.0f));
	body.setTexture(this->normal);
	body.setOrigin(40.f, 40.f);
	body.setPosition(pos);
}

Character::~Character()
{

}

sf::Vector2f Character::getSize()
{
	return body.getSize();
}


void Character::update(float deltaTime, std::vector <obstacle*> listObstacle)
{
	//get which the Obstacle Player is inside
	obstacle* inside = 0;
	int index = -1;
	for (int i = 0; i < listObstacle.size(); i++)
	{
		if (listObstacle[i]->charIsInside(*this))
		{
			inside = listObstacle[i];
			index = i;
			break;
		}
	}
	//std::cout << index;
	sf::Vector2f movement(0.0f, 0.0f);
	bool moveToOther = 0;

	checkMove = 0;

	if (this->stamina > 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			movement.x -= speed * deltaTime * 2;
			checkMove = 1;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			movement.x += speed * deltaTime * 2;
			checkMove = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (inside)
			{
				if (body.getPosition().y - inside->getPosition().y > 34)
				{
					//std::cout << "Jump previous\n";
					if (index - 1 >= 0)
						body.setPosition(body.getPosition().x, listObstacle[index - 1]->getPosition().y + speed * deltaTime * 2 - 70);
				}
				else movement.y += speed * deltaTime * 2;
			}
			else
				movement.y += speed * deltaTime * 2;
			checkMove = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (inside)
			{
				if (inside->getPosition().y - body.getPosition().y > 34)
				{
					//std::cout << "Jump next\n";
					if (index + 1 < listObstacle.size() && body.getPosition().y >= 45)
					{
						body.setPosition(body.getPosition().x,
							listObstacle[index + 1]->getPosition().y - speed * deltaTime * 2 + 70);
						moveToOther = 1;
					}
					else  movement.y -= speed * deltaTime * 2;
				}
				else movement.y -= speed * deltaTime * 2;
			}
			else
				movement.y -= speed * deltaTime * 2;
			checkMove = 1;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (inside)
			{
				//std::cout << "MOVE BACK\n";
				if (body.getPosition().y - inside->getPosition().y > 34)
				{
					//std::cout << "Jump previous\n";
					if (index - 1 >= 0)
					{
						body.setPosition(body.getPosition().x, listObstacle[index - 1]->getPosition().y + speed * deltaTime * 2 - 70);
						moveToOther = 1;
					}
					else movement.y += speed * deltaTime * 2;
				}
				else movement.y += speed * deltaTime * 2;
			}
			else
				movement.y += speed * deltaTime * 2;
			checkMove = 1;
		}
	}

	if (!movement.x && !movement.y)
		row = 0;
	else if (movement.x) row = 1;
	else if (movement.y < 0) row = 3;
	else if (movement.y > 0)
	{
		row = 2;// std::cout << "MOVE BACK\n";
	}

	if (movement.x > 0.0f)
		faceRight = true;
	if (movement.y < 0)
		faceRight = false;
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	if (moveToOther == 0) {
		body.move(movement + listObstacle[0]->getSpeed());
	}
	if (body.getPosition().y - 40 >= 820) this->hp = 0; //dead
	if (body.getPosition().x + 40 >= 1440 || body.getPosition().x - 40 <= 0)
	{
		body.move(-movement - listObstacle[0]->getSpeed());
	}
	if (body.getPosition().y - 40 <= 0)
	{
		body.move(-movement - listObstacle[0]->getSpeed());
	}
}

void Character::drawTo(sf::RenderWindow& window)
{
	window.draw(body);
}

const sf::FloatRect& Character::getBounds()
{
	return body.getGlobalBounds();
}

void Character::setPosition(sf::Vector2f coor)
{
	body.setPosition(coor);
}

sf::Vector2f Character::getPosition()
{
	return body.getPosition();
}

sf::RectangleShape Character::getBody()
{
	return body;
}

void Character::getDamage()
{
	this->hp -= 1;
	if (this->hp <= 0) {
		this->hp = 0;
	}
}

int Character::getHp()
{
	return this->hp;
}

int Character::getHpMax()
{
	return this->hpMax;
}

void Character::loadgetDamage()
{
	if (this->invisible < this->invisibleMax) {
		this->invisible += 1.f;
	}
	else {
		getDamage();
		body.setTexture(this->getDamageTex);
		this->invisible = 0;
	}
}

void Character::settoNormal()
{
	if (this->invisible < this->invisibleMax) {
		this->invisible += 1.f;
	} else if (this->invisible == this->invisibleMax) {
		body.setTexture(this->normal);
	}
}

int Character::getStamina()
{
	return this->stamina;
}

int Character::getStaminaMax()
{
	return this->staminaMax;
}

void Character::reduceStamina()
{
	if (checkMove == 1) {
		moveCounter += 1;
		checkMove = 0;
	}

	if (moveCounter >= moveCounterMax) {
		stamina -= 1;
		moveCounter = 0;
	}
	if (stamina <= 0) {
		stamina = 0;
	}
}

void Character::incStamina(int n)
{
	if (n == 2) {
		this->stamina += 3;
	}
	else if (n == 3) {
		this->stamina += 5;
	}
	if (this->stamina >= this->staminaMax) {
		this->stamina = this->staminaMax;
	}
}

void Character::incPoint()
{
	this->point += 1;
}

int Character::getPoint()
{
	return this->point;
}

float Character::getSpeed()
{
	return speed;
}

void Character::setSpeed( float x)
{
	speed = x;
}


