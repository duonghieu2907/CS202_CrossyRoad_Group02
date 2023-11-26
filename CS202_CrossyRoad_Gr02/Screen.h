#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"


enum class ScreenState {
    MainScreen, // 0
    GamePlayScreen, // 1
    SettingScreen, // 2
    InGameScreen // 3
};

//ANY screen will be inheritance from this abstract base screen.
class Screen {
public:
    Screen(sf::RenderWindow& window) : isEndScreen(false) { initFont(); }
    ~Screen() {}

    virtual void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) {}
    virtual void update(sf::RenderWindow& window) {}
    virtual void render(sf::RenderWindow& window) {}
    void setEndScreen(bool value) { isEndScreen = value; }

protected:
    virtual void initBackground(sf::RenderWindow& window) {}
    void initFont();

protected: // my set to protected if need
    sf::Font font;
    bool isEndScreen;

};

class ScreenControl {
public:
    ScreenControl(sf::RenderWindow& window);
    ~ScreenControl();

    Screen* getScreen(ScreenState state);

private:
    std::vector<Screen*> screens;
};

#endif