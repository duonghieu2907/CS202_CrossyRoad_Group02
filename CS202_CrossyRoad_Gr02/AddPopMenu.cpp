#include "AddPopMenu.h"

AddPopMenu::AddPopMenu(sf::RenderWindow& window) :
	PopMenu(window),
	nameInput(80, sf::Color::Black, sf::Color::White, true),
	confirmButton("", { 265, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & confirmButtonTex),
	cancelButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & cancelButtonTex)
{
	initTitle();
	initNameInput();
	initConfirmButton();
	initCancelButton();
}

AddPopMenu::AddPopMenu() :
	PopMenu(),
	nameInput(50, sf::Color::Black, sf::Color::White, true),
	confirmButton("", { 265, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & confirmButtonTex),
	cancelButton("", { 250, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & cancelButtonTex)
{
	initTitle();
	initNameInput();
	initConfirmButton();
	initCancelButton();
}

AddPopMenu::~AddPopMenu()
{

}

void AddPopMenu::initTitle()
{
	title.setFont(font);
	title.setCharacterSize(80);
	title.setFillColor(sf::Color::Black);
	title.setString("ENTER YOUR NAME:");
	title.setPosition({ 720.f - title.getGlobalBounds().width / 2.f, 405.f - title.getGlobalBounds().height * 3.f });
}

void AddPopMenu::initNameInput()
{
	nameInput.setFont(font);
	nameInput.setBoxSize({ 500.f,80.f });
	nameInput.setLimit(true, 10);
	nameInput.setBoxPosition({ 468.f, 405.f });
	nameInput.setPosition({ 500.f, 390.f });
}

void AddPopMenu::initConfirmButton()
{
	if (!confirmButtonTex.loadFromFile("Material/Buttons/Confirm.png"))
		std::cout << "Confirm not found!\n";
	confirmButtonTex.setSmooth(true);

	confirmButton.setPosition({ 750, 550 });
	confirmButton.setOutlineThickness(2);
	confirmButton.setBackgroundAnimation(&confirmButtonTex);
}

void AddPopMenu::initCancelButton()
{
	if (!cancelButtonTex.loadFromFile("Material/Buttons/Cancel.png"))
		std::cout << "Cancel not found!\n";
	cancelButtonTex.setSmooth(true);

	cancelButton.setPosition({ 420, 550 });
	cancelButton.setOutlineThickness(2);
	cancelButton.setBackgroundAnimation(&cancelButtonTex);
}

void AddPopMenu::nameInputTypeOn(sf::Event event)
{
	nameInput.typedOn(event);
}

void AddPopMenu::nameInputSetSelected(sf::RenderWindow& window)
{
	if (nameInput.isMouseOver(window))
		nameInput.setSelected(true);
	else
		nameInput.setSelected(false);
}

std::string AddPopMenu::nameInputGetText()
{
	return nameInput.getText();
}

bool AddPopMenu::isMouseOverConfirmButton(sf::RenderWindow& window)
{
	return confirmButton.isMouseOver(window);
}

bool AddPopMenu::isMouseOverCancelButton(sf::RenderWindow& window)
{
	return cancelButton.isMouseOver(window);
}

void AddPopMenu::update(sf::RenderWindow& window)
{
	confirmButton.update(window);
	cancelButton.update(window);
}

void AddPopMenu::render(sf::RenderWindow& window)
{
	PopMenu::render(window);
	window.draw(title);
	nameInput.drawTo(window);
	confirmButton.drawTo(window);
	cancelButton.drawTo(window);
}

