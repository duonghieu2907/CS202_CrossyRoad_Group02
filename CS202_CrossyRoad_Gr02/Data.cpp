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
