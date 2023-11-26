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
			row = 0;
		else if (!movement.x && movement.y > 0.f)
			row = 2;
		else if (!movement.x && movement.y < 0.f)
			row = 3;
		else
		{
			row = 1;
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
private:
	sf::Texture texture;
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};
#endif