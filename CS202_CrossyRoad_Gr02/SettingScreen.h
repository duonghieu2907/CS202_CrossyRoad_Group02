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
    void initMusicButton();
    void initControlsButton();
    void stopAllSounds();
    void toggleControls();
    void toggleMusicState();

private:
    sf::Texture settingScreen1Tex;
    sf::Texture settingScreen2Tex;
    sf::Sprite settingScreen;

    sf::Texture saveButtonTex;
    ButtonCustom saveButton;

    sf::Texture backButtonTex;
    ButtonCustom backButton;

    sf::Texture musicOnButtonTex1;
    sf::Texture musicOnButtonTex2;
    sf::Texture musicOffButtonTex1;
    sf::Texture musicOffButtonTex2;
    ButtonCustom musicOnButton;
    ButtonCustom musicOffButton;

    sf::Texture controlsOnButtonTex1;
    sf::Texture controlsOnButtonTex2;
    sf::Texture controlsOffButtonTex1;
    sf::Texture controlsOffButtonTex2;
    ButtonCustom controlsOnButton;
    ButtonCustom controlsOffButton;

    sf::Text HeaderMusicText;
    sf::Text HeaderControlsText;

    bool musicEnabled;
    bool musicEnabledMain;
    bool useWASDControls;

};

#endif