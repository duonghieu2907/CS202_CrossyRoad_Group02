#include "LogInScreen.h"
#include "Data.h"
#include <algorithm>

LogInScreen::LogInScreen(sf::RenderWindow& window) :
	Screen(window),
	newButton("", { 350, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & newButtonTex),
	backButton("", { 170, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex),
	leftButton("", { 55, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & leftButtonTex),
	rightButton("", { 55, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & rightButtonTex),
	left(false),
	counter(0),
	addMenu(window),
	add(false),
	fullMenu(window),
	full(false),
	removeMenu(window),
	remove(false)
{
	initBackground(window);
	initNewButton();
	initBackButton();
	initLeftButton();
	initRightButton();
	checkOver5();
	initAccount();
}

void LogInScreen::initBackground(sf::RenderWindow& window)
{
	// Load main screen background from file
	if (!logInScreenTex.loadFromFile("Material/Backgrounds/LogInScreen.png"))
		std::cout << "LogInScreen not found!\n";
	logInScreenTex.setSmooth(true);

	logInScreen.setTexture(logInScreenTex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / logInScreenTex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / logInScreenTex.getSize().y;
	logInScreen.setScale(scaleX, scaleY);

	// New button
	if (!newButtonTex.loadFromFile("Material/Buttons/New.png"))
		std::cout << "New not found!\n";
	newButtonTex.setSmooth(true);

	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back.png"))
		std::cout << "Back not found!\n";
	backButtonTex.setSmooth(true);

	// Left button
	if (!leftButtonTex.loadFromFile("Material/Buttons/Left.png"))
		std::cout << "Left not found!\n";
	leftButtonTex.setSmooth(true);

	// Right button
	if (!rightButtonTex.loadFromFile("Material/Buttons/Right.png"))
		std::cout << "Right not found!\n";
	rightButtonTex.setSmooth(true);

	// Account button
	if (!accountTex.loadFromFile("Material/Buttons/Account.png"))
		std::cout << "Account not found!\n";
	accountTex.setSmooth(true);

}

void LogInScreen::initNewButton()
{
	newButton.setFont(font);
	newButton.setPosition({ 830, 615 });
	newButton.setOutlineThickness(2);
	newButton.setBackgroundAnimation(&newButtonTex);
}

void LogInScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 500, 615 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void LogInScreen::initLeftButton()
{
	leftButton.setFont(font);
	leftButton.setPosition({ 350, 320 });
	leftButton.setOutlineThickness(2);
	leftButton.setBackgroundAnimation(&leftButtonTex);
}

void LogInScreen::initRightButton()
{
	rightButton.setFont(font);
	rightButton.setPosition({ 1100, 320 });
	rightButton.setOutlineThickness(2);
	rightButton.setBackgroundAnimation(&rightButtonTex);
}

void LogInScreen::checkOver5()
{
	if (dataCtrl.datas.size() > size_t(5))
		over5Acc = true;
	else
		over5Acc = false;
}

void LogInScreen::initAccount()
{
	int i = 0;
	for (auto dataT : dataCtrl.datas)
	{
		AccountButton* tmp = new AccountButton(dataT->getName(), {612.75f, 87.625f}, 30, sf::Color::Transparent, sf::Color::Black,
			&accountTex, std::to_string(dataT->getStar()), dataT->getTime());
		tmp->setPosition({ 440.f, 100.f + i * 100.f });
		tmp->setOutlineThickness(2.f);
		tmp->setFont(font);
		tmp->setBackgroundAnimation(&accountTex);
		accounts.push_back(tmp);
		++i;
		if (i == 5) break;
	}
}


void LogInScreen::updateUI()
{
	
	for (auto account : accounts)
	{
		AccountButton* tmp = accounts.back();
		accounts.pop_back();
		delete tmp;
	}
	checkOver5();
	if (!over5Acc) left = false;
	if (left)
	{
		int i = 0;
		for (auto dataT : dataCtrl.datas)
		{
			++i;
			if (i < 6) continue;
			AccountButton* tmp = new AccountButton(dataT->getName(), { 612.75f, 92.625f }, 30, sf::Color::Transparent, sf::Color::Black,
				&accountTex, std::to_string(dataT->getStar()), dataT->getTime());
			tmp->setPosition({ 440.f, 100.f + (i - 6) * 100.f });
			tmp->setOutlineThickness(2.f);
			tmp->setFont(font);
			tmp->setBackgroundAnimation(&accountTex);
			accounts.push_back(tmp);
		}
	}
	else
	{
		int i = 0;
		for (auto dataT : dataCtrl.datas)
		{
			AccountButton* tmp = new AccountButton(dataT->getName(), { 612.75f, 92.625f }, 30, sf::Color::Transparent, sf::Color::Black,
				&accountTex, std::to_string(dataT->getStar()), dataT->getTime());
			tmp->setPosition({ 440.f, 100.f + i * 100.f });
			tmp->setOutlineThickness(2.f);
			tmp->setFont(font);
			tmp->setBackgroundAnimation(&accountTex);
			accounts.push_back(tmp);
			++i;
			if (i == 5) break;
		}
	}

}

void LogInScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (!remove && !add && !full)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			counter = 0;
			for (auto account : accounts)
			{
				if (account->isMouseOver(window))
				{
					if (left)
					{
						dataCtrl.data = dataCtrl.datas[counter + 5];

					}
					else
					{
						dataCtrl.data = dataCtrl.datas[counter];
					}
					currentScreen = ScreenState::GamePlayScreen;
					endScreen = true;
					isEndScreen = endScreen;
				}
				counter++;
			}
			counter = 0;
			for (auto account : accounts)
			{
				if (account->isMouseOverRemove(window))
				{
					if (left)
					{
						counter += 5;
						dataCtrl.data = dataCtrl.datas[counter];
					}
					else
					{
						dataCtrl.data = dataCtrl.datas[counter];
					}
					remove = true;
					break;
				}
				counter++;
			}
			if (newButton.isMouseOver(window))
			{
				if (dataCtrl.datas.size() < size_t(10))
					add = true;
				else
					full = true;
			}
			else if (backButton.isMouseOver(window))
			{
				currentScreen = ScreenState::MainScreen;
				endScreen = true;
				isEndScreen = endScreen;
			}
			else if (over5Acc && (rightButton.isMouseOver(window) || leftButton.isMouseOver(window)))
			{
				left = !left;
				updateUI();
			}
		}
	}
	else if (remove)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (removeMenu.isMouseOverConfirmButton(window))
			{
				dataCtrl.datas.erase(dataCtrl.datas.begin() + counter);
				updateUI();
				remove = false;
			}
			else if (removeMenu.isMouseOverCancelButton(window))
			{
				remove = false;
			}
		}
	}
	else if (add)
	{
		if (event.type == sf::Event::TextEntered)
		{
			addMenu.nameInputTypeOn(event);
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			if (addMenu.isMouseOverConfirmButton(window))
			{
				bool checkValid = true;
				std::string newName = addMenu.nameInputGetText();
				transform(newName.begin(), newName.end(), newName.begin(), ::toupper);
				if (newName == "")
					checkValid = false;
				if (checkValid)
				{
					for (auto data : dataCtrl.datas)
					{
						if (newName == data->getName())
						{
							checkValid = false;
							break;
						}
					}
				}
				if (checkValid)
				{
					sf::Time time;
					Data* newAccount = new Data(newName, 0, time);
					dataCtrl.datas.push_back(newAccount);
					dataCtrl.data = newAccount;
					addMenu.nameInputSetString("");
					currentScreen = ScreenState::GamePlayScreen;
					endScreen = true;
					isEndScreen = endScreen;
					add = false;
				}
			}
			else if (addMenu.isMouseOverCancelButton(window))
			{
				add = false;
			}
		}
	}
	else if (full)
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (fullMenu.isMouseOverConfirmButton(window))
			{
				full = false;
			}
		}
	}
}

void LogInScreen::update(sf::RenderWindow& window)
{
	if (updateAccount())
	{
		updateUI();
		//std::cout << "Update data\n";
		setUpdateAccount(0);
	}
	if (!isEndScreen)
	{
		if (remove)
		{
			removeMenu.update(window);
		}
		else if (add)
		{
			addMenu.update(window);
		}
		else if (full)
		{
			fullMenu.update(window);
		}
		/*else
		{
			for (auto account : accounts)
			{
				account->update(window);
			}
			newButton.update(window);
			backButton.update(window);
			if (left)
				leftButton.update(window);
			else if (over5Acc)
				rightButton.update(window);
		}*/
		for (auto account : accounts)
		{
			account->update(window);
		}
		newButton.update(window);
		backButton.update(window);
		if (left)
			leftButton.update(window);
		else if (over5Acc)
			rightButton.update(window);
	}
}

void LogInScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.draw(logInScreen);
		for (auto account : accounts)
		{
			account->drawTo(window);
		}
		newButton.drawTo(window);
		backButton.drawTo(window);
		if (left)
			leftButton.drawTo(window);
		else if (over5Acc)
			rightButton.drawTo(window);
		if (remove)
		{
			removeMenu.render(window);
		}
		else if (add)
		{
			addMenu.render(window);
		}
		else if (full)
		{
			fullMenu.render(window);
		}
	}
}