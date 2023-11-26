#include "GamePlayScreen.h"

GamePlayScreen::GamePlayScreen(sf::RenderWindow& window) :
	Screen(window),
	continueButton("", { 300, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & continueButtonTex),
	newGameButton("", { 350, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & newGameButtonTex),
	backButton("", { 170, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex)
{
	initBackground(window);
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

void GamePlayScreen::initContinueButton()
{
	continueButton.setFont(font);
	continueButton.setPosition({ 610, 300 });
	continueButton.setOutlineThickness(2);
	continueButton.setBackgroundAnimation(&continueButtonTex);
}

void GamePlayScreen::initNewGameButton()
{
	newGameButton.setFont(font);
	newGameButton.setPosition({ 590, 400 });
	newGameButton.setOutlineThickness(2);
	newGameButton.setBackgroundAnimation(&newGameButtonTex);
}

void GamePlayScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 680, 500 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void GamePlayScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (continueButton.isMouseOver(window))
		{

		}
		else if (newGameButton.isMouseOver(window))
		{
			currentScreen = ScreenState::InGameScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (backButton.isMouseOver(window))
		{
			currentScreen = ScreenState::MainScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
	}
}

void GamePlayScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
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
		continueButton.drawTo(window);
		newGameButton.drawTo(window);
		backButton.drawTo(window);
	}
}