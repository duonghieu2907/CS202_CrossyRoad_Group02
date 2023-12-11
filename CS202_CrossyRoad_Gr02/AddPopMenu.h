#ifndef ADDPOPMENU_H
#define ADDPOPMENU_H
#pragma once
#include "PopMenu.h"
#include "Textbox.h"

class AddPopMenu : public PopMenu {
public:
	AddPopMenu(sf::RenderWindow& window);
	AddPopMenu();
	~AddPopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;

	void nameInputTypeOn(sf::Event event);
	void nameInputSetSelected(sf::RenderWindow& window);
	std::string nameInputGetText();

	bool isMouseOverConfirmButton(sf::RenderWindow& window);
	bool isMouseOverCancelButton(sf::RenderWindow& window);
private:
	void initTitle();
	void initNameInput();
	void initConfirmButton();
	void initCancelButton();

private:
	sf::Text title;
	Textbox nameInput;

	sf::Texture confirmButtonTex;
	ButtonCustom confirmButton;

	sf::Texture cancelButtonTex;
	ButtonCustom cancelButton;
};

#endif