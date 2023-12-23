#ifndef INSTRUCTIONSCREEN_H
#define INSTRUCTIONSCREEN_H

#include "Screen.h"

class InstructionScreen :public Screen
{
public:
	InstructionScreen(sf::RenderWindow& window);
	~InstructionScreen() {};

public:
	void handleEvent(sf::Event event, sf::RenderWindow& Window, ScreenState& currentScreen, bool& endScreen);
	void update(sf::RenderWindow& window) override;
	void render(sf::RenderWindow& window) override;


private:
	void initBackground(sf::RenderWindow& window);
	void initBackButton();
	void initSkipButton();

	enum InsState
	{
		Overview,
		Howtoplay_AboutUs
	};

	InsState CurrentInsState;



private:
	sf::Texture instructionScreen1Tex;
	sf::Texture instructionScreen2Tex;
	sf::Sprite instructionScreen;

	sf::Texture backButtonTex;
	ButtonCustom backButton;

	sf::Texture skipButtonTex;
	ButtonCustom skipButton;

	sf::Text overviewText;
	sf::Text howtoplayText;

	sf::Text HeaderOverviewText;
	sf::Text HeaderHowtoplayText;

	bool skipPressed;

	std::string overviewString;  
	std::size_t currentCharIndex;  
	sf::Clock textClock;  
	float textSpeed;
};

#endif