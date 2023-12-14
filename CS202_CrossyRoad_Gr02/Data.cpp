#include "Data.h"

void Data::setName(std::string name)
{
	this->name = name;
}

void Data::setStar(int star)
{
	this->star = star;
}

void Data::setTime(sf::Time time)
{
	this->time = time;
}

//std::ostream& operator<<(std::ostream& out, const Data& other)
//{
//	out << other.name << " " << other.highscore << std::endl;
//	return out;
//}

std::string Data::getName() const
{ 
	return name; 
}

int Data::getStar() const
{
	return star;
}

sf::Time Data::getTime() const
{
	return time;
}

// Data Control

//DataControl::DataControl()
//{
//	std::ifstream fin("Data/Data.txt");
//	if (!fin.is_open())
//	{
//		std::cout << "Data not found!\n";
//		fin.close();
//	}
//	else
//	{
//		while (!fin.eof()) 
//		{
//			std::string name;
//			int highscore = 0;
//			std::getline(fin, name, ' ');
//			if (name.empty())
//				break;
//			fin >> highscore;
//			fin.ignore(1000, '\n');
//			Data* tmp = new Data(name, highscore);
//			datas.push_back(tmp);
//		}
//		fin.close();
//	}
//}
//
//DataControl::~DataControl()
//{
//	std::ofstream fout("Data/Data.txt");
//	if (!fout.is_open())
//	{
//		std::cout << "Data not found!\n";
//		fout.close();
//	}
//	else
//	{
//		for (auto dataT : datas)
//			fout << dataT->getName() << " " << dataT->getHighscore() << std::endl;
//		fout.close();
//	}
//}
