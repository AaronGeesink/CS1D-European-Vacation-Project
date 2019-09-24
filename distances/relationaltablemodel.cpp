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

#include "connection.h"

void initializeModel(QSqlRelationalTableModel *model)
{
	//! [0]
		model->setTable("distances");
	//! [0]

		model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	//! [1]
		//model->setRelation(2, QSqlRelation("food", "cityID", "name"));
	//! [1] //! [2]
		//model->setRelation(3, QSqlRelation("country", "id", "name"));
	//! [2]

	//! [3]
		model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
		model->setHeaderData(1, Qt::Horizontal, QObject::tr("Start"));
		model->setHeaderData(2, Qt::Horizontal, QObject::tr("End"));
		model->setHeaderData(3, Qt::Horizontal, QObject::tr("Distance"));
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
	QSqlQuery query;
	query.exec("create table distances(id int primary key, city1 varchar(20), city2 varchar(20), distance int)");
	query.exec("insert into distances values(1, 'Amsterdam', 'Berlin', 655)");
	query.exec("insert into distances values(2, 'Amsterdam', 'Brussels', 236)");
	query.exec("insert into distances values(3, 'Amsterdam', 'Budapest', 1395)");
	query.exec("insert into distances values(4, 'Amsterdam', 'Hamburg', 361)");
	query.exec("insert into distances values(5, 'Amsterdam', 'Lisbon', 2236)");
	query.exec("insert into distances values(6, 'Amsterdam', 'London', 541)");
	query.exec("insert into distances values(7, 'Amsterdam', 'Madrid', 1767)");
	query.exec("insert into distances values(8, 'Amsterdam', 'Paris', 430)");
	query.exec("insert into distances values(9, 'Amsterdam', 'Prague', 878)");
	query.exec("insert into distances values(10, 'Amsterdam', 'Rome', 1647)");
	query.exec("insert into distances values(11, 'Berlin', 'Amsterdam', 655)");
	query.exec("insert into distances values(12, 'Berlin', 'Brussels', 765)");
	query.exec("insert into distances values(13, 'Berlin', 'Budapest', 873)");
	query.exec("insert into distances values(14, 'Berlin', 'Hamburg', 288)");
	query.exec("insert into distances values(15, 'Berlin', 'Lisbon', 2779)");
	query.exec("insert into distances values(16, 'Berlin', 'London', 678)");
	query.exec("insert into distances values(17, 'Berlin', 'Madrid', 2392)");
	query.exec("insert into distances values(18, 'Berlin', 'Paris', 1054)");
	query.exec("insert into distances values(19, 'Berlin', 'Prague', 349)");
	query.exec("insert into distances values(20, 'Berlin', 'Rome', 1502)");
	query.exec("insert into distances values(21, 'Brussels', 'Amsterdam', 236)");
	query.exec("insert into distances values(22, 'Brussels', 'Berlin', 765)");
	query.exec("insert into distances values(23, 'Brussels', 'Budapest', 1353)");
	query.exec("insert into distances values(24, 'Brussels', 'Hamburg', 489)");
	query.exec("insert into distances values(25, 'Brussels', 'Lisbon', 2357)");
	query.exec("insert into distances values(26, 'Brussels', 'London', 403)");
	query.exec("insert into distances values(27, 'Brussels', 'Madrid', 1578)");
	query.exec("insert into distances values(28, 'Brussels', 'Paris', 313)");
	query.exec("insert into distances values(29, 'Brussels', 'Prague', 898)");
	query.exec("insert into distances values(30, 'Brussels', 'Rome', 1483)");
	query.exec("insert into distances values(31, 'Budapest', 'Amsterdam', 1395)");
	query.exec("insert into distances values(32, 'Budapest', 'Berlin', 873)");
	query.exec("insert into distances values(33, 'Budapest', 'Brussels', 1353)");
	query.exec("insert into distances values(34, 'Budapest', 'Hamburg', 1163)");
	query.exec("insert into distances values(35, 'Budapest', 'Lisbon', 3069)");
	query.exec("insert into distances values(36, 'Budapest', 'London', 1707)");
	query.exec("insert into distances values(37, 'Budapest', 'Madrid', 2512)");
	query.exec("insert into distances values(38, 'Budapest', 'Paris', 1485)");
	query.exec("insert into distances values(39, 'Budapest', 'Prague', 525)");
	query.exec("insert into distances values(40, 'Budapest', 'Rome', 1274)");
	query.exec("insert into distances values(41, 'Hamburg', 'Amsterdam', 361)");
	query.exec("insert into distances values(42, 'Hamburg', 'Berlin', 288)");
	query.exec("insert into distances values(43, 'Hamburg', 'Brussels', 489)");
	query.exec("insert into distances values(44, 'Hamburg', 'Budapest', 1163)");
	query.exec("insert into distances values(45, 'Hamburg', 'Lisbon', 2121)");
	query.exec("insert into distances values(46, 'Hamburg', 'London', 930)");
	query.exec("insert into distances values(47, 'Hamburg', 'Madrid', 2171)");
	query.exec("insert into distances values(48, 'Hamburg', 'Paris', 376)");
	query.exec("insert into distances values(49, 'Hamburg', 'Prague', 640)");
	query.exec("insert into distances values(50, 'Hamburg', 'Rome', 1658)");
	query.exec("insert into distances values(51, 'Lisbon', 'Amsterdam', 2236)");
	query.exec("insert into distances values(52, 'Lisbon', 'Berlin', 2779)");
	query.exec("insert into distances values(53, 'Lisbon', 'Brussels', 2357)");
	query.exec("insert into distances values(54, 'Lisbon', 'Budapest', 3069)");
	query.exec("insert into distances values(55, 'Lisbon', 'Hamburg', 2121)");
	query.exec("insert into distances values(56, 'Lisbon', 'London', 2189)");
	query.exec("insert into distances values(57, 'Lisbon', 'Madrid', 625)");
	query.exec("insert into distances values(58, 'Lisbon', 'Paris', 1736)");
	query.exec("insert into distances values(59, 'Lisbon', 'Prague', 2707)");
	query.exec("insert into distances values(60, 'Lisbon', 'Rome', 2510)");
	query.exec("insert into distances values(61, 'London', 'Amsterdam', 541)");
	query.exec("insert into distances values(62, 'London', 'Berlin', 678)");
	query.exec("insert into distances values(63, 'London', 'Brussels', 403)");
	query.exec("insert into distances values(64, 'London', 'Budapest', 1707)");
	query.exec("insert into distances values(65, 'London', 'Hamburg', 930)");
	query.exec("insert into distances values(66, 'London', 'Lisbon', 2189)");
	query.exec("insert into distances values(67, 'London', 'Madrid', 1719)");
	query.exec("insert into distances values(68, 'London', 'Paris', 464)");
	query.exec("insert into distances values(69, 'London', 'Prague', 1265)");
	query.exec("insert into distances values(70, 'London', 'Rome', 1866)");
	query.exec("insert into distances values(71, 'Madrid', 'Amsterdam', 1767)");
	query.exec("insert into distances values(72, 'Madrid', 'Berlin', 2392)");
	query.exec("insert into distances values(73, 'Madrid', 'Brussels', 1578)");
	query.exec("insert into distances values(74, 'Madrid', 'Budapest', 2512)");
	query.exec("insert into distances values(75, 'Madrid', 'Hamburg', 2171)");
	query.exec("insert into distances values(76, 'Madrid', 'Lisbon', 625)");
	query.exec("insert into distances values(77, 'Madrid', 'London', 1719)");
	query.exec("insert into distances values(78, 'Madrid', 'Paris', 1633)");
	query.exec("insert into distances values(79, 'Madrid', 'Prague', 2312)");
	query.exec("insert into distances values(80, 'Madrid', 'Rome', 1951)");
	query.exec("insert into distances values(81, 'Paris', 'Amsterdam', 430)");
	query.exec("insert into distances values(82, 'Paris', 'Berlin', 1054)");
	query.exec("insert into distances values(83, 'Paris', 'Brussels', 313)");
	query.exec("insert into distances values(84, 'Paris', 'Budapest', 1485)");
	query.exec("insert into distances values(85, 'Paris', 'Hamburg', 376)");
	query.exec("insert into distances values(86, 'Paris', 'Lisbon', 1736)");
	query.exec("insert into distances values(87, 'Paris', 'London', 464)");
	query.exec("insert into distances values(88, 'Paris', 'Madrid', 1633)");
	query.exec("insert into distances values(89, 'Paris', 'Prague', 1030)");
	query.exec("insert into distances values(90, 'Paris', 'Rome', 1442)");
	query.exec("insert into distances values(91, 'Prague', 'Amsterdam', 878)");
	query.exec("insert into distances values(92, 'Prague', 'Berlin', 349)");
	query.exec("insert into distances values(93, 'Prague', 'Brussels', 898)");
	query.exec("insert into distances values(94, 'Prague', 'Budapest', 525)");
	query.exec("insert into distances values(95, 'Prague', 'Hamburg', 640)");
	query.exec("insert into distances values(96, 'Prague', 'Lisbon', 2707)");
	query.exec("insert into distances values(97, 'Prague', 'London', 1265)");
	query.exec("insert into distances values(98, 'Prague', 'Madrid', 2312)");
	query.exec("insert into distances values(99, 'Prague', 'Paris', 1030)");
	query.exec("insert into distances values(100, 'Prague', 'Rome', 1303)");
	query.exec("insert into distances values(101, 'Rome', 'Amsterdam', 1647)");
	query.exec("insert into distances values(102, 'Rome', 'Berlin', 1502)");
	query.exec("insert into distances values(103, 'Rome', 'Brussels', 1483)");
	query.exec("insert into distances values(104, 'Rome', 'Budapest', 1274)");
	query.exec("insert into distances values(105, 'Rome', 'Hamburg', 1658)");
	query.exec("insert into distances values(106, 'Rome', 'Lisbon', 2510)");
	query.exec("insert into distances values(107, 'Rome', 'London', 1866)");
	query.exec("insert into distances values(108, 'Rome', 'Madrid', 1951)");
	query.exec("insert into distances values(109, 'Rome', 'Paris', 1442)");
	query.exec("insert into distances values(110, 'Rome', 'Prague', 1303)");


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
