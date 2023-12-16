#ifndef DATA_H
#define DATA_H
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <vector>

class Data {
public:
	Data() : name(""), star(0) {}
	Data(std::string name, int star, sf::Time time) : name(name), star(star), time(time) {}
	~Data() {}

	void setName(std::string name);
	void setStar(int star);
	void setTime(sf::Time time);

	//friend std::ostream& operator<<(std::ostream& out, const Data& other);

	std::string getName() const;
	int getStar() const;
	sf::Time getTime() const;
private:
	std::string name;
	int star;
	sf::Time time;
};

struct DataControl {
	std::vector<Data*> datas;
	Data* data = nullptr;
};

//extern struct DataControl dataCtrl;

//extern DataControl dataCtrl;

//class DataControl {
//public:
//	DataControl() {}
//	~DataControl() {}
//
//private:
//	std::vector<Data*> datas;
//	Data* data;
//};

#endif