#include "RemovePopMenu.h"

RemovePopMenu::RemovePopMenu(sf::RenderWindow& window) :
	PopMenu(window),
	confirmButton("", { 265, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & confirmButtonTex),
	cancelButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & cancelButtonTex)
{
	initTitle();
	initConfirmButton();
	initCancelButton();
}

RemovePopMenu::RemovePopMenu() :
	PopMenu(),
	confirmButton("", { 265, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & confirmButtonTex),
	cancelButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & cancelButtonTex)
{
	initTitle();
	initConfirmButton();
	initCancelButton();
}

RemovePopMenu::~RemovePopMenu()
{

}

void RemovePopMenu::initTitle()
{
	title.setFont(font);
	title.setCharacterSize(80);
	title.setFillColor(sf::Color::Black);
	title.setString("ARE YOU SURE?");
	title.setPosition({ 720.f - title.getGlobalBounds().width / 2.f, 405.f - title.getGlobalBounds().height * 2.5f});
}

void RemovePopMenu::initConfirmButton()
{
	if (!confirmButtonTex.loadFromFile("Material/Buttons/Confirm.png"))
		std::cout << "Confirm not found!\n";
	confirmButtonTex.setSmooth(true);

	confirmButton.setPosition({ 750, 500 });
	confirmButton.setOutlineThickness(2);
	confirmButton.setBackgroundAnimation(& confirmButtonTex);
}

void RemovePopMenu::initCancelButton()
{
	if (!cancelButtonTex.loadFromFile("Material/Buttons/Cancel.png"))
		std::cout << "Cancel not found!\n";
	cancelButtonTex.setSmooth(true);

	cancelButton.setPosition({ 420, 500 });
	cancelButton.setOutlineThickness(2);
	cancelButton.setBackgroundAnimation(& cancelButtonTex);
}

bool RemovePopMenu::isMouseOverConfirmButton(sf::RenderWindow& window)
{
	return confirmButton.isMouseOver(window);
}

bool RemovePopMenu::isMouseOverCancelButton(sf::RenderWindow& window)
{
	return cancelButton.isMouseOver(window);
}

void RemovePopMenu::update(sf::RenderWindow& window)
{
	confirmButton.update(window);
	cancelButton.update(window);
}

void RemovePopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(title);
	confirmButton.drawTo(window);
	cancelButton.drawTo(window);
}

