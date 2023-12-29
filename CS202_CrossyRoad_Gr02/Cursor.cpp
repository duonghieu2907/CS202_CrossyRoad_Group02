#include "Cursor.h"

Cursor::Cursor() {
    if (!cursorTex.loadFromFile("Material/Others/cursor.png")) 
    {
        std::cout << "Cursor not found!\n";
    }

    cursor.setTexture(cursorTex);
}

void Cursor::update(sf::RenderWindow& window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    cursor.setPosition(static_cast<sf::Vector2f>(mousePosition));
}

void Cursor::render(sf::RenderWindow& window) {
    window.draw(cursor);
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