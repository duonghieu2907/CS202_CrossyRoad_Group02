#include "EndGamePopMenu.h"

EndGamePopMenu::EndGamePopMenu(sf::RenderWindow& window) :
	PopMenu(window),
	restartButton("", { 280, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & restartButtonTex),
	quitButton("", { 450, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & quitButtonTex)
{
	initTitle();
	initRestartButton();
	initQuitButton();
}

EndGamePopMenu::EndGamePopMenu() :
	PopMenu(),
	restartButton("", { 280, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & restartButtonTex),
	quitButton("", { 450, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & quitButtonTex)
{
	initTitle();
	initRestartButton();
	initQuitButton();
}

EndGamePopMenu::~EndGamePopMenu()
{

}

void EndGamePopMenu::initTitle()
{
	title.setFont(font);
	title.setCharacterSize(80);
	title.setFillColor(sf::Color::Black);
	title.setString("> > PAUSED < <");
	title.setPosition({ 720.f - title.getGlobalBounds().width / 2.f, 405.f - title.getGlobalBounds().height * 4.5f });
}

void EndGamePopMenu::initRestartButton()
{
	if (!restartButtonTex.loadFromFile("Material/Buttons/Restart.png"))
		std::cout << "Restart not found!\n";
	restartButtonTex.setSmooth(true);

	restartButton.setPosition({ 580, 450 });
	restartButton.setOutlineThickness(2);
	restartButton.setBackgroundAnimation(&restartButtonTex);
}

void EndGamePopMenu::initQuitButton()
{
	if (!quitButtonTex.loadFromFile("Material/Buttons/Quit.png"))
		std::cout << "Quit not found!\n";
	quitButtonTex.setSmooth(true);

	quitButton.setPosition({ 505, 550 });
	quitButton.setOutlineThickness(2);
	quitButton.setBackgroundAnimation(&quitButtonTex);
}

bool EndGamePopMenu::isMouseOverRestartButton(sf::RenderWindow& window)
{
	return restartButton.isMouseOver(window);
}

bool EndGamePopMenu::isMouseOverQuitButton(sf::RenderWindow& window)
{
	return quitButton.isMouseOver(window);
}

void EndGamePopMenu::update(sf::RenderWindow& window)
{
	restartButton.update(window);
	quitButton.update(window);
}

void EndGamePopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(title);
	restartButton.drawTo(window);
	quitButton.drawTo(window);
}

