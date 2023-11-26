#ifndef MAINSCREEN_H
#define MAINSCREEN_H

#include "Screen.h"

class MainScreen : public Screen {
public:
    MainScreen(sf::RenderWindow& window);
    ~MainScreen() {}

    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window) override;
    void initPlayButton();
    void initInstructionButton();
    void initSettingButton();
    void initExitButton();

private:
    sf::Texture mainScreen1Tex;
    sf::Texture mainScreen2Tex;
    sf::Sprite mainScreen;

    sf::Texture playButtonTex;
    ButtonCustom playButton;

    sf::Texture intButtonTex;
    ButtonCustom instructionButton;

    sf::Texture settingButtonTex;
    ButtonCustom settingButton;

    sf::Texture exitButtonTex;
    ButtonCustom exitButton;
};


#endif