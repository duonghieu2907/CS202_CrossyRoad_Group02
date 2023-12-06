#ifndef INGAMESCREEN_H
#define INGAMESCREEN_H

#include "Screen.h"
#include "Character.h"
#include "obstacle.h"
#include "rain.h"

class InGameScreen : public Screen
{
public:
    sf::Text text;
    sf::Text playerHp;
    sf::Text playerStamina;
    sf::Text playerPoint;

    void initTex();
    void initText();
    void getRoadRan();

    InGameScreen(sf::RenderWindow& window);
    ~InGameScreen() {}
    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

    const bool isEndGame();
private:
    Character player;
    std::vector<obstacle*> listObstacle;
    float deltaTime = 0;
    sf::Clock clock;
    sf::Clock TimeDisplay;

    rain myRain;
    
    sf::Texture* car; // get the texture of car
    sf::Texture* road; // get the texture of road
    sf::Texture* cat;
    sf::Texture* chicken;
    sf::Texture* duck;
    sf::Texture* dog;
    sf::Texture* monkey;

    float addRoadTime; // time until adding new road
    float addRoadTimeMax; // maximum time to add new road

    sf::Texture* star;
};

#endif