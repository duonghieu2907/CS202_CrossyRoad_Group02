#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "Screen.h"

class GamePlayScreen : public Screen {
public:
    GamePlayScreen(sf::RenderWindow& window);
    ~GamePlayScreen() {}

    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window) override;
    void initContinueButton();
    void initNewGameButton();
    void initBackButton();

private:
    sf::Texture gamePlayScreen1Tex;
    sf::Texture gamePlayScreen2Tex;
    sf::Sprite gamePlayScreen;

    sf::Texture continueButtonTex;
    ButtonCustom continueButton;

    sf::Texture newGameButtonTex;
    ButtonCustom newGameButton;

    sf::Texture backButtonTex;
    ButtonCustom backButton;
};


#endif