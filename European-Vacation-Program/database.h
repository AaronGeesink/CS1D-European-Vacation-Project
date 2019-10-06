#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>

// Not in use
void closeConnection();

void createDatabase();

bool checkConnection();

std::vector<QString> queryCityNames();

#endif // DATABASE_H
