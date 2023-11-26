#ifndef SETTINGSCREEN_H
#define SETTINGSCREEN_H

#include "Screen.h"

class SettingScreen : public Screen {
public:
    SettingScreen(sf::RenderWindow& window);
    ~SettingScreen() {}

public:
    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window);
    void initBackButton();
    void initSaveButton();

private:
    sf::Texture settingScreen1Tex;
    sf::Texture settingScreen2Tex;
    sf::Sprite settingScreen;

    sf::Texture saveButtonTex;
    ButtonCustom saveButton;

    sf::Texture backButtonTex;
    ButtonCustom backButton;

};

#endif