#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Character.h"

class rain
{
private:
    //std::srand(std::time(nullptr));

    // Create a vector to store raindrop positions
    std::vector<sf::Vector2f> raindrops;
    // Create a rectangle shape for raindrops
    sf::RectangleShape raindropShape;
    //raindropShape.setRotation(30);
    bool state = 0;
    sf::Time start;
    sf::Time end;

public:
    rain()
    {
        std::srand(std::time(nullptr));
        raindropShape.setSize(sf::Vector2f(4, 20));
        raindropShape.setRotation(30);
    }
    void setState(bool st)
    {
        state = st;
    }
    bool getState()
    {
        return state;
    }
    void update(sf::RenderWindow &window, Character& player, sf::Time time)
    {
        int i = static_cast<unsigned>(rand() % 1000 + 1); // alter percentage see rain at here
       // std::cout << i << std::endl;
        if (!state)
        {
            //std::cout << i << std::endl;
            if (i == 1) { //  see a ghost
                state = 1;
                player.setSpeed(player.getSpeed() * 2 / 3);
                start = time;

            }
        }
        if(state)
        {
            end = time;
            if (rand() % 100 < 10) {
                // std::cout << "OK\n";
                float x = static_cast<float>(rand() % (window.getSize().x + 200));
                sf::Color randomColor(

                    73, 73, 163
                );
                raindropShape.setFillColor(randomColor);
                raindrops.push_back(sf::Vector2f(x, 0));
            }
            if (end.asSeconds() - start.asSeconds() >= 10)
            {
                state = 0;
                player.setSpeed(player.getSpeed() * 1.5);
                start = time;
            }
        }

    }
    void drawTo(sf::RenderWindow& window)
    {
    //std:: cout << raindrops.size()  << std::endl;
        for (auto& raindrop : raindrops) {
            raindrop.x -= 4;
            raindrop.y += 10; // Adjust the speed of raindrops

            raindropShape.setPosition(raindrop);

            window.draw(raindropShape);
        }

        // Remove raindrops that are out of the window
        raindrops.erase(
            std::remove_if(
                raindrops.begin(),
                raindrops.end(),
                [&window](const sf::Vector2f& pos) {
                    return pos.y > window.getSize().y;
                }),
            raindrops.end());
    }
};