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
		animation.update(0, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
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
	void setSpeed(float x);
	float getSpeed();
	int getPoint();

	void incHp(int n);
	static void setControlsState(bool controlsState);

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

	static bool controlsStateMain;

};
#endif