#ifndef CITY_H
#define CITY_H

#include <QString>
#include <vector>
#include <QDebug>
#include "food.h"

struct CityDistance
{
	int distance;
	QString endCity;

	CityDistance(): distance{0}, endCity{""} { }

	CityDistance(int distance, QString endCity): distance{distance}, endCity{endCity} { }

	bool operator<(const CityDistance& other) const
	{
		return distance < other.distance;
	}

	bool operator!=(const CityDistance& other) const
	{
		return this->distance != other.distance;
	}
};

class City
{
public:
	City();
	City(QString name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart = false);

	QString getName();
	QString getName() const;
	int getNumFoods();
	bool getIsStart() const;
	bool setIsStart(bool value);
	std::vector<Food> getFoods();
	void removeCityDistance(QString name);
	void sortDistances();
	CityDistance getFirstDistance() const;

private:
	QString name;
	std::vector<CityDistance> otherCities;
	std::vector<Food> foods;
	bool isStart;
};


// comparator for Cities
struct CompareCity
{
	bool operator()(City const& c1, City const& c2)
	{
		if (c1.getIsStart() != c2.getIsStart())
			return c1.getIsStart() < c2.getIsStart();
		if (c1.getFirstDistance() != c2.getFirstDistance())
			return c1.getFirstDistance() < c2.getFirstDistance();
		return true;
	}
};

#endif // CITY_H
