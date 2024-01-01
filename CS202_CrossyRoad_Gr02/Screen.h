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
    InstructionScreen, // 4
    InGameScreen // 5
};

// struct DataControl dataCtrl;

//ANY screen will be inheritance from this abstract base screen.
class Screen {
public:
    Screen() : isEndScreen(false), callRestartGame(false) { dataCtrl.data = nullptr; }
    Screen(sf::RenderWindow& window);
    virtual ~Screen() { saveData(); }
    bool getRestart()
    {
        return callRestartGame;
    }
    bool visibleCursor()
    {
        return !callDisVisibleCursor;
    }
    bool updateAccount()
    {
        return callUpdateAccount;
    }
    void setUpdateAccount(bool a)
    {
        callUpdateAccount = a;
    }
    void setRestart(bool  x)
    {
        callRestartGame = x;
    }
    virtual void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) {}
    virtual void update(sf::RenderWindow& window) {}
    virtual void render(sf::RenderWindow& window) {}
    void setEndScreen(bool value) { isEndScreen = value; }

    static DataControl dataCtrl;
protected:
    virtual void initBackground(sf::RenderWindow& window) {}
    void initFont();
    void initData();
    void saveData();
protected: // my set to protected if need
    sf::Font font;
    bool isEndScreen;

    bool callRestartGame;
    bool callDisVisibleCursor;
    bool callUpdateAccount;
};

class ScreenControl {
public:
    ScreenControl() {}
    ScreenControl(sf::RenderWindow& window);
    ~ScreenControl();
    void pop()
    {
        if (screens.size() > 0)
        screens.pop_back();
    }
    void addInGameScreen(sf::RenderWindow& window);
    
    Screen* getScreen(ScreenState state);

private:
    std::vector<Screen*> screens;
};

#endif