#ifndef INGAMESCREEN_H
#define INGAMESCREEN_H

#include "Screen.h"
#include "GamePlayScreen.h"
#include "PausePopMenu.h"
#include "EndGamePopMenu.h"
#include "ContinuePopMenu.h"
#include "Character.h"
#include "obstacle.h"
#include "rain.h"
#include "ghost.h"

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
    sf::Time elapsed; //save time player have play
    sf::Time duration;

    rain myRain;


    ghost devil;
    	 
    sf::Texture* road; // get the texture of road

    sf::Texture* honda;
    sf::Texture* car;
    sf::Texture* xedo;
    sf::Texture* road1;

    sf::Texture* cat;
    sf::Texture* chicken;
    sf::Texture* duck;
    sf::Texture* dog;
    sf::Texture* monkey;

    float addRoadTime; // time until adding new road
    float addRoadTimeMax; // maximum time to add new road


    bool playing;
    bool started = 0;


    sf::Texture* star;
    sf::Texture* sugarcane;
    sf::Texture* xaxi;

    sf::Texture playerHpTex;
    sf::Sprite playerHpTexBox;

    sf::Texture playerStaminaTex;
    sf::Sprite playerStaminaTexBox;

    sf::Texture playerStarTex;
    sf::Sprite playerStarTexBox;

    sf::Texture* obs1;
    sf::Texture* obs2;
    sf::Texture* obs3;
    sf::Texture* obs4;
    sf::Texture* obs5;
    sf::Texture* obs6;
    sf::Texture* obs7;
    sf::Texture* obs8;

    sf::Vector2f ItemCoor;

    bool pause;
    PausePopMenu pauseMenu;

    EndGamePopMenu endMenu;

    sf::Texture* banhmi;
    sf::Texture* comtam;
    sf::Texture* ma;

    bool Ghost = false;
    float Ghostdie = 0;
    
    ContinuePopMenu continueMenu;

};

#endif