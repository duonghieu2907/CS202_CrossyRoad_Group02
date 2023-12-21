#include "ContinuePopMenu.h"

ContinuePopMenu::ContinuePopMenu(sf::RenderWindow& window) :
	PopMenu(window)
{
	initBackground(window);
	initContainer(window);
	initInstruction();

}

ContinuePopMenu::ContinuePopMenu() :
	PopMenu()
{
}

ContinuePopMenu::~ContinuePopMenu()
{

}

void ContinuePopMenu::initBackground(sf::RenderWindow& window)
{
	background.setSize(
		sf::Vector2f(
			static_cast<float>(window.getSize().x),
			static_cast<float>(window.getSize().y)
		)
	);
	background.setFillColor(sf::Color(20, 20, 20, 50));
}

void ContinuePopMenu::initContainer(sf::RenderWindow& window)
{
	container.setFillColor(sf::Color::Transparent);
}

void ContinuePopMenu::initInstruction()
{
	instruction.setFont(font);
	instruction.setCharacterSize(80);
	instruction.setFillColor(sf::Color::White);
	instruction.setString("PRESS ANY KEY TO START");
	instruction.setPosition({ background.getSize().x / 2.f - instruction.getGlobalBounds().width / 2, background.getSize().y / 2.f - instruction.getGlobalBounds().height / 2 });
}

void ContinuePopMenu::update(sf::RenderWindow& window)
{

}

void ContinuePopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(instruction);
}
