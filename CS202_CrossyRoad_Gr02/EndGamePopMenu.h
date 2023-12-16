#ifndef ENDGAMEPOPMENU_H
#define ENDGAMEPOPMENU_H
#pragma once
#include "PopMenu.h"

class EndGamePopMenu : public PopMenu {
public:
	EndGamePopMenu(sf::RenderWindow& window);
	EndGamePopMenu();
	~EndGamePopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;

	bool isMouseOverRestartButton(sf::RenderWindow& window);
	bool isMouseOverQuitButton(sf::RenderWindow& window);
private:
	void initTitle();
	void initRestartButton();
	void initQuitButton();

private:
	sf::Text title;

	sf::Texture restartButtonTex;
	ButtonCustom restartButton;

	sf::Texture quitButtonTex;
	ButtonCustom quitButton;
};

#endif