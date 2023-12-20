#include "InfoPopMenu.h"

InfoPopMenu::InfoPopMenu(sf::RenderWindow& window) :
	PopMenu(window)
{
	initContainer(window);
}

InfoPopMenu::InfoPopMenu() :
	PopMenu()
{
}

InfoPopMenu::~InfoPopMenu()
{

}

void InfoPopMenu::initContainer(sf::RenderWindow& window)
{
	container.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x) / 3.2f,
			static_cast<float>(window.getSize().y) / 4.f
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

void InfoPopMenu::setTime()
{
	time.setFont(font);
	time.setCharacterSize(40);
	time.setFillColor(sf::Color::Black);
	int minutes = static_cast<int>(Screen::dataCtrl.data->getTime().asSeconds()) / 60;
	int seconds = static_cast<int>(Screen::dataCtrl.data->getTime().asSeconds()) % 60;
	time.setString("Highest score: " + std::to_string(minutes) + ":" + std::to_string(seconds));
	time.setPosition({ container.getPosition().x + container.getSize().x / 2.f - time.getGlobalBounds().width / 2, container.getPosition().y + 50.f});
}

void InfoPopMenu::setStar()
{
	star.setFont(font);
	star.setCharacterSize(40);
	star.setFillColor(sf::Color::Black);
	star.setString("Star: " + std::to_string(Screen::dataCtrl.data->getStar()));
	star.setPosition({ container.getPosition().x + container.getSize().x / 2.f - star.getGlobalBounds().width / 2, container.getPosition().y +  100.f});
}

void InfoPopMenu::update(sf::RenderWindow& window)
{

}

void InfoPopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(time);
	window.draw(star);
}
