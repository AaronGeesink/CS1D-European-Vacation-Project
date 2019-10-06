#include "city.h"

City::City() : name{""}, isStart{false}
{ }

City::City(std::string name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart)
	: name{name}, otherCities{otherCities}, foods{foods}, isStart{isStart}
{ }

void City::removeCityDistance(std::string name)
{
	for (int i = 0; i < otherCities.size(); i++)
	{
		if (otherCities[i].endCity == name)
		{
			otherCities.erase(otherCities.begin() + i);
		}

	}
}
