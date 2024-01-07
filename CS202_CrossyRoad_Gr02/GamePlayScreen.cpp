#include "GamePlayScreen.h"

bool GamePlayScreen::isContinue = false;

GamePlayScreen::GamePlayScreen(sf::RenderWindow& window) :
	Screen(window),
	isViewInfo(false),
	infoMenu(window),
	infoButton("", { 150, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & infoButtonTex),
	continueButton("", { 300, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & continueButtonTex),
	newGameButton("", { 350, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & newGameButtonTex),
	backButton("", { 170, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex)
{
	initBackground(window);
	initUsername();
	initDiscontinue();
	initInfoButton();
	initContinueButton();
	initNewGameButton();
	initBackButton();
}

void GamePlayScreen::initBackground(sf::RenderWindow& window)
{
	// Load main screen background from file
	if (!gamePlayScreen1Tex.loadFromFile("Material/Backgrounds/GamePlayScreens/GamePlayScreen1.png"))
		std::cout << "GamePlayScreen1 not found!\n";
	gamePlayScreen1Tex.setSmooth(true);
	if (!gamePlayScreen2Tex.loadFromFile("Material/Backgrounds/GamePlayScreens/GamePlayScreen2.png"))
		std::cout << "GamePlayScreen2 not found!\n";
	gamePlayScreen2Tex.setSmooth(true);
	// Random from 2 backgrounds
	srand(time(0));
	if (!(rand() % 50))
		gamePlayScreen.setTexture(gamePlayScreen2Tex);
	else
		gamePlayScreen.setTexture(gamePlayScreen1Tex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / gamePlayScreen1Tex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / gamePlayScreen1Tex.getSize().y;
	gamePlayScreen.setScale(scaleX, scaleY);

	// Discontinue button
	if (!discontinueTex.loadFromFile("Material/Buttons/Discontinue.png"))
		std::cout << "Discontinue not found!\n";
	discontinueTex.setSmooth(true);

	// Info button
	if (!infoButtonTex.loadFromFile("Material/Buttons/Info.png"))
		std::cout << "Info not found!\n";
	infoButtonTex.setSmooth(true);

	// Continue button
	if (!continueButtonTex.loadFromFile("Material/Buttons/Continue.png"))
		std::cout << "Continue not found!\n";
	continueButtonTex.setSmooth(true);

	// New game button
	if (!newGameButtonTex.loadFromFile("Material/Buttons/New Game.png"))
		std::cout << "New Game not found!\n";
	newGameButtonTex.setSmooth(true);

	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back.png"))
		std::cout << "Back not found!\n";
	backButtonTex.setSmooth(true);

}

void GamePlayScreen::initUsername()
{
	username.setFont(font);
	username.setCharacterSize(80);
	username.setFillColor(sf::Color::Black);
}

void GamePlayScreen::initDiscontinue()
{
	discontinue.setSize({ 300.f, 55.f });
	discontinue.setPosition({ 610, 320 });
	discontinue.setTexture(&discontinueTex);
}

void GamePlayScreen::initInfoButton()
{
	infoButton.setFont(font);
	infoButton.setPosition({ 700, 520 });
	infoButton.setOutlineThickness(2);
	infoButton.setBackgroundAnimation(&infoButtonTex);
}

void GamePlayScreen::initContinueButton()
{
	continueButton.setFont(font);
	continueButton.setPosition({ 610, 320 });
	continueButton.setOutlineThickness(2);
	continueButton.setBackgroundAnimation(&continueButtonTex);
}

void GamePlayScreen::initNewGameButton()
{
	newGameButton.setFont(font);
	newGameButton.setPosition({ 590, 420 });
	newGameButton.setOutlineThickness(2);
	newGameButton.setBackgroundAnimation(&newGameButtonTex);
}

void GamePlayScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 680, 620 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void GamePlayScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (infoButton.isMouseOver(window))
	{
		isViewInfo = true;
		infoMenu.setTime();
		infoMenu.setStar();
	}
	else
		isViewInfo = false;

	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (isContinue && continueButton.isMouseOver(window))
		{
			currentScreen = ScreenState::InGameScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (newGameButton.isMouseOver(window))
		{
			currentScreen = ScreenState::InGameScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (backButton.isMouseOver(window))
		{
			if (isContinue)
			{
				if (dataCtrl.tmp.getTime() > dataCtrl.data->getTime())
					dataCtrl.data->setTime(dataCtrl.tmp.getTime());
				dataCtrl.data->setStar(dataCtrl.data->getStar() + dataCtrl.tmp.getStar());
				isContinue = false;
				setRestart(true);
				
			}
			setUpdateAccount(1);
			currentScreen = ScreenState::LogInScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
	}
}

void GamePlayScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		if (dataCtrl.data)
		{
			username.setString("Welcome, " + dataCtrl.data->getName() + "!");
			username.setPosition({ 720.f - username.getGlobalBounds().width / 2.2f, 160.f});
		}
		else
		{
		}
		if (isContinue)
			continueButton.update(window);
		
		infoButton.update(window);
		newGameButton.update(window);
		backButton.update(window);
	}
}

void GamePlayScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.draw(gamePlayScreen);
		window.draw(username);
		if (isContinue)
			continueButton.drawTo(window);
		else
			window.draw(discontinue);
		infoButton.drawTo(window);
		newGameButton.drawTo(window);
		backButton.drawTo(window);
		if (isViewInfo)
			infoMenu.render(window);
	}
}