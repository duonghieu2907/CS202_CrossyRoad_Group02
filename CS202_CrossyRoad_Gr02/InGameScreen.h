#ifndef INGAMESCREEN_H
#define INGAMESCREEN_H

#include "Screen.h"
#include "Character.h"
#include "obstacle.h"

class InGameScreen : public Screen
{
public:
    InGameScreen(sf::RenderWindow& window);
    ~InGameScreen() {}
    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
private:
    Character player;
    std::vector<obstacle*> listObstacle;
    float deltaTime = 0;
    sf::Clock clock;
};

#endif