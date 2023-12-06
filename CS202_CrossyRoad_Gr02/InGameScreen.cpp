#include "InGameScreen.h"
#include "Road.h"

void InGameScreen::initTex()
{

	myRain;
	myRain.setState(1);
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
	if (!(honda->loadFromFile("Material/Animations/honda.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	sf::Texture* tcat = new sf::Texture;
	if (!(tcat->loadFromFile("Material/Animations/Cat.png")))
	{
		std::cout << "Can not load cat! \n";
	}

	sf::Texture* tchicken = new sf::Texture;
	if (!(tchicken->loadFromFile("Material/Animations/Chicken.png")))
	{
		std::cout << "Can not load chicken! \n";
	}

	sf::Texture* tduck = new sf::Texture;
	if (!(tduck->loadFromFile("Material/Animations/Duck.png")))
	{
		std::cout << "Can not load duck! \n";
	}

	sf::Texture* tdog = new sf::Texture;
	if (!(tdog->loadFromFile("Material/Animations/Dog.png")))
	{
		std::cout << "Can not load dog! \n";
	}

	sf::Texture* tmonkey = new sf::Texture;
	if (!(tmonkey->loadFromFile("Material/Animations/Monkey.png")))
	{
		std::cout << "Can not load monkey! \n";
	}

	sf::Texture* tstar = new sf::Texture;
	if (!(tstar->loadFromFile("Material/Others/Star.png")))
	{
		std::cout << "Can not load star! \n";
	}

	this->car = honda;
	this->road = t;
	this->cat = tcat;
	this->chicken = tchicken;
	this->duck = tduck;
	this->dog = tdog;
	this->monkey = tmonkey;
	this->star = tstar;
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

	playerPoint.setFont(font);
	playerPoint.setCharacterSize(30);
	playerPoint.setFillColor(sf::Color::White);
	playerPoint.setPosition(0, 62);
}

void InGameScreen::getRoadRan()
{
	int i = static_cast<unsigned>(rand() % 10 + 1);
	int randItem = static_cast<unsigned>(rand() % 3 + 1); // 1,2,3

	Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), this->road);

	TrafficLight TLight(20.0f, 20.0f, 0);

	int randObs = static_cast<int>(rand() % 6 + 1);
	if (randObs == 1) {
		Item tmp0(sf::Vector2f (100.f,100.f),this->star, sf::Vector2u(1,1),0.1f,1); //
		truck tmp1(sf::Vector2f(100.f, 100.f), this->car, sf::Vector2u(10, 1), 0.1f, 10.f, true);

		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
		tmp->addLight(TLight, tmp->getPosition() + sf::Vector2f(i * 50, 0));
		tmp->addItem(tmp0, tmp->getPosition() + sf::Vector2f(i * 40, 0)); // 
	}
	else if (randObs == 2) { // the cat is so big!!!! 
		truck tmp1(sf::Vector2f(100.f, 100.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 3) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->chicken, sf::Vector2u(12, 1), 0.1f, 10.f, 0);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 4) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->duck, sf::Vector2u(6, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 5) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->dog, sf::Vector2u(8, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 6) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->monkey, sf::Vector2u(8, 1), 0.1f, 10.f, true);
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
	if (player.getHp() > 0) { //update when playerHp is bigger than 0
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

		// Stamina
		player.reduceStamina();


		//Rain effect
		if (myRain.getState()) myRain.update(window);


		//Intersect with the object
		for (int i = 0; i < listObstacle.size();i++)
		{
			if (listObstacle[i]->charIsInside(player) && listObstacle[i]->isCollision(player)) {
				player.loadgetDamage(); // after intersect with the obstacle, being invisible
			}
			listObstacle[i]->isGetItem(player);
		}
		// Return the normal state after the invisible
		player.settoNormal();

		// Player hp render
		playerHp.setString("PLayer Hp: " + std::to_string(player.getHp()) + " / " + std::to_string(player.getHpMax()));
		playerStamina.setString("PLayer Stamina: " + std::to_string(player.getStamina()) + " / " + std::to_string(player.getStaminaMax()));
		playerPoint.setString("PLayer Point: " + std::to_string(player.getPoint()));

		//Endless mode
		for (int i = 0;i < listObstacle.size();i++) {
			if (listObstacle[i]->getPosition().y - 81.f > 810.f) {
				listObstacle.erase(listObstacle.begin() + i);
				getRoadRan();
			}
		}
	}
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
		window.draw(playerPoint);
		player.drawTo(window);
		if(myRain.getState())myRain.drawTo(window);
	}

}

const bool InGameScreen::isEndGame()
{
	if (player.getHp() == 0) {
		return true;
	}
	else {
		return false;
	}
}
