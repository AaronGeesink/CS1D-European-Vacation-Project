#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include "database.h"

/**
 *@author Garrett Geesink
 *@brief Header file for the EditWindow
 *@date October 2019
 */
namespace Ui {
class EditWindow;
}

class EditWindow : public QWidget
{
	Q_OBJECT

public:
	explicit EditWindow(QWidget *parent = nullptr);
	~EditWindow();

private slots:

	/**
	 * @author Garrett Geesink
	 * @brief on_loadCities_clicked()
	 * Queries the database for the city table and displays it to the EditWindow
	 */
	void on_loadCities_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_loadFood_clicked()
	 * Queries the database for the food table and displays it to the EditWindow
	 */
	void on_loadFood_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_loadDistances_clicked()
	 * Queries the database for the distance table and displays it to the EditWindow
	 */
	void on_loadDistances_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_submitButton_clicked()
	 * Queries the database for the city table and displays it to the EditWindow
	 */
	void on_submitButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_revertButton_clicked()
	 * Reverts changes made to the database
	 */
	void on_revertButton_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_deleteFoodItem_clicked()
	 * Deletes a user-specified food item from the database
	 */
	void on_deleteFoodItem_clicked();

	/**
	 * @author Garrett Geesink
	 * @brief on_deleteFoodItem_clicked()
	 * Adds a user-specified food item
	 */
	void on_addFoodButton_clicked();

private:
	Ui::EditWindow *ui;
	QSqlTableModel * model;			/// Table Model for rendering SQL table to the window
	QSqlQueryModel * queryModel;	/// Query Model for rendering SQL table to the window
	int currentTable = 1;			/// Specifies the current loaded table
};

#endif // EDITWINDOW_H
