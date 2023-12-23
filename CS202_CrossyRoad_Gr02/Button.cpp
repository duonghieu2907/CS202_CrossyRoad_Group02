#include "Button.h"

sf::Sound Button::buttonSound;

sf::SoundBuffer Button::buttonBuff;

Button::Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor) 
{
    button.setSize(buttonSize);
    button.setFillColor(bgColor);

    // Get these for later use:
    btnWidth = buttonSize.x;
    btnHeight = buttonSize.y;
    text.setString(btnText);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);
    initButtonSound();
}

// Pass font by reference:
void Button::setFont(const sf::Font& font) 
{
    text.setFont(font);
}

void Button::setBackColor(const sf::Color &color) 
{
    button.setFillColor(color);
}

void Button::setTextColor(const sf::Color &color) 
{
    text.setFillColor(color);
}

void Button::setPosition(const sf::Vector2f &point) 
{
    button.setPosition(point);

    // Center text on button:
    //float xPos = (point.x + btnWidth / 2.0) - (text.getLocalBounds().width / 2);
    //float yPos = (point.y + btnHeight / 2.5) - (text.getLocalBounds().height / 2);

    float xPos = (point.x + btnWidth * 0.1f); // - (text.getLocalBounds().width / 2);
    float yPos = (point.y + btnHeight * 0.28f); //- (text.getLocalBounds().height / 2);
    text.setPosition(xPos, yPos);
}

void Button::setPosition(float x, float y)
{
    button.setPosition(x, y);
    float xPos = (x + btnWidth / 2) - (text.getLocalBounds().width / 2);
    float yPos = (y + btnHeight / 2.5) - (text.getLocalBounds().height / 2);
    text.setPosition(xPos, yPos);
}

void Button::setOutlineThickness(float thickness)
{
    button.setOutlineThickness(thickness);
}

void Button::setOutlineColor(const sf::Color &color)
{
    button.setOutlineColor(color);
}

void Button::setTexture(const sf::Texture *texture)
{
    button.setTexture(texture);
}

const sf::Vector2f& Button::getSize()
{
    return button.getSize();
}

void Button::drawTo(sf::RenderWindow& window) 
{
    //window.draw(button);
    window.draw(text);
}

// Check if the mouse is within the bounds of the button:
bool Button::isMouseOver(sf::RenderWindow& window) 
{
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    int btnPosX = button.getPosition().x; 
    int btnPosY = button.getPosition().y;

    int btnxPosWidth = button.getPosition().x + btnWidth;
    int btnyPosHeight = button.getPosition().y + btnHeight;

    if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
        return true;
    }
    return false;
    // This is okay, but the convert from float to int may lead to some error
    // The getPosition().x return float and then convert to int
    
    /* Change
    if (this->button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
        return true;
    }
    return false;
    */
}

void Button::update(sf::RenderWindow& window)
{
    sf::Color grey(0, 0, 0, 120);
    if (isMouseOver(window)) {
        //std::cout << 1;
		button.setOutlineColor(grey);
	}
    else {
		button.setOutlineColor(sf::Color::Transparent);
	}
}

void Button::setString(std::string text)
{
    this->text.setString(text);
}

void Button::setStyle(sf::Uint32 style)
{
    text.setStyle(style);
}

void Button::adjustSizeToContainText()
{
    button.setSize(sf::Vector2f(text.getGlobalBounds().width + 30, text.getGlobalBounds().height + 10));
    btnWidth = button.getSize().x;
    btnHeight = button.getSize().y;
    
}

void Button::initButtonSound()
{
    if (!buttonSound.getBuffer())
    {
        if (!buttonBuff.loadFromFile("Sound/button.wav"))
            std::cout << "button.wav not found!\n";
        buttonSound.setBuffer(buttonBuff);
    }
}

// ButtonCustom

ButtonCustom::ButtonCustom(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor, sf::Texture* buttonTex)
    : Button(btnText, buttonSize, charSize, bgColor, textColor), buttonTex(buttonTex)
{

}

void ButtonCustom::setBackgroundAnimation(sf::Texture* buttonTex) 
{
    this->buttonTex = buttonTex;
    buttonImg.setTexture(*this->buttonTex);
    
    uvRect.width = this->buttonTex->getSize().x / 3.0f;
    uvRect.height = this->buttonTex->getSize().y;
}

void ButtonCustom::setPosition(const sf::Vector2f& point) 
{
    Button::setPosition(point);
    buttonImg.setPosition(point);
}

void ButtonCustom::update(sf::RenderWindow& window)
{
    //Button::update(window);
    buttonImg.setTexture(*buttonTex);
    if (isMouseOver(window)) 
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            uvRect.left = uvRect.width * 2;
            uvRect.top = 0;
            buttonSound.play();
        }
        else
        {
            uvRect.left = uvRect.width;
            uvRect.top = 0;
        }
    }
    else {
        uvRect.left = 0;
        uvRect.top = 0;
    }
    buttonImg.setTextureRect(uvRect);
}

void ButtonCustom::drawTo(sf::RenderWindow& window) 
{
    //Button::drawTo(window);
    window.draw(buttonImg);
}

// AccountButton

AccountButton::AccountButton(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor,
    sf::Texture* buttonTex, std::string score, sf::Time time)
    : ButtonCustom(btnText, { buttonSize.x * 0.85f, buttonSize.y }, charSize, bgColor, textColor, buttonTex),
    remove("", { buttonSize.x * 0.15f, buttonSize.y }, charSize, bgColor, textColor, &removeTex)
{
    initBackground();
    initScore(score, charSize, textColor);
    initTime(time, charSize, textColor);
    initRemoveButton();
    initStarShape(buttonSize);
    initClockShape(buttonSize);
}

void AccountButton::initBackground()
{
    if (!starTex.loadFromFile("Material/Others/Star.png"))
        std::cout << "Star not found!\n";
    if (!clockTex.loadFromFile("Material/Others/Clock.png"))
        std::cout << "Star not found!\n";
    if (!removeTex.loadFromFile("Material/Buttons/Delete.png"))
        std::cout << "Delete not found!\n";
}

void AccountButton::initScore(std::string score, int charSize, sf::Color textColor)
{
    this->score.setString(score);
    this->score.setCharacterSize(charSize);
    this->score.setFillColor(textColor);
}

void AccountButton::initTime(sf::Time time, int charSize, sf::Color textColor)
{
    int minutes = static_cast<int>(time.asSeconds()) / 60;
    int seconds = static_cast<int>(time.asSeconds()) % 60;
    this->time.setString(std::to_string(minutes) + ":" + std::to_string(seconds));
    this->time.setCharacterSize(charSize);
    this->time.setFillColor(textColor);
}

void AccountButton::initRemoveButton()
{
    remove.setBackgroundAnimation(&removeTex);
}

void AccountButton::initStarShape(sf::Vector2f buttonSize)
{
    star.setSize({ buttonSize.y * 0.8f, buttonSize.y * 0.8f });
    star.setTexture(&starTex);
}

void AccountButton::initClockShape(sf::Vector2f buttonSize)
{
    clock.setSize({ buttonSize.y * 0.35f, buttonSize.y * 0.35f });
    clock.setTexture(&clockTex);
}

void AccountButton::setPosition(const sf::Vector2f& point)
{
    ButtonCustom::setPosition(point);
    time.setPosition({ point.x + btnWidth * 0.55f, point.y + btnHeight * 0.3f });
    clock.setPosition({ point.x + btnWidth * 0.47f, point.y + btnHeight * 0.32f });
    score.setPosition({point.x + btnWidth * 0.86f, point.y + btnHeight * 0.3f});
    star.setPosition({ point.x + btnWidth * 0.75f, point.y + btnHeight * 0.075f });
    remove.setPosition({ point.x + btnWidth, point.y });
}

void AccountButton::setFont(const sf::Font& font)
{
    Button::setFont(font);
    time.setFont(font);
    score.setFont(font);
}

void AccountButton::setTextColor(const sf::Color& color)
{
    Button::setTextColor(color);
    time.setFillColor(color);
    score.setFillColor(color);
}

void AccountButton::setScoreString(std::string score)
{
    this->score.setString(score);
}

void AccountButton::setTimeString(std::string score)
{
    this->score.setString(score);
}

// Check if the mouse is within the bounds of the remove button:
bool AccountButton::isMouseOverRemove(sf::RenderWindow& window)
{
    return remove.isMouseOver(window);
}

void AccountButton::update(sf::RenderWindow& window)
{
    //Button::update(window);
    ButtonCustom::update(window);

    remove.update(window);
}

void AccountButton::drawTo(sf::RenderWindow& window)
{
    //Button::drawTo(window);
    ButtonCustom::drawTo(window);
    Button::drawTo(window);
    remove.drawTo(window);
    window.draw(time);
    window.draw(clock);
    window.draw(score);
    window.draw(star);
}