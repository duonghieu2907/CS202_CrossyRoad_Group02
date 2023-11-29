#include "InGameScreen.h"
#include "Road.h"

InGameScreen::InGameScreen(sf::RenderWindow& window) :
	Screen(window)
{

	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	
	text.setPosition(1250, 0);

	sf::Texture* t = new sf::Texture;
	if (!(t->loadFromFile("Material/Animations/lo.png")))
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
		Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), t);

		truck tmp1(sf::Vector2f(100.f, 100.f), honda, sf::Vector2u(10, 1), 0.1f, 10.f, true);

		TrafficLight TLight(20.0f,20.0f, 0);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i* 100, tmp->getPosition().y));
		tmp->addLight(TLight,tmp -> getPosition() + sf::Vector2f(i*50, 0));
		listObstacle.push_back(tmp);
	}

	float dis = 0;
	for (int i = 0; i < listObstacle.size(); i++)
	{
		listObstacle[i]->setPosition(sf::Vector2f(720, -15 - dis));
		dis += 162;
	}
	t = new sf::Texture;
	if (!t->loadFromFile("Material/Animations/Human.png"))
		std::cout << "Human Animation not found!\n";
	Character man(t, sf::Vector2u(4, 3), 0.1f, 100.0f, listObstacle[0]->getPosition());
	player = man;

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
	sf::Time elapsed = TimeDisplay.getElapsedTime();
	int minutes = static_cast<int>(elapsed.asSeconds()) / 60;
	int seconds = static_cast<int>(elapsed.asSeconds()) % 60;
	text.setString("Time: " + std::to_string(minutes) + "m " +
		std::to_string(seconds) + "s");

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
		window.draw(text);
		player.drawTo(window);
	}

}
