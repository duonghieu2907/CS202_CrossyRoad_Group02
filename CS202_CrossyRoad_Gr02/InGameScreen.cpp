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
	if (!(tcat->loadFromFile("Material/Animations/cat sheet.png")))
	{
		std::cout << "Can not load cat! \n";
	}

	sf::Texture* tchicken = new sf::Texture;
	if (!(tchicken->loadFromFile("Material/Animations/chicken sheet.png")))
	{
		std::cout << "Can not load chicken! \n";
	}

	sf::Texture* tduck = new sf::Texture;
	if (!(tduck->loadFromFile("Material/Animations/duck sheet.png")))
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

	sf::Texture* twater = new sf::Texture;
	if (!(twater->loadFromFile("Material/Others/Water.png")))
	{
		std::cout << "Can not load star! \n";
	}

	sf::Texture* tcola = new sf::Texture;
	if (!(tcola->loadFromFile("Material/Others/Cola.png")))
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
	this->water = twater;
	this->cola = tcola;
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
	int randItem = static_cast<unsigned>(rand() % 4 + 1); // 1,2,3. 4 for the star ( increase the rating of the star)
	int itemRate = static_cast<unsigned>(rand() % 20 + 1); // this is how frequently the item appear
	int randObs = static_cast<int>(rand() % 6 + 1);


	Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), this->road);

	// Random Item
	if (itemRate >= 12) {
		if (randItem == 2) {
			Item tmp0(sf::Vector2f(100.f, 100.f), this->water, sf::Vector2u(1, 1), 0.1f, 2); //
			float randCoor = static_cast<float>(rand() % 600 + 50);
			tmp->addItem(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
		}
		else if (randItem == 3) {
			Item tmp0(sf::Vector2f(40.f, 40.f), this->cola, sf::Vector2u(1, 1), 0.1f, 3); //
			float randCoor = static_cast<float>(rand() % 600 + 50);
			tmp->addItem(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
		}
	}
	else if (itemRate < 12 && itemRate >= 1) {
		if (randItem == 1 || randItem == 4) {
			Item tmp0(sf::Vector2f(100.f, 100.f), this->star, sf::Vector2u(1, 1), 0.1f, 1); //
			float randCoor = static_cast<float>(rand() % 600 + 50);
			tmp->addItem(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
		}
	}

	TrafficLight TLight(20.0f, 20.0f, 0);
	int randObs = static_cast<int>(rand() % 5 + 1);
	if (randObs == 1 && playing) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->car, sf::Vector2u(10, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i*40 , tmp->getPosition().y));
		tmp->addLight(TLight, tmp->getPosition() + sf::Vector2f(i * 50, 0));
	}

	
	//Random obstacle
	else if (randObs == 2) { // the cat is so big!!!! 
		truck tmp1(sf::Vector2f(100.f, 100.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 3) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->chicken, sf::Vector2u(12, 1), 0.1f, 15.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 4) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->duck, sf::Vector2u(6, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 5) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->dog, sf::Vector2u(8, 1), 0.1f, 20.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));
	}
	else if (randObs == 6) {
		truck tmp1(sf::Vector2f(100.f, 100.f), this->monkey, sf::Vector2u(8, 1), 0.1f, 10.f, true);
		tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 100, tmp->getPosition().y));

	}

	listObstacle.push_back(tmp);
	if (listObstacle.size() == 1) {
		listObstacle[listObstacle.size() - 1]->setPosition(sf::Vector2f(720, +81));
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

	sf::Texture* tghost = new sf::Texture;
	if (!tghost->loadFromFile("Material/Animations/ghost flight.png"))
	{
		std::cout << "Can not load ghost\n";
	}
	 ghost women(sf::Vector2f(150.f, 150.f), tghost, sf::Vector2u(6, 1), 0.1f, 0.01f, true);
	 devil = women;
	// devil.setState(1);
}

void InGameScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		if (playing == 0 && player.getHp() >= 0)
		{
			playing = 1;
			//clock.restart();
		}
	}
}

void InGameScreen::update(sf::RenderWindow& window)
{

	if (playing == 0 && player.getHp() == player.getHpMax())
	{
		TimeDisplay.restart();
	}
	else if(player.getHp() > 0) elapsed = TimeDisplay.getElapsedTime();
 	int minutes = static_cast<int>(elapsed.asSeconds()) / 60;
	int seconds = static_cast<int>(elapsed.asSeconds()) % 60;
	text.setString("Time: " + std::to_string(minutes) + "m " +
		std::to_string(seconds) + "s");

	deltaTime = clock.restart().asSeconds();

	playerHp.setString("PLayer Hp: " + std::to_string(player.getHp()) + " / " + std::to_string(player.getHpMax()) + "\n");
	playerStamina.setString("PLayer Stamina: " + std::to_string(player.getStamina()) + " / " + std::to_string(player.getStaminaMax()) + "\n");
	if(playing == 0) player.update(deltaTime);
	if (playing)
	{


		for (int i = 0; i < listObstacle.size();i++)
		{
			listObstacle[i]->update();
			//std::cout << i << " " << listObstacle[i]->getPosition().x << " " << listObstacle[i]->getPosition().y<<"\n";
		}

		player.update(deltaTime, listObstacle);

		// Stamina
		player.reduceStamina();
		//std::cout << player.getStamina() << " / " << player.getStaminaMax() << "\n";


		//Rain effect
		if (myRain.getState()) myRain.update(window);

		devil.update(deltaTime, devil.getRight(), player);

		for (int i = 0; i < listObstacle.size();i++)
		{
			if (listObstacle[i]->charIsInside(player) && listObstacle[i]->isCollision(player)) {
				player.loadgetDamage(); // after intersect with the obstacle, being invisible
				//std::cout << player.getHp() << "\n";
			}
		}
		// Return the normal state after the invisible
		player.settoNormal();

		// Player hp render
	

		//Endless mode
		for (int i = 0;i < listObstacle.size();i++) {
			if (listObstacle[i]->getPosition().y - 81.f > 810.f) {
				listObstacle.erase(listObstacle.begin() + i);
				getRoadRan();
			}
		}

		if (player.getHp() <= 0) playing = 0;

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
		devil.drawTo(window);
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
