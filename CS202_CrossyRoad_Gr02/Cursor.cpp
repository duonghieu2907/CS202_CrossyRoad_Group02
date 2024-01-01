#include "Cursor.h"

Cursor::Cursor() {
    if (!cursorTex.loadFromFile("Material/Others/cursor.png")) 
    {
        std::cout << "Cursor not found!\n";
    }

    cursor.setTexture(cursorTex);
    cursor.setOrigin(cursorTex.getSize().x / 2, cursorTex.getSize().y / 2);
    cursor.setScale(0.5, 0.5);
}

void Cursor::update(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    cursor.setPosition(static_cast<sf::Vector2f>(mousePosition));
}

void Cursor::render(sf::RenderWindow& window) {
    if(visible) window.draw(cursor);
}

void Cursor::setCustomCursorVisible(sf::RenderWindow& window, bool visible) {
    if (visible) {
        window.setMouseCursorVisible(true);
    }
    else {
        window.setMouseCursorVisible(false);
    }
}

void Cursor::setCustomCursorScale(sf::RenderWindow& window, float scaleX, float scaleY) {
    cursor.setScale(scaleX, scaleY);
}

void Cursor::setVisible(bool v)
{
    visible = v;
}