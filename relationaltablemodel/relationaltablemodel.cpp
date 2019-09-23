/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtSql>

#include "../connection.h"

void initializeModel(QSqlRelationalTableModel *model)
{
	/*
//! [0]
    model->setTable("employee");
//! [0]

    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
//! [1]
    model->setRelation(2, QSqlRelation("city", "id", "name"));
//! [1] //! [2]
    model->setRelation(3, QSqlRelation("country", "id", "name"));
//! [2]

//! [3]
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("City"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Country"));
//! [3]

    model->select();
	*/

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

void createRelationalTables()
{
	/*
    QSqlQuery query;
    query.exec("create table employee(id int primary key, name varchar(20), city int, country int)");
    query.exec("insert into employee values(1, 'Espen', 5000, 47)");
    query.exec("insert into employee values(2, 'Harald', 80000, 49)");
    query.exec("insert into employee values(3, 'Sam', 100, 1)");

    query.exec("create table city(id int, name varchar(20))");
    query.exec("insert into city values(100, 'San Jose')");
    query.exec("insert into city values(5000, 'Oslo')");
    query.exec("insert into city values(80000, 'Munich')");

    query.exec("create table country(id int, name varchar(20))");
    query.exec("insert into country values(1, 'USA')");
    query.exec("insert into country values(47, 'Norway')");
	query.exec("insert into country values(49, 'Germany')");*/

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
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection())
        return EXIT_FAILURE;

    createRelationalTables();

    QSqlRelationalTableModel model;

    initializeModel(&model);

    QScopedPointer<QTableView> view(createView(QObject::tr("Relational Table Model"), &model));
    view->show();

    return app.exec();
}
