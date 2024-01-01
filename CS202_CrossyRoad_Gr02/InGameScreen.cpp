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
	if (!(t->loadFromFile("Material/Animations/Lane/lo.png")))
	{
		std::cout << "Can not load road! \n";
	}

	sf::Texture* t1 = new sf::Texture;
	{
		if (!(t1->loadFromFile("Material/Animations/Lane/le.png")))
		{
			std::cout << "Can not load road! \n";
		}

	}

	sf::Texture* t2 = new sf::Texture;
	if (!(t2->loadFromFile("Material/Animations/Lane/la.png")))
	{
		std::cout << "Can not load road! \n";
	}

	sf::Texture* t3 = new sf::Texture;
	if (!(t3->loadFromFile("Material/Animations/Lane/song.png")))
	{
		std::cout << "Can not load road! \n";
	}

	//Lane object
	sf::Texture* tbridge = new sf::Texture;
	if (!(tbridge->loadFromFile("Material/Animations/Lane Object/bridge.png")))
	{
		std::cout << "Can not load bridge! \n";
	}
  
  // Load Vehicle
	sf::Texture* thonda = new sf::Texture;
	if (!(thonda->loadFromFile("Material/Animations/Vehicles/Xe may.png")))
	{
		std::cout << "Can not load xe may! \n";
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

	sf::Texture* txecuuthuong = new sf::Texture;
	if (!(txecuuthuong->loadFromFile("Material/Animations/Vehicles/Xe cuu thuong.png")))
	{
		std::cout << "Can not load xe cuu thuong! \n";
	}

	sf::Texture* txebantai = new sf::Texture;
	if (!(txebantai->loadFromFile("Material/Animations/Vehicles/Xe ban tai.png")))
	{
		std::cout << "Can not load ban tai! \n";
	}

	// Load the animal 
	sf::Texture* tcat = new sf::Texture;
	if (!(tcat->loadFromFile("Material/Animations/Animals/cat sheet.png")))
	{
		std::cout << "Can not load cat! \n";
	}

	sf::Texture* tchicken = new sf::Texture;
	if (!(tchicken->loadFromFile("Material/Animations/Animals/chicken sheet.png")))
	{
		std::cout << "Can not load chicken! \n";
	}

	sf::Texture* tduck = new sf::Texture;
	if (!(tduck->loadFromFile("Material/Animations/Animals/duck sheet.png")))
	{
		std::cout << "Can not load duck! \n";
	}

	sf::Texture* tdog = new sf::Texture;
	if (!(tdog->loadFromFile("Material/Animations/Animals/Dog.png")))
	{
		std::cout << "Can not load dog! \n";
	}

	sf::Texture* tmonkey = new sf::Texture;
	if (!(tmonkey->loadFromFile("Material/Animations/Animals/Monkey.png")))
	{
		std::cout << "Can not load monkey! \n";
	}

	// Load orthers
	sf::Texture* tstar = new sf::Texture;
	if (!(tstar->loadFromFile("Material/Others/Item/Star.png")))
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

	// Load static obstacle
	sf::Texture* tobs1 = new sf::Texture;
	if (!tobs1->loadFromFile("Material/Animations/Obstacles/1.png"))
	{
		std::cout << "Can not load obj1!! \n";
	}

	sf::Texture* tobs2 = new sf::Texture;
	if (!tobs2->loadFromFile("Material/Animations/Obstacles/2.png"))
	{
		std::cout << "Can not load obj2!! \n";
	}

	sf::Texture* tobs3 = new sf::Texture;
	if (!tobs3->loadFromFile("Material/Animations/Obstacles/3.png"))
	{
		std::cout << "Can not load obj3!! \n";
	}

	sf::Texture* tobs4 = new sf::Texture;
	if (!tobs4->loadFromFile("Material/Animations/Obstacles/4.png"))
	{
		std::cout << "Can not load obj4!! \n";
	}

	sf::Texture* tobs5 = new sf::Texture;
	if (!tobs5->loadFromFile("Material/Animations/Obstacles/5.png"))
	{
		std::cout << "Can not load obj5!! \n";
	}

	sf::Texture* tobs6 = new sf::Texture;
	if (!tobs6->loadFromFile("Material/Animations/Obstacles/6.png"))
	{
		std::cout << "Can not load obj6!! \n";
	}

	sf::Texture* tobs7 = new sf::Texture;
	if (!tobs7->loadFromFile("Material/Animations/Obstacles/7.png"))
	{
		std::cout << "Can not load obj7!! \n";
	}

	sf::Texture* tobs8 = new sf::Texture;
	if (!tobs8->loadFromFile("Material/Animations/Obstacles/8.png"))
	{
		std::cout << "Can not load obj8!! \n";
	}

	// Load gift
	sf::Texture* tbanhmi = new sf::Texture;
	if (!tbanhmi->loadFromFile("Material/Others/Chest Item/banhmi.png"))
	{
		std::cout << "Can not load banhmi!! \n";
	}

	sf::Texture* tcomtam = new sf::Texture;
	if (!tcomtam->loadFromFile("Material/Others/Chest Item/comtam.png"))
	{
		std::cout << "Can not load comtam!! \n";
	}

	sf::Texture* tma = new sf::Texture;
	if (!tma->loadFromFile("Material/Others/Chest Item/Chest.png"))
	{
		std::cout << "Can not load gift!! \n";
	}

	// Load background
	sf::Texture* tbackground = new sf::Texture;
	if (!tbackground->loadFromFile("Material/Backgrounds/StartingScreen.png"))
	{
		std::cout << "Can not load background!! \n";
	}

	this->honda = thonda;
	this->car = tcar;
	this->xedo = txedo;
	this->xecuuthuong = txecuuthuong;
	this->xebantai = txebantai;

	this->road = t;
	this->road1 = t1;
	this->road2 = t2;
	this->road3 = t3;
	this->bridge = tbridge;

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

	this->obs1 = tobs1;
	this->obs2 = tobs2;
	this->obs3 = tobs3;
	this->obs4 = tobs4;
	this->obs5 = tobs5;
	this->obs6 = tobs6;
	this->obs7 = tobs7;
	this->obs8 = tobs8;
  
	this->comtam = tcomtam;
	this->banhmi = tbanhmi;
	this->ma = tma;

	this->background.setSize(sf::Vector2f(1440,880));
	this->background.setTexture(tbackground);
	this->background.setPosition(sf::Vector2f(0.f, 0.f));
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
	int j = static_cast<unsigned>(rand() % 3 + 1); // For number of vehicle in a road
	int randItem = static_cast<unsigned>(rand() % 4 + 1); // 1,2,3. 4 for the star ( increase the rating of the star)
	int itemRate = static_cast<unsigned>(rand() % 20 + 1); // this is how frequently the item appear
	int randObs = static_cast<unsigned>(rand() % 25 + 1 ); // 1 , 7 -15 car ; 2-6 for animal ; >= 16 <=20 for static obstacle, 21 - 23 leaf, 24-25 river
	int RandnumCar = static_cast<unsigned>(rand() % 5 + 1);
	int RandnumAnimal = static_cast<unsigned>(rand() % 3 + 1);
	int direct = static_cast<unsigned>(rand() % 2 + 1);
	int RoadType = static_cast<unsigned>(rand() % 2 + 1);

	Road* tmp = new Road(162.0f, sf::Vector2f(0, 1), this->road);

	// Random Item
	float randCoor = 0.f;
	int rightRand0 = static_cast<unsigned>(rand() % 2 + 1);
	if (rightRand0 == 1) {
		randCoor = static_cast<float>(rand() % 500 + 50);
	}
	else {
		randCoor = - static_cast<float>(rand() % 500 + 50);
	}
	ItemCoor = tmp->getPosition() + sf::Vector2f(randCoor, 0);

	if (randObs <= 23 ) {
		if (itemRate >= 12) {
			if (randItem == 2) { // 102x61
				Item tmp0(sf::Vector2f(51.f, 61.f), this->sugarcane, sf::Vector2u(2, 1), 0.1f, 2); //
				tmp->addItem(tmp0, ItemCoor);
			}
			else if (randItem == 3) { // 82x71
				Item tmp0(sf::Vector2f(41.f, 71.f), this->xaxi, sf::Vector2u(2, 1), 0.1f, 3); //
				tmp->addItem(tmp0, ItemCoor);
			}
		}
		else if (itemRate < 12 && itemRate >= 1) { // 137x60
			if (randItem == 1 || randItem == 4) {
				Item tmp0(sf::Vector2f(68.5f, 60.f), this->star, sf::Vector2u(2, 1), 0.1f, 1);
				tmp->addItem(tmp0, ItemCoor);
			}
		}
	}


	//Random obstacle
	if ((randObs == 1 || randObs >= 7 && randObs <= 15) && playing) { // for car and gift

		//set gift here
		int giftRand = static_cast<unsigned>(rand() % 3 + 1); // Set percentage here - 33.3%
		int rightRand = static_cast<unsigned> (rand() % 2 + 1);

		float randCoor = 0.f;
		if (rightRand == 1) {
			randCoor = static_cast<float>(rand() % 500 + 50);
		}
		else {
			randCoor = - static_cast<float>(rand() % 500 + 50);
		}
		
		if (giftRand == 1) { // add gift
			int giftTypeRand = static_cast<unsigned>(rand() % 8 + 1);
			if (giftTypeRand == 1) {
				Item tmp0(sf::Vector2f(100.f, 50.f), this->banhmi, sf::Vector2u(3, 1), 0.1, 4);
				tmp->addGift(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
			}
			else if (giftTypeRand == 2) {
				Item tmp0(sf::Vector2f(100.f, 50.f), this->comtam, sf::Vector2u(3, 1), 0.1, 5);
				tmp->addGift(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
			}
			else if (giftTypeRand >= 3) {
				Item tmp0(sf::Vector2f(100.f, 50.f), this->ma, sf::Vector2u(3, 1), 0.1, 6);
				tmp->addGift(tmp0, tmp->getPosition() + sf::Vector2f(randCoor, 0));
			}
		}

		// Set car here

		int curDir = -1;
		for (int j = 0;j < RandnumCar;j++) {
			int RandCarType = static_cast<unsigned>(rand() % 5 + 1);
			if (direct == 1) {
				curDir = 1;
				if (RandCarType == 1) {
					truck tmp1(sf::Vector2f(89.f, 85.f), this->honda, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 2) {
					truck tmp1(sf::Vector2f(288.667f, 100.f), this->car, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 3) { 
					truck tmp1(sf::Vector2f(352.f, 110.f), this->xedo, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 4) { 
					truck tmp1(sf::Vector2f(291.67f, 100.f), this->xebantai, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 5) { 
					truck tmp1(sf::Vector2f(218.75f, 110.f), this->xecuuthuong, sf::Vector2u(4, 1), 0.1f, 10.f, true);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
			}
			else {
				curDir = 0;
				if (RandCarType == 1) {
					truck tmp1(sf::Vector2f(89.f, 85.f), this->honda, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 2) {
					truck tmp1(sf::Vector2f(288.6675f, 100.f), this->car, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 3) {
					truck tmp1(sf::Vector2f(352.f, 110.f), this->xedo, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 10 + j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 4) {
					truck tmp1(sf::Vector2f(291.67f, 100.f), this->xebantai, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
				}
				else if (RandCarType == 5) {
					truck tmp1(sf::Vector2f(218.75f, 110.f), this->xecuuthuong, sf::Vector2u(4, 1), 0.1f, 10.f, false);
					tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 10 - j * 400, tmp->getPosition().y));
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
		tmp->setTexture(road);
	}

	if (randObs == 2 && playing) { // for cat
		for (int j = 0;j < RandnumAnimal;j++) {
			if (direct == 1) {
				truck tmp1(sf::Vector2f(120.f, 90.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, true);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x - 720 - i * 20 - j * 300, tmp->getPosition().y));
			}
			else {
				truck tmp1(sf::Vector2f(120.f, 90.f), this->cat, sf::Vector2u(4, 1), 0.1f, 10.f, false);
				tmp->addCar(tmp1, sf::Vector2f(tmp->getPosition().x + 720 + i * 20 + j * 300, tmp->getPosition().y));
			}
		}
		tmp->setTexture(road1);
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
		tmp->setTexture(road1);
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
		tmp->setTexture(road1);
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
		tmp->setTexture(road1);
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
		tmp->setTexture(road1);
	}
	else if (randObs >= 16 && randObs <= 20) { // static obstacles
		int RandObsNum = static_cast<unsigned>(rand() % 4 + 1); // 1-7 block
		int saveRand = 0;
		int arr[8];
		for (int i = 0;i < 8;i++) {
			arr[i] = 0;
		}
		int earr[8];
		for (int i = 0;i < 8;i++) {
			earr[i] = 0;
		}

		for (int k = 0;k < RandObsNum;k++) {
			int StaObsRand = static_cast<unsigned>(rand() % 10 + 1); // get random for the static obstacle
			int PosObsRand = static_cast<unsigned>(rand() % 7 + 1);

			while (arr[PosObsRand] == 1 || earr[PosObsRand] == 1) { // make sure current obstacle don't spawn on the previous one

				PosObsRand = static_cast<unsigned>(rand() % 7 + 1);
				int counter = 0;
				for (int i = 0;i < 8;i++) { 
					if (arr[i] == 1) {
						counter += 1;
					}
				}
				if (counter == 7) { // if all the position is one, break the loop
					break;
				}
			}

			float ObsDis = 200.f;
			if (PosObsRand == 1) {
				ObsDis = -600.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 2) {
				ObsDis = -400.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 3) {
				ObsDis = -200.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 4) {
				ObsDis = 0.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 5) {
				ObsDis = 200.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 6) {
				ObsDis = 400.f;
				earr[PosObsRand] = 1;
			}
			else if (PosObsRand == 7) {
				ObsDis = 600.f;
				earr[PosObsRand] = 1;
			}

			if (abs(tmp->getPosition().x + ObsDis - ItemCoor.x) >= 100.f) { // the Obs not spawn on the Item
				if (StaObsRand == 1) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs1, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 2) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs2, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 3) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs3, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 4) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs4, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 5) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs5, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis - 10.f, tmp->getPosition().y - 15.f));
				}
				else if (StaObsRand == 6) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs6, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 7) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs7, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis - 10.f, tmp->getPosition().y - 5.f));
				}
				else if (StaObsRand == 8) {
					StaticObstacles tmp1(sf::Vector2f(140.f, 140.f), this->obs8, sf::Vector2u(1, 1), 0);
					tmp->addObj(tmp1, sf::Vector2f(tmp->getPosition().x + ObsDis, tmp->getPosition().y - 5.f));
				}
			}
		}
		tmp->setTexture(road1);
	}
	else if (randObs >= 21 && randObs <= 23) {
		tmp->setTexture(road2);
		}
	else if (randObs >= 24){
		sf::RectangleShape tmpBridge;
		tmpBridge.setSize(sf::Vector2f(100.f,110.f));
		tmpBridge.setOrigin(sf::Vector2f(tmpBridge.getGlobalBounds().width/2 , tmpBridge.getGlobalBounds().height / 2));
		tmpBridge.setTexture(bridge);

		tmp->addBridge(tmpBridge, tmp->getPosition());
		tmp->setTexture(road3);
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
	Screen(window),
	pause(false),
	pauseMenu(window),
	endMenu(window),
	continueMenu(window),
	playing(false)
{
	initText();

	initTex();
	
	for (int i = 0;i < 7;i++) {
		getRoadRan();
	}

	sf::Texture* tman = new sf::Texture;
	if (!tman->loadFromFile("Material/Animations/Entity/Human with clothes.png"))
		std::cout << "Human Animation not found!\n";
	Character man(tman, sf::Vector2u(8, 4), 0.1f, 100.0f, listObstacle[0]->getPosition() + sf::Vector2f(0.f,500.f));
	player = man;

	sf::Texture* tghost = new sf::Texture;
	if (!tghost->loadFromFile("Material/Animations/Entity/ghost flight.png"))
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
				dataCtrl.data->setStar(dataCtrl.data->getStar() + player.getPoint());
				if (elapsed > dataCtrl.data -> getTime()) 
					dataCtrl.data->setTime(elapsed);
				saveData();
				setRestart(1);
			}
			else if (pauseMenu.isMouseOverQuitButton(window)) // QUIT TO MENU
			{
				dataCtrl.tmp.setStar(player.getPoint());
				dataCtrl.tmp.setTime(elapsed);
				pause = false;
				GamePlayScreen::isContinue = true;
				currentScreen = ScreenState::GamePlayScreen;
				endScreen = true;
				isEndScreen = endScreen;
				
			}
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
		{
			pause = false;
		}
	}
	else if (isEndGame())
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (endMenu.isMouseOverRestartButton(window)) // RESTART
			{
				dataCtrl.data->setStar(dataCtrl.data->getStar() + player.getPoint());
				if (elapsed > dataCtrl.data->getTime()) 
					dataCtrl.data->setTime(elapsed);
				saveData();

				setRestart(1);
			}
			else if (endMenu.isMouseOverQuitButton(window)) // QUIT TO MENU
			{
				GamePlayScreen::isContinue = false;
				dataCtrl.data->setStar(dataCtrl.data->getStar() + player.getPoint());
				if (elapsed > dataCtrl.data->getTime()) dataCtrl.data->setTime(elapsed);
				saveData();
				setRestart(1);
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
			if (playing == 0  && started == 0)
			{
				playing = 1;
				started = 1;
				
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
					duration = elapsed;
				}
			}
		}
	}
}

void InGameScreen::update(sf::RenderWindow& window)
{
	if (playing == 0) TimeDisplay.restart();
	if (pause)
	{
		pauseMenu.update(window);
		TimeDisplay.restart();
	}
	else if (isEndGame())
	{
		endMenu.update(window);
	}
	else
	{
		if (playing == 0 && started == 0)
		{
			TimeDisplay.restart();
		}

		elapsed = TimeDisplay.getElapsedTime() + duration;

		int minutes = static_cast<int>(elapsed.asSeconds()) / 60;
		int seconds = static_cast<int>(elapsed.asSeconds()) % 60;
		text.setString("Time: " + std::to_string(minutes) + "m " + std::to_string(seconds) + "s");

		deltaTime = clock.restart().asSeconds();

		if (playing == 0)
		{
			player.update(deltaTime);
			for (int i = 0; i < listObstacle.size(); i++)
			{
				listObstacle[i]->beginUpdate();
			}
		}
		if (playing)
		{
			for (int i = 0; i < listObstacle.size(); i++)
			{
				listObstacle[i]->update();
			}

			player.update(deltaTime, listObstacle);

			// Stamina
			player.reduceStamina();

			//Rain effect
			myRain.update(window, player, elapsed);

			for (int i = 0; i < listObstacle.size();i++)
			{
				if (listObstacle[i]->charIsInside(player) && listObstacle[i]->isCollision(player)) {
					player.loadgetDamage(); // after intersect with the obstacle, being invisible
				}
				listObstacle[i]->isGetItem(player);
				listObstacle[i]->ObjCollision(player);
				listObstacle[i]->GiftCollision(player);
				listObstacle[i]->RiverCollision(player);
				if (listObstacle[i]->isGhostCollision() == 1) {
					Ghost = 1;
					devil.setEnd(false);
				}
			}

			//Ghost
			if (Ghost == 1) {
				if (!devil.getEnd()) {
					devil.update(deltaTime, devil.getRight(), player, elapsed);
				}
				else {
					devil.setEnd(true);
					Ghost = 0;
				}
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
	}
}

void InGameScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.clear();
		
		window.draw(this->background);

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
		if (Ghost == 1) {
			devil.drawTo(window);
		}

		if(myRain.getState())myRain.drawTo(window);

		if (!playing && player.getHp() > 0)
		{
			continueMenu.render(window);
		}
		
		if (pause)
		{
			pauseMenu.render(window);
		}
		else if (isEndGame())
		{
			endMenu.render(window);
		}
	}

}

const bool InGameScreen::isEndGame()
{
	if (player.getHp() <= 0) 
		return true;
	else 
		return false;
}
