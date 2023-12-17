#include "GamePlayScreen.h"

bool GamePlayScreen::isContinue = false;

GamePlayScreen::GamePlayScreen(sf::RenderWindow& window) :
	Screen(window),
	continueButton("", { 300, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & continueButtonTex),
	newGameButton("", { 350, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & newGameButtonTex),
	backButton("", { 170, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex)
{
	initBackground(window);
	initUsername();
	initDiscontinue();
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
	discontinue.setPosition({ 610, 350 });
	discontinue.setTexture(&discontinueTex);
}

void GamePlayScreen::initContinueButton()
{
	continueButton.setFont(font);
	continueButton.setPosition({ 610, 350 });
	continueButton.setOutlineThickness(2);
	continueButton.setBackgroundAnimation(&continueButtonTex);
}

void GamePlayScreen::initNewGameButton()
{
	newGameButton.setFont(font);
	newGameButton.setPosition({ 590, 450 });
	newGameButton.setOutlineThickness(2);
	newGameButton.setBackgroundAnimation(&newGameButtonTex);
}

void GamePlayScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 680, 550 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void GamePlayScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
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
			//std::cout << "data is null\n";
		}
		if (isContinue)
			continueButton.update(window);
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
		newGameButton.drawTo(window);
		backButton.drawTo(window);
	}
}