#ifndef BUTTON_H
#define BUTTON_H
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Button {
public:
	Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor);

	virtual ~Button() {}

	// Pass font by reference:
	virtual void setFont(const sf::Font& font);

	void setBackColor(const sf::Color &color);

	virtual void setTextColor(const sf::Color &color);

	virtual void setPosition(const sf::Vector2f &point);

	void setPosition(float x, float y);

	void setOutlineThickness(float thickness);

	void setOutlineColor(const sf::Color& color);

	void setTexture(const sf::Texture *texture);

	const sf::Vector2f& getSize();

	virtual void drawTo(sf::RenderWindow& window);

	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(sf::RenderWindow& window);

	virtual void update(sf::RenderWindow& window);

	void setString(std::string text);

	void setStyle(sf::Uint32 style);

	void adjustSizeToContainText();

	static sf::Sound& getButtonSound();


protected:
	int btnWidth;
	int btnHeight;

	static sf::Sound buttonSound;
private:
	void initButtonSound();

private:
	sf::Text text;
	sf::RectangleShape button;
	static sf::SoundBuffer buttonBuff;
};

class ButtonCustom : public Button {
public:
	ButtonCustom(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor, sf::Texture* buttonTex);

	virtual ~ButtonCustom() {}

	void setBackgroundAnimation(sf::Texture* buttonTex);

	void setPosition(const sf::Vector2f& point) override;

	void update(sf::RenderWindow& window) override;

	void drawTo(sf::RenderWindow& window) override;

private:
	sf::Texture* buttonTex;
	sf::IntRect uvRect;
	sf::Sprite buttonImg;
};

class AccountButton : public ButtonCustom {
public:
	AccountButton(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor,
		sf::Texture* buttonTex, std::string score, sf::Time time);

	~AccountButton() {}

	void setPosition(const sf::Vector2f& point) override;

	void update(sf::RenderWindow& window) override;

	void drawTo(sf::RenderWindow& window) override;

	void setFont(const sf::Font& font) override;

	void setTextColor(const sf::Color& color) override;

	void setScoreString(std::string score);

	void setTimeString(std::string score);
	// Check if the mouse is within the bounds of the remove button:
	bool isMouseOverRemove(sf::RenderWindow& window);

private:
	void initBackground();
	void initScore(std::string score, int charSize, sf::Color textColor);
	void initTime(sf::Time time, int charSize, sf::Color textColor);
	void initRemoveButton();
	void initStarShape(sf::Vector2f buttonSize);
	void initClockShape(sf::Vector2f buttonSize);
private:

	sf::Text time;
	sf::Texture clockTex;
	sf::RectangleShape clock;

	sf::Text score;
	sf::Texture starTex;
	sf::RectangleShape star;

	sf::Texture removeTex;
	ButtonCustom remove;
};

#endif
