#include "InGameScreen.h"
#include "Road.h"

void InGameScreen::initTex()
{

	myRain;
	//myRain.setState(1);
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	
	text.setPosition(1250, 0);


	sf::Texture* t = new sf::Texture;
	if (!(t->loadFromFile("Material/Animations/lo.png")))
	{
		std::cout << "Can not load road! \n";
	}


	

	sf::Texture* t1 = new sf::Texture;
	{
		if (!(t1->loadFromFile("Material/Animations/le.png")))
		{
			std::cout << "Can not load road! \n";
		}

	}
  
  // Load Vehicle
	sf::Texture* thonda = new sf::Texture;
	if (!(thonda->loadFromFile("Material/Animations/Vehicles/Honda.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	sf::Texture* tcar = new sf::Texture;
	if (!(tcar->loadFromFile("Material/Animations/Vehicles/Car.png")))
	{
		std::cout << "Can not load honda! \n";
	}

	sf::Texture* txedo = new sf::Texture;
	if (!(txedo->loadFromFile("Material/Animations/Vehicles/Xe do.png")))
	{
		std::cout << "Can not load honda! \n";
	}


	// Load the animal 
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

	// Load orthers
	sf::Texture* tstar = new sf::Texture;
	if (!(tstar->loadFromFile("Material/Others/Star.png")))
	{
		std::cout << "Can not load star! \n";
	}

	sf::Texture* tsugarcane = new sf::Texture;
	if (!(tsugarcane->loadFromFile("Material/Others/Item/sugarcane.png")))
	{
		std::cout << "Can not load sugarcane! \n";
	}

	sf::Texture* txaxi = new sf::Texture;
	if (!(txaxi->loadFromFile("Material/Others/Item/xaxi.png")))
	{
		std::cout << "Can not load xaxi! \n";
	}

	sf::Texture thp;
	if (!(thp.loadFromFile("Material/Animations/Stats/Health.png")))
	{
		std::cout << "Can not load player health! \n";
	}

	sf::Texture tst;
	if (!(tst.loadFromFile("Material/Animations/Stats/Stamina.png")))
	{
		std::cout << "Can not load stamina! \n";
	}

	sf::Texture tplayerstar;
	if (!tplayerstar.loadFromFile("Material/Others/Star.png"))
	{
		std::cout << "Can not load star!! \n";
	}

	this->honda = thonda;
	this->car = tcar;
	this->xedo = txedo;

	this->road = t;



	this->road1 = t1;

	this->cat = tcat;
	this->chicken = tchicken;
	this->duck = tduck;
	this->dog = tdog;
	this->monkey = tmonkey;

	this->star = tstar;
	this->sugarcane = tsugarcane;
	this->xaxi = txaxi;

	this->playerHpTex = thp;
	this->playerStaminaTex = tst;
	this->playerStarTex = tplayerstar;
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
	playerStamina.setPosition(0, 35);

	playerPoint.setFont(font);
	playerPoint.setCharacterSize(30);
	playerPoint.setFillColor(sf::Color::White);
	playerPoint.setPosition(0, 73);

	playerHpTexBox.setTexture(playerHpTex);
	sf::IntRect curRectHp(1755 * 3, 0, 1755, 480);
	playerHpTexBox.setTextureRect(curRectHp);
	playerHpTexBox.setScale(0.07f, 0.07f);
	playerHpTexBox.setPosition(45.f, 0.f);

	playerStaminaTexBox.setTexture(playerStaminaTex);
	sf::IntRect curRectStamina(800 * 10, 0, 800, 118);
	playerStaminaTexBox.setTextureRect(curRectStamina);
	playerStaminaTexBox.setScale(0.4f, 0.4f);
	playerStaminaTexBox.setPosition(120.f, 29.f);

	playerStarTexBox.setTexture(playerStarTex);
	sf::IntRect curRectStar(0, 0, 540, 540);
	playerStarTexBox.setTextureRect(curRectStar);
	playerStarTexBox.setScale(0.1f, 0.1f);
	playerStarTexBox.setPosition(85.f,65.f);
}

void InGameScreen::getRoadRan()
{

	int i = static_cast<unsigned>(rand() % 10 + 1);
	int j = static_cast<unsigned>(rand() % 3); // For number of vehicle in a road
	int randItem = static_cast<unsigned>(rand() % 4 + 1); // 1,2,3. 4 for the star ( increase the rating of the star)
	int itemRate = static_cast<unsigned>(rand() % 20 + 1); // this is how frequently the item appear
	int randObs = static_cast<unsigned>(rand() % 11 + 1); // 1 ,7,8,9,10,11 car
	int RandnumCar = static_cast<unsigned>(rand() % 5 + 1);
	int RandnumAnimal = static_cast<unsigned>(rand() % 3 + 1);
	int direct = static_cast<unsigned>(rand() % 2 + 1);


	Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), this->road);
	//Road* tmp1 = new Road(162.0f, sf::Vector2f(0, 1), this->road1);

	// Random Item
	if (itemRate >= 12) {
		if (randItem == 2) {
			Item tmp0(sf::Vector2f(100.f, 100.f), this->sugarcane, sf::Vector2u(1, 1), 0.1f, 2); //
			float randCoor = static_cast<float>(rand() % 600 + 50);
			tmp->addItem(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
		}
		else if (randItem == 3) {
			Item tmp0(sf::Vector2f(30.f, 45.f), this->xaxi, sf::Vector2u(1, 1), 0.1f, 3); //
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
	//int randObs = static_cast<int>(rand() % 5 + 1);


	//Random obstacle
	if ((randObs == 1 || randObs >= 7) && playing) { // for car
		int curDir = -1;
		for (int j = 0;j < RandnumCar ;j++) {
			int RandCarType = static_cast<unsigned>(rand() % 3 + 1);
			if (direct == 1) {
				curDir = 1;
				if (RandCarType == 1) {
					truck tmp1(sf::Vector2f(100.f, 100.f), this->honda, sf::Vector2u(10, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 300, tmp->getPosition().y));
				}
				else if (RandCarType == 2) {
					truck tmp1(sf::Vector2f(288.6675f, 100.f), this->car, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 300, tmp->getPosition().y));
				}
				else if (RandCarType == 3) { // 1408 4224x330 1408/110
					truck tmp1(sf::Vector2f(352.f, 110.f), this->xedo, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 300, tmp->getPosition().y));
				}
			}
			else {
				curDir = 0;
				if (RandCarType == 1) {
					truck tmp1(sf::Vector2f(100.f, 100.f), this->honda, sf::Vector2u(10, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 300, tmp->getPosition().y));
				}
				else if (RandCarType == 2) {
					truck tmp1(sf::Vector2f(288.6675f, 100.f), this->car, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 300, tmp->getPosition().y));
				}
				else if (RandCarType == 3) {
					truck tmp1(sf::Vector2f(352.f, 110.f), this->xedo, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 300, tmp->getPosition().y));
				}
			}
		}
		if (curDir == 1) {
			TrafficLight TLight(15.0f, 20.0f, 0);
			tmp->addLight(TLight, tmp->getPosition() - sf::Vector2f(i * 50, 0));
		}
		else if (curDir == 0) {
			TrafficLight TLight(15.0f, 20.0f, 1);
			tmp->addLight(TLight, tmp->getPosition() + sf::Vector2f(i * 50, 0));
		}
	}
	else if (randObs == 2 && playing) { // for cat
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(160.f, 90.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 300, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(160.f, 90.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 300, tmp->getPosition().y));
			}
		}
	}
	else if (randObs == 3 && playing) { // for chicken
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->chicken, sf::Vector2u(12, 1), 0.1f, 15.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 200, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->chicken, sf::Vector2u(12, 1), 0.1f, 15.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 200, tmp->getPosition().y));
			}

		}
	}
	else if (randObs == 4 && playing) { // foc duck
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->duck, sf::Vector2u(6, 1), 0.1f, 10.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 200, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->duck, sf::Vector2u(6, 1), 0.1f, 10.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 200, tmp->getPosition().y));
			}
		}
	}
	else if (randObs == 5 && playing) { // for dog
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(125.f, 125.f), this->dog, sf::Vector2u(8, 1), 0.1f, 10.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 200, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(125.f, 125.f), this->dog, sf::Vector2u(8, 1), 0.1f, 10.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 200, tmp->getPosition().y));
			}
		}
	}
	else if (randObs == 6 && playing) { // for monkey 
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->monkey, sf::Vector2u(8, 1), 0.1f, 10.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 200, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(100.f, 100.f), this->monkey, sf::Vector2u(8, 1), 0.1f, 10.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 200, tmp->getPosition().y));
			}
		}

	}
	if (i % 2 && randObs != 1) tmp->setTexture(road1);

	listObstacle.push_back(tmp);
	if (listObstacle.size() == 1) {
		listObstacle[listObstacle.size() - 1]->setPosition(sf::Vector2f(720, +81));
	}
	else {
		listObstacle[listObstacle.size() - 1]->setPosition(sf::Vector2f(720, listObstacle[listObstacle.size() - 2]->getPosition().y - 162));
	}
}

InGameScreen::InGameScreen(sf::RenderWindow& window) :
	Screen(window),
	pause(false),
	pauseMenu(window),
	playing(false)
{
	initText();

	initTex();
	
	for (int i = 0;i < 7;i++) {
		getRoadRan();
	}

	sf::Texture* tman = new sf::Texture;
	if (!tman->loadFromFile("Material/Animations/Human.png"))
		std::cout << "Human Animation not found!\n";
	Character man(tman, sf::Vector2u(4, 3), 0.1f, 100.0f, listObstacle[0]->getPosition());
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
	if (pause)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (pauseMenu.isMouseOverResumeButton(window)) // RESUME
			{
				pause = false;
			}
			else if (pauseMenu.isMouseOverRestartButton(window)) // RESTART
			{

			}
			else if (pauseMenu.isMouseOverQuitButton(window)) // QUIT TO MENU
			{
				pause = false;
				GamePlayScreen::isContinue = true;
				currentScreen = ScreenState::GamePlayScreen;
				endScreen = true;
				isEndScreen = endScreen;
			}
		}
	}
	else
	{
		if (event.type == sf::Event::KeyReleased)
		{
			if (playing == 0 && player.getHp() > 0 && started == 0)
			{
				playing = 1;
				started = 1;
				//clock.restart();
			}
			else if (!playing && player.getHp() > 0)
			{
				playing = true;
			}
			else if (playing)
			{
				if (event.key.code == sf::Keyboard::Escape) {
					pause = true;
					playing = false;
				}
			}
		}
	}
}

void InGameScreen::update(sf::RenderWindow& window)
{
	if (pause)
	{
		pauseMenu.update(window);
	}
	else
	{
		if (playing == 0 && player.getHp() == player.getHpMax() && started == 0)
		{
			TimeDisplay.restart();
		}
		else if (player.getHp() > 0) elapsed = TimeDisplay.getElapsedTime();
		int minutes = static_cast<int>(elapsed.asSeconds()) / 60;
		int seconds = static_cast<int>(elapsed.asSeconds()) % 60;
		text.setString("Time: " + std::to_string(minutes) + "m " +
			std::to_string(seconds) + "s");

		deltaTime = clock.restart().asSeconds();

		playerHp.setString("Hp: ");
		int curHp = player.getHp();
		playerHpTexBox.setTexture(playerHpTex);
		sf::IntRect curRectHp(1755 * curHp, 0, 1755, 480);
		playerHpTexBox.setTextureRect(curRectHp);
		playerHpTexBox.setScale(0.1f, 0.1f);

		playerStamina.setString("Stamina: ");
		int curStamina = player.getStamina();
		playerStaminaTexBox.setTexture(playerStaminaTex);
		sf::IntRect curRectStamina(800 * curStamina, 0, 800, 118);
		playerStaminaTexBox.setTextureRect(curRectStamina);
		playerStaminaTexBox.setScale(0.4f, 0.4f);
		//playerStaminaTexBox.setPosition(120.f, 29.f);

		playerPoint.setString("Star: " + std::to_string(player.getPoint()));
		std::string StarString = std::to_string(player.getPoint());
		float lenStarString = static_cast<float>(StarString.size() * 5);
		playerStarTexBox.setPosition(85.f + lenStarString, 65.f);


		if (playing == 0) 
			player.update(deltaTime);
		if (playing)
		{
			for (int i = 0; i < listObstacle.size(); i++)
			{
				listObstacle[i]->update();
				//std::cout << i << " " << listObstacle[i]->getPosition().x << " " << listObstacle[i]->getPosition().y<<"\n";
			}

			player.update(deltaTime, listObstacle);

			// Stamina
			player.reduceStamina();
			//std::cout << player.getStamina() << " / " << player.getStaminaMax() << "\n";


			//Rain effect
			myRain.update(window, player);

			devil.update(deltaTime, devil.getRight(), player);

			for (int i = 0; i < listObstacle.size(); i++)
			{
				if (listObstacle[i]->charIsInside(player) && listObstacle[i]->isCollision(player)) {
					player.loadgetDamage(); // after intersect with the obstacle, being invisible
					//std::cout << player.getHp() << "\n";
				}
				listObstacle[i]->isGetItem(player);
			}

			// Return the normal state after the invisible
			player.settoNormal();

			//Endless mode
			for (int i = 0; i < listObstacle.size(); i++) {
				if (listObstacle[i]->getPosition().y - 81.f > 810.f) {
					//listObstacle[i]->clear();
					listObstacle.erase(listObstacle.begin() + i);
					getRoadRan();
				}
			}

			if (player.getHp() <= 0) 
				playing = 0;

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

		// Render Hp and Hp bar
		window.draw(playerHp);
		window.draw(playerHpTexBox);
		// Render Stamina and Stamina Hp
		window.draw(playerStamina);
		window.draw(playerStaminaTexBox);
		// Render player point
		window.draw(playerPoint);
		window.draw(playerStarTexBox);

		player.drawTo(window);
		devil.drawTo(window);
		if(myRain.getState())myRain.drawTo(window);

		if (pause)
		{
			pauseMenu.render(window);
		}
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
