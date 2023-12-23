#ifndef INFOPOPMENU_H
#define INFOPOPMENU_H
#pragma once
#include <string>
#include "PopMenu.h"
#include "Screen.h"

class InfoPopMenu : public PopMenu {
public:
	InfoPopMenu(sf::RenderWindow& window);
	InfoPopMenu();
	~InfoPopMenu();

	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;
	void setTime();
	void setStar();
private:
	void initContainer(sf::RenderWindow& window) override;

private:
	sf::Text time;

	sf::Text star;
};

#endif