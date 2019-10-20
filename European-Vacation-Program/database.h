#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include "city.h"
#include <QFile>
#include <QDir>

/**
 * @author Garrett Geesink
 * @brief createDatabase()
 * Finds the SQL database file and loads it
 */
void createDatabase();

/**
 * @author Garrett Geesink
 * @brief checkConnection()
 * Checks the connection to the SQL database
 * @return bool
 */
bool checkConnection();

/**
 * @author Garrett Geesink
 * @brief Finds the SQL database file and loads it
 * @return vector<QString>
 */
std::vector<QString> queryCityNames();

/**
 * @author Aaron Geesink
 * @brief queryCityNames()
 * Queries the SQL database for the distance between a start and end city
 * @param QString start, QString end
 * @return CityDistance
 */
CityDistance queryDistance(QString start, QString end);

/**
 * @author Aaron Geesink
 * @brief queryFoods(QString cityName)
 * Queries the SQL database for a city's food.
 * @param QString cityName
 * @return vector<Food>
 */
std::vector<Food> queryFoods(QString cityName);

#endif // DATABASE_H
