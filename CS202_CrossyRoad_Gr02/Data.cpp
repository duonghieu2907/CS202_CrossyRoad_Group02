#include "Data.h"

void Data::setName(std::string name)
{
	this->name = name;
}

void Data::setHighscore(int highscore)
{
	this->highscore = highscore;
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

int Data::getHighscore() const 
{ 
	return highscore; 
}



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
//			fin >> highscore;
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
//		for (auto data : datas)
//			fout << data;
//		fout.close();
//	}
//}
