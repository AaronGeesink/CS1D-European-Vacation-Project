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
	db.setDatabaseName("C:/Users/chatm/Desktop/CS1D-European-Vacation-Project/European-Vacation-Program/resources/database.db");
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

#endif // DATABASE_H
