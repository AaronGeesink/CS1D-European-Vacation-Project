#include "database.h"


void closeConnection()
{
	QSqlDatabase db = QSqlDatabase::database();
	db.close();
	QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

void createDatabase()
{
	QSqlDatabase::addDatabase("QSQLITE");
	QSqlDatabase db;
	db = QSqlDatabase::database();
	// Load database from file
	const QString DB_PATH = QDir::currentPath() + "/resources/database.db";
	db.setDatabaseName(DB_PATH);}

bool checkConnection()
{
	// Initialize a new QSQLite database
	QSqlDatabase db;
	db = QSqlDatabase::database();

	// Check if database loaded
	if(!db.open())
	{
		qDebug("Failed to load SQL Database");
		return false;
	}
	else
	{
		qDebug("Connected to SQL database");
		return true;
	}
}

std::vector<QString> queryCityNames()
{
	std::vector<QString> cityNames;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());
	query.prepare("SELECT * FROM city");

	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		cityNames.push_back(query.value(0).toString());
	}
	return cityNames;
}



CityDistance queryDistance(QString start, QString end)
{
	QSqlQuery query;
	int distance = 0;
	CityDistance cityDistance;

	query.prepare("SELECT distance FROM distance WHERE start = :start and end = :end");
	query.bindValue(":start", start);
	query.bindValue(":end", end);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		distance = query.value(0).toInt();
		cityDistance.distance = distance;
		cityDistance.endCity = end;
	}
	return cityDistance;
}

std::vector<Food> queryFoods(QString cityName)
{
	std::vector<Food> foods;
	std::vector<QString> foodNames;
	std::vector<float> foodPrices;

	QSqlQuery query;

// Query the food names for the city
	query.prepare("SELECT foodName FROM food WHERE cityName = :cityName");
	query.bindValue(":cityName", cityName);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		foodNames.push_back(query.value(0).toString());
	}

// Query the food prices for the city
	query.prepare("SELECT price FROM food WHERE cityName = :cityName");
	query.bindValue(":cityName", cityName);
	if(!query.exec())
	{
		qDebug() << "Failed to query from SQL Database";
	}
	while(query.next())
	{
		foodPrices.push_back(query.value(0).toDouble());
	}

	for (int i = 0; i < foodNames.size(); i++)
	{
		Food food(foodNames[i], foodPrices[i]);
		foods.push_back(food);
	}

	return foods;
}
