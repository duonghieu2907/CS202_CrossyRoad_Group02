#include "PopMenu.h"

PopMenu::PopMenu(sf::RenderWindow& window)
{
	initFont();
	initBackground(window);
	initContainer(window);
}

PopMenu::PopMenu()
{

}

PopMenu::~PopMenu()
{

}

void PopMenu::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/HIEN KHANH 3.ttf"))
		std::cout << "Font not found!\n";
}

void PopMenu::initBackground(sf::RenderWindow& window)
{
	background.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)
		)
	);
	background.setFillColor(sf::Color(20, 20, 20, 100));
}

void PopMenu::initContainer(sf::RenderWindow& window)
{
	container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 1.5f,
			static_cast<float>(window.getSize().y) / 1.5f
		)
	);
	container.setFillColor(sf::Color::Yellow);
	container.setPosition(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 2.f - container.getSize().x / 2.f,
			static_cast<float>(window.getSize().y) / 2.f - container.getSize().y / 2.f
		)
	);
}

void PopMenu::update(sf::RenderWindow& window)
{

}

void PopMenu::render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(container);
}
