#include "InstructtionScreen.h"

InstructionScreen::InstructionScreen(sf::RenderWindow& window) :
	Screen(window),
	backButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex),
	skipButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & skipButtonTex), 
	skipPressed(false),
	CurrentInsState(InsState::Overview),
	currentCharIndex(0), 
	textSpeed(0.05f)

{
	initBackground(window);
	initBackButton();
	initSkipButton();
}

void InstructionScreen::initBackground(sf::RenderWindow& window)
{
	// Load instruction screen background from file
	if (!instructionScreen1Tex.loadFromFile("Material/Backgrounds/InstructionScreens/InstructionScreen1.png"))
		std::cout << "InstructionScreen1 not found!\n";
	instructionScreen1Tex.setSmooth(true);
	if (!instructionScreen2Tex.loadFromFile("Material/Backgrounds/InstructionScreens/InstructionScreen2.png"))
		std::cout << "InstructionScreen1 not found!\n";
	instructionScreen2Tex.setSmooth(true);

	// Random from 2 backgounds
	srand(time(0));
	if (!(rand() % 50))
		instructionScreen.setTexture(instructionScreen2Tex);
	else
		instructionScreen.setTexture(instructionScreen1Tex);

	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / instructionScreen1Tex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / instructionScreen1Tex.getSize().y;
	instructionScreen.setScale(scaleX, scaleY);

	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back.png"))
		std::cout << "Back not found!\n";
	backButtonTex.setSmooth(true);

	// Skip button
	if (!skipButtonTex.loadFromFile("Material/Buttons/Save.png"))
		std::cout << "Skip hover not found!\n";
	skipButtonTex.setSmooth(true);

	//Instruction overview
	HeaderOverviewText.setFont(font);
	HeaderOverviewText.setCharacterSize(40);
	HeaderOverviewText.setFillColor(sf::Color::Black);
	HeaderOverviewText.setPosition(400, 220);
	HeaderOverviewText.setString("Overview");
			overviewText.setFont(font);
			overviewText.setCharacterSize(20);
			//overviewText.setFillColor(sf::Color::Black);
			//overviewText.setFillColor(sf::Color(177, 65, 46, 255)); (180,167,147,255)
			overviewText.setFillColor(sf::Color(180, 167, 147, 255));
			overviewString = "This is a brief overview of the game story...";
			overviewText.setString("");
			overviewText.setPosition(400,280);

	//Instruction howtoplay
	HeaderHowtoplayText.setFont(font);
	HeaderHowtoplayText.setCharacterSize(40);
	HeaderHowtoplayText.setFillColor(sf::Color::Black);
	HeaderHowtoplayText.setPosition(400, 220);
	HeaderHowtoplayText.setString("How to play\n\n\n\nAbout us");
		howtoplayText.setFont(font);
		howtoplayText.setCharacterSize(20);
		howtoplayText.setFillColor(sf::Color(180, 167, 147, 255));
		howtoplayText.setString("The object of the game, is to not get hit by any cars and animals. You have to\ncross the street also. Your score will be the numbers you walk forward.\nWhen you see a red light on the road, the car will stop. Be alert or the ghost\nwill fly at you, trust me, it happened to me.\n\n\n\n\nNeu cac nguoi thanh tâm muon biet, thì chung toi san long tra loi. De de phong\nthe gioi bi pha hoai, de bao ve nen hoa binh the gioi. Chung toi dai dien cho nhung\nnhan vat phan dien, day kha ai va ngay ngat long nguoi.");
		howtoplayText.setPosition(400, 280);

}

void InstructionScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 680, 600 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void InstructionScreen::initSkipButton()
{
	skipButton.setFont(font);
	skipButton.setPosition({ 1000, 150 });
	skipButton.setOutlineThickness(2);
	skipButton.setBackgroundAnimation(&skipButtonTex);
}

void InstructionScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (backButton.isMouseOver(window))
		{
			currentScreen = ScreenState::MainScreen;
			endScreen = true;
			isEndScreen = endScreen;
			CurrentInsState = InsState::Overview;
			overviewText.setString("");
			currentCharIndex = 0;
		}
		else if (skipButton.isMouseOver(window))
		{
			skipPressed = true;
		}
	}
}

void InstructionScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		backButton.update(window);
		skipButton.update(window);
		if (skipPressed)
		{
			CurrentInsState = InsState::Howtoplay_AboutUs;
			skipPressed = false;  
		}
		else if (CurrentInsState == InsState::Overview && currentCharIndex < overviewString.size())
			{
				//Check time between chars
				if (textClock.getElapsedTime().asSeconds() >= textSpeed)
				{
					// Display a char
					overviewText.setString(overviewText.getString() + overviewString[currentCharIndex]);
					currentCharIndex++;

					// Restart clock
					textClock.restart();
				}
			}
	}
	else
	{

	}
}

void InstructionScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.draw(instructionScreen);
		backButton.drawTo(window);
		if (CurrentInsState == InsState::Overview)
		{
			window.draw(overviewText);
			window.draw(HeaderOverviewText);
		}
		else if (CurrentInsState == InsState::Howtoplay_AboutUs)
		{
			window.draw(HeaderHowtoplayText);
			window.draw(howtoplayText);
		}

		backButton.drawTo(window);

		if (CurrentInsState == InsState::Overview)
			skipButton.drawTo(window);
	}
}

