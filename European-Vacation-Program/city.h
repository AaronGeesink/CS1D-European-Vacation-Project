#ifndef CITY_H
#define CITY_H

#include <QString>
#include <vector>
#include <QDebug>
#include "food.h"

/**
 *@author Aaron Geesink
 *@brief CityDistance struct
 * A struct which contains the distance from a given city to another city
 *@date October 2019
 */
struct CityDistance
{
	int distance;			/// Distance from one city to another
	QString endCity;		/// Name of the other city from the current one

	/**
	 * @brief CityDistance()
	 * Default Constructor
	 */
	CityDistance(): distance{0}, endCity{""} { }

	/**
	 * @brief CityDistance(int distance, QString endCity)
	 * Overloaded Constructor
	 */
	CityDistance(int distance, QString endCity): distance{distance}, endCity{endCity} { }

	/**
	 * @brief CityDistance::operator<()
	 * Overloaded less than comparison operator
	 * Compares the distances between two pairs of cities to determine which is shorter
	 */
	bool operator<(const CityDistance& other) const
	{
		return distance < other.distance;
	}

	/**
	 * @brief CityDistance::operator!=()
	 * Overloaded inequality operator
	 * Returns true if both city distances are not equal.
	 */
	bool operator!=(const CityDistance& other) const
	{
		return this->distance != other.distance;
	}
};

/**
 *@author Aaron Geesink
 *@brief City class
 * This is the City class used to instantiate, store, and perform calculations on cities
 *@date October 2019
 */
class City
{
public:
	/**
	 * @brief City()
	 * Default Constructor
	 */
	City();

	/**
	 * @brief City(QString name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart = false)
	 * Overloaded Constructor
	 */
	City(QString name, std::vector<CityDistance> otherCities, std::vector<Food> foods, bool isStart = false);

	/**
	 * @author Aaron Geesink
	 * @brief getName()
	 * This method returns a QString containing the name of the City
	 * @return QString
	 */
	QString getName();

	/**
	 * @author Aaron Geesink
	 * @brief getName() const
	 * Const method which returns a QString containing the name of the City
	 * @return QString
	 */
	QString getName() const;

	/**
	 * @author Aaron Geesink
	 * @brief getNumFoods()
	 * This method returns the number of foods in a City's food vector
	 * @return int
	 */
	int getNumFoods();

	/**
	 * @author Aaron Geesink
	 * @brief getNumNonZeroFoods()
	 * This method returns the quantity food in a City's food vector
	 * @return int
	 */
	int getNumNonZeroFoods();

	/**
	 * @author Aaron Geesink
	 * @brief getIsStart()
	 * Returns the value of the "isStart" data member
	 * If the city is the starting city, return true. Else, return false.
	 * @return bool
	 */
	bool getIsStart() const;

	/**
	 * @author Aaron Geesink
	 * @brief setIsStart()
	 * Sets a the value of a City's isStart data member
	 * @param bool value
	 * @return bool
	 */
	bool setIsStart(bool value);

	/**
	 * @author Aaron Geesink
	 * @brief getFoods()
	 * Returns the City's food vector to the client
	 * @return vector<food>&
	 */
	std::vector<Food>& getFoods();

	/**
	 * @author Aaron Geesink
	 * @brief removeCityDistance()
	 * Removes all distances related to the argument city from the City's distance vector
	 */
	void removeCityDistance(QString name);

	/**
	 * @author Aaron Geesink
	 * @brief getNumNonZeroFoods()
	 * This method returns a vector of food items purchased
	 * @return vector<Food>
	 */
	std::vector<Food> getNonZeroFoods();

	/**
	 * @author Aaron Geesink
	 * @brief sortDistances()
	 * Sorts the City's distance vector in order of shortest to longest distance
	 */
	void sortDistances();

	/**
	 * @author Aaron Geesink
	 * @brief getShortestDistance()
	 * Returns the distance to the closest city in the city vector
	 * @return CityDistance
	 */
	CityDistance getShortestDistance() const;

private:
	QString name;							/// Name of the city
	std::vector<CityDistance> otherCities;	/// City vector
	std::vector<Food> foods;				/// Food vector
	bool isStart;							/// Specifies if City is the starting city
};


/**
 *@author Aaron Geesink
 *@brief CompareCity struct
 * A comparator for cities
 *@date October 2019
 */
struct CompareCity
{
	/**
	 *@author Aaron Geesink
	 *@brief operator
	 * a comparator for cities
	 *@date October 2019
	 */
	bool operator()(City const& c1, City const& c2)
	{
		if (c1.getIsStart() != c2.getIsStart())
			return c1.getIsStart() < c2.getIsStart();
		if (c1.getShortestDistance() != c2.getShortestDistance())
			return c1.getShortestDistance() < c2.getShortestDistance();
		return true;
	}
};

#endif // CITY_H
