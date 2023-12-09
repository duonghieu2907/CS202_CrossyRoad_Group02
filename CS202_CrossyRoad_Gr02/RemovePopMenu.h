#ifndef REMOVEPOPMENU_H
#define REMOVEPOPMENU_H
#pragma once
#include "PopMenu.h"

class RemovePopMenu : public PopMenu {
public:
	RemovePopMenu(sf::RenderWindow& window);
	RemovePopMenu();
	~RemovePopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;

	bool isMouseOverConfirmButton(sf::RenderWindow& window);
	bool isMouseOverCancelButton(sf::RenderWindow& window);
private:
	void initTitle();
	void initConfirmButton();
	void initCancelButton();

private:
	sf::Text title;

	sf::Texture confirmButtonTex;
	ButtonCustom confirmButton;

	sf::Texture cancelButtonTex;
	ButtonCustom cancelButton;
};

#endif