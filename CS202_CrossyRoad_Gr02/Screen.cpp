#include <iomanip>
#include "Screen.h"
#include "MainScreen.h"
#include "LogInScreen.h"
#include "SettingScreen.h"
#include "GamePlayScreen.h"
#include "InGameScreen.h"

ScreenControl::ScreenControl(sf::RenderWindow& window)
{
	Screen* tmp;
	tmp = new MainScreen(window);
	screens.push_back(tmp);
	tmp = new LogInScreen(window);
	screens.push_back(tmp);
	tmp = new SettingScreen(window);
	screens.push_back(tmp);
	tmp = new GamePlayScreen(window);
	screens.push_back(tmp);
	tmp = new InGameScreen(window);
	screens.push_back(tmp);
}

ScreenControl::~ScreenControl()
{
	for (auto screen : screens) delete screen;
	screens.clear();
}

Screen* ScreenControl::getScreen(ScreenState state) 
{
	switch (state) {
	case ScreenState::MainScreen:
		return screens[0];
	case ScreenState::LogInScreen:
		return screens[1];
	case ScreenState::SettingScreen:
		return screens[2];
	case ScreenState::GamePlayScreen:
		return screens[3];
	case ScreenState::InGameScreen:
		return screens[4];
	}
}

// SCREEN

DataControl Screen::dataCtrl;

Screen::Screen(sf::RenderWindow& window) : isEndScreen(false)
{ 
	dataCtrl.data = nullptr;
	initFont(); 
	initData();
	window.setFramerateLimit(120);
}

void Screen::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/HIEN KHANH 3.ttf"))
		std::cout << "Font not found!\n";
}

void Screen::initData()
{
	if (dataCtrl.datas.empty())
	{
		std::ifstream fin("Data/Data.txt");
		if (!fin.is_open())
		{
			std::cout << "Data not found!\n";
			fin.close();
		}
		else
		{
			while (!fin.eof())
			{
				std::string name;
				sf::Time time;
				std::getline(fin, name, ' ');
				if (name == "")
					break;
				float second = 0.f;
				fin >> second;
				time = sf::seconds(second);
				int star = 0;
				fin >> star;
				fin.ignore(1000, '\n');
				Data* tmp = new Data(name, star, time);
				dataCtrl.datas.push_back(tmp);
			}
			fin.close();
		}
	}
}

void Screen::saveData()
{
	std::ofstream fout("Data/DataSave.txt");
	if (!fout.is_open())
	{
		std::cout << "DataSave not found!\n";
		fout.close();
	}
	else
	{
		for (auto dataT : dataCtrl.datas)
			fout << dataT->getName() << " " << std::setprecision(0) << std::fixed << dataT->getTime().asSeconds() << " " << dataT->getStar() << std::endl;
		fout.close();
	}
}