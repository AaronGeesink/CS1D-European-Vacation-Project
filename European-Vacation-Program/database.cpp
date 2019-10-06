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
	query.prepare("select * from city");

	if(!query.exec())
	{
		qDebug() << "UNABLE TO EXECUTE QUERY(1)";
	}
	while(query.next())
	{
		cityNames.push_back(query.value(0).toString());
	}
	return cityNames;
}
