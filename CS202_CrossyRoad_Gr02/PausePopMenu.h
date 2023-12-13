#ifndef PAUSEPOPMENU_H
#define PAUSEPOPMENU_H
#pragma once
#include "PopMenu.h"

class PausePopMenu : public PopMenu {
public:
	PausePopMenu(sf::RenderWindow& window);
	PausePopMenu();
	~PausePopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;

	bool isMouseOverResumeButton(sf::RenderWindow& window);
	bool isMouseOverRestartButton(sf::RenderWindow& window);
	bool isMouseOverQuitButton(sf::RenderWindow& window);
private:
	void initTitle();
	void initResumeButton();
	void initRestartButton();
	void initQuitButton();

private:
	sf::Text title;

	sf::Texture resumeButtonTex;
	ButtonCustom resumeButton;

	sf::Texture restartButtonTex;
	ButtonCustom restartButton;

	sf::Texture quitButtonTex;
	ButtonCustom quitButton;
};

#endif