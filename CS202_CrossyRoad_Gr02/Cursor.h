#ifndef CURSOR_H
#define CURSOR_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Cursor {
public:
    Cursor();

public:
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setCustomCursorVisible(sf::RenderWindow& window, bool visible);
    void setCustomCursorScale(sf::RenderWindow& window, float scaleX, float scaleY);
    void setVisible(bool v);

private:
    bool visible;
    sf::Sprite cursor;
    sf::Texture cursorTex;
};

#endif