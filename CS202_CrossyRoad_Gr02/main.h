#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Screen.h"
#include "Character.h"
#include "obstacle.h"

static const unsigned int SCREEN_HEIGHT = 810;
static const unsigned int SCREEN_WIDTH = 1440;

class Application {
public:
    Application();
    ~Application();
    void run();

public:
    void handleEvent();
    void update();
    void render();

private:
    void initWindow();

private:
    sf::VideoMode videoMode;
    sf::RenderWindow window;

    sf::Event event;

    ScreenState curScreenState;

    ScreenControl screenCtrl;
    Screen* curScreen;

};

#endif