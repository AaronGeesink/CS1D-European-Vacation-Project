#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "database.h"

/**
 *@author Garrett Geesink
 *@brief Header file for the ViewWindow
 *@date October 2019
 */
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

	/**
	 * @author Garrett Geesink
	 * @brief on_loadCities_clicked()
	 * Displays the city table from the SQL database
	 */
	void on_loadCities_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_loadFood_clicked()
	 * Displays the food table from the SQL database
	 */
	void on_loadFood_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_loadDistances_clicked()
	 * Displays the distance table from the SQL database
	 */
	void on_loadDistances_clicked();

private:
	Ui::ViewWindow *ui;
	QSqlQueryModel * model;	/// A model used to display SQL tables
};

#endif // VIEWWINDOW_H
