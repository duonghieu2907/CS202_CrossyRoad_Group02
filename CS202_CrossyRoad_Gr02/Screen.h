#ifndef SCREEN_H
#define SCREEN_H
#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include "Textbox.h"
#include "Button.h"
#include "Data.h"


enum class ScreenState {
    MainScreen, // 0
    LogInScreen, // 1
    SettingScreen, // 2
    GamePlayScreen, // 3
    InGameScreen // 4
};

// struct DataControl dataCtrl;

//ANY screen will be inheritance from this abstract base screen.
class Screen {
public:
    Screen() : isEndScreen(false) { dataCtrl.data = nullptr; }
    Screen(sf::RenderWindow& window);
    virtual ~Screen() { saveData(); }

    virtual void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) {}
    virtual void update(sf::RenderWindow& window) {}
    virtual void render(sf::RenderWindow& window) {}
    void setEndScreen(bool value) { isEndScreen = value; }

protected:
    virtual void initBackground(sf::RenderWindow& window) {}
    void initFont();

    void initData();
    void saveData();
protected: // my set to protected if need
    sf::Font font;
    bool isEndScreen;

    static DataControl dataCtrl;
};

class ScreenControl {
public:
    ScreenControl() {}
    ScreenControl(sf::RenderWindow& window);
    ~ScreenControl();

    Screen* getScreen(ScreenState state);

private:
    std::vector<Screen*> screens;
};

#endif