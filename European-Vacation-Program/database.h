#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include "city.h"
#include <QFile>
#include <QDir>

// Not in use
void closeConnection();

void createDatabase();

bool checkConnection();

std::vector<QString> queryCityNames();

CityDistance queryDistance(QString start, QString end);

std::vector<Food> queryFoods(QString cityName);

#endif // DATABASE_H
