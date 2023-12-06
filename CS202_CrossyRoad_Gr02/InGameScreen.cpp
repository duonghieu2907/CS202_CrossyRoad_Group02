#include "InGameScreen.h"
#include "Road.h"

void InGameScreen::initTex()
{
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

	sf::Texture* tcat = new sf::Texture;
	if (!(tcat->loadFromFile("Material/Animations/Cat.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	sf::Texture* tchicken = new sf::Texture;
	if (!(tchicken->loadFromFile("Material/Animations/Chicken.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	sf::Texture* tduck = new sf::Texture;
	if (!(tduck->loadFromFile("Material/Animations/Duck.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	this->car = honda;
	this->road = t;
	this->cat = tcat;
	this->chicken = tchicken;
	this->duck = tduck;

}

void InGameScreen::initText()
{
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(1250, 0);

	playerHp.setFont(font);
	playerHp.setCharacterSize(30);
	playerHp.setFillColor(sf::Color::White);
	playerHp.setPosition(0, 0);

	playerStamina.setFont(font);
	playerStamina.setCharacterSize(30);
	playerStamina.setFillColor(sf::Color::White);
	playerStamina.setPosition(0, 31);
}

void InGameScreen::getRoadRan()
{
	int i = static_cast<unsigned>(rand() % 10 + 1);

	Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), this->road);

	TrafficLight TLight(20.0f, 20.0f, 0);

	int randObs = static_cast<int>(rand() % 5 + 1);
	if (randObs == 1) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->car, sf::Vector2u(10, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
		tmp->addLight(TLight, tmp->getPosition() + sf::Vector2f(i * 50, 0));
	}
	else if (randObs == 2) { // the problem maybe from the switch time
		truck tmp1(sf::Vector2f(100.f, 100.f), this->cat, sf::Vector2u(8, 5), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 3) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->chicken, sf::Vector2u(4, 5), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 4) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->duck, sf::Vector2u(4, 5), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}

	listObstacle.push_back(tmp);
	if (listObstacle.size() == 1) {
		listObstacle[listObstacle.size() - 1]->setPosition(sf::Vector2f(720, -15));
	}
	else {
		listObstacle[listObstacle.size() - 1]->setPosition(sf::Vector2f(720, listObstacle[listObstacle.size() - 2]->getPosition().y - 162));
	}
}

InGameScreen::InGameScreen(sf::RenderWindow& window) :
	Screen(window)
{
	initText();

	initTex();
	//dis = 0;
	for (int i = 0;i < 7;i++) {
		getRoadRan();
	}

	sf::Texture* t = new sf::Texture;
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
		//std::cout << i << " " << listObstacle[i]->getPosition().x << " " << listObstacle[i]->getPosition().y<<"\n";
	}
	
	player.update(deltaTime, listObstacle);

	// Stamina
	player.reduceStamina();
	//std::cout << player.getStamina() << " / " << player.getStaminaMax() << "\n";

	for (int i = 0; i < listObstacle.size();i++)
	{
		if (listObstacle[i]->isCollision(player)) {
			player.loadgetDamage(); // after intersect with the obstacle, being invisible
			//std::cout << player.getHp() << "\n";
		}
	}
	// Return the normal state after the invisible
	player.settoNormal();

	// Player hp render
	playerHp.setString("PLayer Hp: " + std::to_string(player.getHp()) + " / " + std::to_string(player.getHpMax()) + "\n");
	playerStamina.setString("PLayer Stamina: " + std::to_string(player.getStamina()) + " / " + std::to_string(player.getStaminaMax()) + "\n");

	//Endless mode
	///*
	for (int i = 0;i < listObstacle.size();i++) {
		if (listObstacle[i]->getPosition().y - 81.f > 920.f) {
			listObstacle.erase(listObstacle.begin() + i);
			getRoadRan();
		}
	}
	//*/

	//std::cout << listObstacle.size() << "\n";
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
		window.draw(playerHp);
		window.draw(playerStamina);
		player.drawTo(window);
	}

}
