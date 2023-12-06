#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include "Screen.h"
#include "Button.h"

class LogInScreen : public Screen {
public:
    LogInScreen(sf::RenderWindow& window);
    ~LogInScreen() {}

    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window) override;
    void initNewButton();
    void initBackButton();
    void initLeftButton();
    void initRightButton();
    void initCheckOver5();
    void initAccount();

    void switchAccUI();

private:
    sf::Texture logInScreenTex;
    sf::Sprite logInScreen;

    sf::Texture newButtonTex;
    ButtonCustom newButton;

    sf::Texture backButtonTex;
    ButtonCustom backButton;

    sf::Texture leftButtonTex;
    ButtonCustom leftButton;

    sf::Texture rightButtonTex;
    ButtonCustom rightButton;

    bool over5Acc;
    bool left;

    sf::Texture accountTex;
    std::vector<AccountButton*> accounts;
};


#endif