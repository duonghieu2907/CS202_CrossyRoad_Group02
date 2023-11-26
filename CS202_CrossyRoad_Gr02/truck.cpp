#include "truck.h"

truck::truck(float OBSwidth, sf::Vector2f OBSspeed, sf::Texture* OBStext, sf::Vector2f sizeTruck,
    sf::Texture *truckPic, sf::Vector2u imgCount, float switchTime, float speed):
    obstacle(OBSwidth, OBSspeed, OBStext), row(0), faceRight(true), carSpeed(speed), animation(truckPic, imgCount, switchTime)
{
    car.setSize(sizeTruck);
    car.setTexture(truckPic);
    car.setOrigin(sizeTruck.x / 2, sizeTruck.y / 2);
}

void truck::setPosition(sf::Vector2f pos )
{
    car.setPosition(pos);
}

