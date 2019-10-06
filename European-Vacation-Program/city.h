#ifndef CITY_H
#define CITY_H
#include <string>
#include <vector>
#include "food.h"

struct CityDistance
{
	int distance;
	std::string endCity;

	bool operator<(const CityDistance& other)
	{
		return distance < other.distance;
	}
};


class City
{
public:
	City();
	City(std::string name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart = false);
	void removeCityDistance(std::string name);

private:
	std::string name;
	std::vector<CityDistance> otherCities;
	std::vector<Food> foods;
	bool isStart;
};

#endif // CITY_H
