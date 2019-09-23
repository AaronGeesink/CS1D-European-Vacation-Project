#ifndef DBINIT_H
#define DBINIT_H

#include <QtWidgets>
#include <QtSql>

//#include "../connection.h"

void initializeModel(QSqlRelationalTableModel *model)
{
	//! [0]
		model->setTable("city");
	//! [0]

		model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//! [1]
		model->setRelation(2, QSqlRelation("food", "cityID", "name"));
	//! [1] //! [2]
		//model->setRelation(3, QSqlRelation("country", "id", "name"));
	//! [2]

	//! [3]
		model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
		model->setHeaderData(1, Qt::Horizontal, QObject::tr("City"));
		model->setHeaderData(2, Qt::Horizontal, QObject::tr("Food"));
		//model->setHeaderData(3, Qt::Horizontal, QObject::tr("Distance"));
	//! [3]

		model->select();
}

QTableView *createView(const QString &title, QSqlTableModel *model)
{
//! [4]
	QTableView *view = new QTableView;
	view->setModel(model);
	view->setItemDelegate(new QSqlRelationalDelegate(view));
//! [4]
	view->setWindowTitle(title);
	return view;
}

QSqlError dbinit()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(":memory:");

	if (!db.open())
		return db.lastError();

	QSqlQuery query;
	query.exec("create table city(cityID int primary key, city varchar(20), food int)");
	query.exec("insert into city values(1, 'Amsterdam', 1)");
	query.exec("insert into city values(2, 'Berlin', 2)");
	query.exec("insert into city values(3, 'Brussels', 3)");
	query.exec("insert into city values(4, 'Budapest', 4)");
	query.exec("insert into city values(5, 'Hamburg', 5)");
	query.exec("insert into city values(6, 'Lisbon', 6)");
	query.exec("insert into city values(7, 'London', 7)");
	query.exec("insert into city values(8, 'Madrid', 8)");
	query.exec("insert into city values(9, 'Paris', 9)");
	query.exec("insert into city values(10, 'Prague', 10)");
	query.exec("insert into city values(11, 'Rome', 11)");

	query.exec("create table food(foodID int primary key, name varchar(20), cityID int)");
	query.exec("insert into food values(1, 'Hagelslag toast', 1)");
	query.exec("insert into food values(2, 'Stroopwaffles', 1)");
	query.exec("insert into food values(3, 'Sausage', 2)");
	query.exec("insert into food values(4, 'Saurkraut', 2)");
	query.exec("insert into food values(5, 'Mussels', 3)");
	query.exec("insert into food values(6, 'Eel', 3)");
	query.exec("insert into food values(7, 'Goulash', 4)");
	query.exec("insert into food values(8, 'Paprikash', 4)");
	query.exec("insert into food values(9, 'Fish Sandwich', 5)");
	query.exec("insert into food values(10, 'Knackwurst', 5)");
	query.exec("insert into food values(11, 'Petiscos', 6)");
	query.exec("insert into food values(12, 'Sardines', 6)");
	query.exec("insert into food values(13, 'Fish and Chips', 7)");
	query.exec("insert into food values(14, 'Scone', 7)");
	query.exec("insert into food values(15, 'Chickpea Stew', 8)");
	query.exec("insert into food values(16, 'Churros', 8)");
	query.exec("insert into food values(17, 'Baguette', 9)");
	query.exec("insert into food values(18, 'Wine', 9)");
	query.exec("insert into food values(19, 'Duck', 10)");
	query.exec("insert into food values(20, 'Schnitzel', 10)");
	query.exec("insert into food values(21, 'Pita Bread', 11)");
	query.exec("insert into food values(22, 'Gyro', 11)");

	return QSqlError();

}


#endif
