#ifndef DATA_H
#define DATA_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Data {
public:
	Data() : name(""), highscore(0) {}
	Data(std::string name, int highscore) : name(name), highscore(highscore) {}
	~Data() {}

	void setName(std::string name);
	void setHighscore(int highscore);

	//friend std::ostream& operator<<(std::ostream& out, const Data& other);

	std::string getName() const;
	int getHighscore() const;
private:
	std::string name;
	int highscore;
};

//class DataControl {
//public:
//	DataControl() {}
//	~DataControl() {}
//
//private:
//	std::vector<Data*> datas;
//};

#endif