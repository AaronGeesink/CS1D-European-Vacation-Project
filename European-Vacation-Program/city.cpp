#include "city.h"

City::City() : name{""}, isStart{false}
{ }

City::City(QString name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart)
	: name{name}, otherCities{otherCities}, foods{foods}, isStart{isStart}
{ }

QString City::getName()
{
	return name;
}

QString City::getName() const
{
	return name;
}

void City::removeCityDistance(QString name)
{
	for (int i = 0; i < otherCities.size(); i++)
	{
		if (otherCities[i].endCity == name)
		{
			otherCities.erase(otherCities.begin() + i);
			qDebug() << name << " Deleted";
		}
	}
}

void City::sortDistances()
{
	std::sort(otherCities.begin(), otherCities.end(), std::less<CityDistance>());
	//qDebug() << otherCities[0].endCity;
}

CityDistance City::getShortestDistance() const
{
	CityDistance shortest = otherCities[0];
	for (int i = 0; i < otherCities.size(); i++)
	{
		if (otherCities[i].distance < shortest.distance)
		{
			shortest = otherCities[i];
		}
	}
	return shortest;
}

int City::getNumFoods()
{
	return foods.size();
}

bool City::getIsStart() const
{
	return isStart;
}

bool City::setIsStart(bool value)
{
	isStart = value;
}

std::vector<Food> City::getFoods()
{
	return foods;
}
