#ifndef CHARACTER_H
#define CHARACTER_H
#include"obstacle.h"
#include <iostream>
#include "Animation.h"
#include <vector>

class obstacle;
class Character {
public:

	Character();
	Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed);
	Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed, sf::Vector2f pos);
	~Character();

	sf::Vector2f getSize();
	void update(float deltaTime)
	{
		sf::Vector2f movement(0.0f, 0.0f);
		bool moveToOther = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			movement.x -= speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			movement.x += speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			movement.y -= speed * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			movement.y += speed * deltaTime;

		if (!movement.x && !movement.y)
			row = 1;
		else
		{
			row = 2;
			if (movement.x > 0.0f)
				faceRight = true;
			else
				faceRight = false;
		}

		animation.update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		if (moveToOther == 0) body.move(movement);
	}
	void update(float deltaTime, std::vector <obstacle*> listObstacle);
	void drawTo(sf::RenderWindow& window);
	const sf::FloatRect& getBounds();
	void setPosition(sf::Vector2f coor);
	sf::Vector2f getPosition();
	sf::RectangleShape getBody();

	void getDamage();
	int getHp();
	int getHpMax();
	void loadgetDamage();
	void settoNormal();
	
	int getStamina();
	int getStaminaMax();

	void reduceStamina();

	void incStamina(int n);
	void incPoint();

	int getPoint();
private:
	//sf::Texture texture;
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	int hp;
	int hpMax;

	float invisible; //this is for when the character get damage, he/she will be invisible for a short period of time 
	float invisibleMax; // the maximum period of time the character in invisible state

	sf::Texture* getDamageTex;
	sf::Texture* normal;

	int checkMove;
	int moveCounter;
	int moveCounterMax;

	int stamina;
	int staminaMax;

	unsigned point;
};
#endif