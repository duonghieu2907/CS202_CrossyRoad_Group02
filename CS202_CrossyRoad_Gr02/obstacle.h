#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Character.h"
#include "SFML/Graphics.hpp"

class Character;

class obstacle
{
public:
    obstacle();
    obstacle(float width, sf::Vector2f speed, sf::Texture* texture);

    float getWidth();
    bool charIsInside(Character player);
    virtual bool isCollision(Character& player) { return false; }
    virtual void isGetItem(Character& player) {}
    sf::Vector2f getPosition();
    virtual void setPosition(sf::Vector2f pos);
    void setSpeed(sf::Vector2f v);
    sf::Vector2f getSpeed();
    float distaceToPlayer(Character player); // Updated with Character parameter
    void setTexture(sf::Texture* t)
    {
        rec.setTexture(t);
    }
    virtual void drawTo(sf::RenderWindow& window);
    sf::RectangleShape getShape();
    virtual void update();

    virtual int getCarnum() { return 0; }
    virtual void printCarpos(){}
private:
    sf::RectangleShape rec;

    float width;
    sf::Texture* getPic;
    sf::Vector2f speed;
};
#endif