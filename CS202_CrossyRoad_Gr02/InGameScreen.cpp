#include "InGameScreen.h"
#include "Road.h"

InGameScreen::InGameScreen(sf::RenderWindow& window) :
	Screen(window)
{
	sf::Texture* t = new sf::Texture;
	if (!(t->loadFromFile("Material/Animations/road.jpg")))
	{
		std::cout << "Can not load road! \n";
	}

	sf::Texture* honda = new sf::Texture;
	if (!(honda->loadFromFile("Material/Animations/Honda.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	for (int i = 0; i < 10; i++)
	{
		Road* tmp = new Road(162.0f, sf::Vector2f(0, 1.f), t);

		truck tmp1(sf::Vector2f(100.f, 100.f), honda, sf::Vector2u(10, 1), 0.1f, 1.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720, tmp->getPosition().y));
		//std::cout << tmp->car.size() << "\n";
		listObstacle.push_back(tmp);
	}

	float dis = 0;
	for (int i = 0; i < listObstacle.size(); i++)
	{
		listObstacle[i]->setPosition(sf::Vector2f(720, -15 - dis));
		dis += 162;
	}
	t = new sf::Texture;
	if (!t->loadFromFile("Material/Animations/Cat.png"))
		std::cout << "Cat Animation not found!\n";
	Character cat(t, sf::Vector2u(8, 5), 0.1f, 100.0f, listObstacle[0]->getPosition());
	player = cat;

}

void InGameScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
}

void InGameScreen::update(sf::RenderWindow& window)
{
	deltaTime = clock.restart().asSeconds();
	for (int i = 0; i < listObstacle.size();i++)
	{
		listObstacle[i]->update();
	}
	player.update(deltaTime, listObstacle);
}

void InGameScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.clear();

		for (int i = 0; i < listObstacle.size(); i++)
		{
			listObstacle[i]->drawTo(window);
		}
		player.drawTo(window);
	}

}
