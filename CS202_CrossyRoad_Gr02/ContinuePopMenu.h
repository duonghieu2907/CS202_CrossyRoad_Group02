#ifndef CONTINUEPOPMENU_H
#define CONTINUEPOPMENU_H
#pragma once
#include <string>
#include "PopMenu.h"
#include "Screen.h"

class ContinuePopMenu : public PopMenu {
public:
	ContinuePopMenu(sf::RenderWindow& window);
	ContinuePopMenu();
	~ContinuePopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
private:
	void initBackground(sf::RenderWindow& window) override;
	void initContainer(sf::RenderWindow& window) override;
	void initInstruction();

private:
	sf::Text instruction;
};

#endif