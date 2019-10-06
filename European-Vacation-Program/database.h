#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

// Not in use
inline void closeConnection()
{
	QSqlDatabase db = QSqlDatabase::database();
	db.close();
	QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

inline void createDatabase()
{
	QSqlDatabase::addDatabase("QSQLITE");
	QSqlDatabase db;
	db = QSqlDatabase::database();
	// Load database from file
	db.setDatabaseName("C:/Users/roverdog/Desktop/CS1D-European-Vacation-Project/European-Vacation-Program/resources/database.db");
}


inline bool checkConnection()
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
	QSqlQuery query;
	query.prepare("SELECT * "
				  "FROM Cities "
				  "ORDER  BY City ASC");
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

#endif // DATABASE_H
