#include "PausePopMenu.h"

PausePopMenu::PausePopMenu(sf::RenderWindow& window) :
	PopMenu(window),
	resumeButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & resumeButtonTex),
	restartButton("", { 280, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & restartButtonTex),
	quitButton("", { 450, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & quitButtonTex)
{
	initTitle();
	initResumeButton();
	initRestartButton();
	initQuitButton();
}

PausePopMenu::PausePopMenu() :
	PopMenu(),
	resumeButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & resumeButtonTex),
	restartButton("", { 280, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & restartButtonTex),
	quitButton("", { 450, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & quitButtonTex)
{
	initTitle();
	initResumeButton();
	initRestartButton();
	initQuitButton();
}

PausePopMenu::~PausePopMenu()
{

}

void PausePopMenu::initTitle()
{
	title.setFont(font);
	title.setCharacterSize(80);
	title.setFillColor(sf::Color::Black);
	title.setString("> > PAUSED < <");
	title.setPosition({ 720.f - title.getGlobalBounds().width / 2.f, 405.f - title.getGlobalBounds().height * 4.5f });
}

void PausePopMenu::initResumeButton()
{
	if (!resumeButtonTex.loadFromFile("Material/Buttons/Resume.png"))
		std::cout << "Resume not found!\n";
	resumeButtonTex.setSmooth(true);

	resumeButton.setPosition({ 595, 350 });
	resumeButton.setOutlineThickness(2);
	resumeButton.setBackgroundAnimation(&resumeButtonTex);
}

void PausePopMenu::initRestartButton()
{
	if (!restartButtonTex.loadFromFile("Material/Buttons/Restart.png"))
		std::cout << "Restart not found!\n";
	restartButtonTex.setSmooth(true);

	restartButton.setPosition({ 580, 450 });
	restartButton.setOutlineThickness(2);
	restartButton.setBackgroundAnimation(&restartButtonTex);
}

void PausePopMenu::initQuitButton()
{
	if (!quitButtonTex.loadFromFile("Material/Buttons/Quit.png"))
		std::cout << "Quit not found!\n";
	quitButtonTex.setSmooth(true);

	quitButton.setPosition({ 505, 550 });
	quitButton.setOutlineThickness(2);
	quitButton.setBackgroundAnimation(&quitButtonTex);
}

bool PausePopMenu::isMouseOverResumeButton(sf::RenderWindow& window)
{
	return resumeButton.isMouseOver(window);
}

bool PausePopMenu::isMouseOverRestartButton(sf::RenderWindow& window)
{
	return restartButton.isMouseOver(window);
}

bool PausePopMenu::isMouseOverQuitButton(sf::RenderWindow& window)
{
	return quitButton.isMouseOver(window);
}

void PausePopMenu::update(sf::RenderWindow& window)
{
	resumeButton.update(window);
	restartButton.update(window);
	quitButton.update(window);
}

void PausePopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(title);
	resumeButton.drawTo(window);
	restartButton.drawTo(window);
	quitButton.drawTo(window);
}

