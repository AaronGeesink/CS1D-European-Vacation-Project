#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QFile>
#include <QDir>

// Not in use
void closeConnection();

void createDatabase();

bool checkConnection();

std::vector<QString> queryCityNames();

#endif // DATABASE_H
