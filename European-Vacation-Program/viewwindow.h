#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "database.h"

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ViewWindow(QWidget *parent = nullptr);
	~ViewWindow();

private slots:

	void on_loadCities_clicked();

	void on_loadFood_clicked();

	void on_loadDistances_clicked();

private:
	Ui::ViewWindow *ui;
	QSqlQueryModel * model;
};

#endif // VIEWWINDOW_H
