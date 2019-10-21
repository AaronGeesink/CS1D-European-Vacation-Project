#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <viewwindow.h>
#include <loginwindow.h>
#include <editwindow.h>
#include <cityselectwindow.h>
#include <foodselectwindow.h>
#include <resultswindow.h>
#include "city.h"

/**
 *@author Aaron Geesink
 *@brief Header file for the MainWindow
 *@date October 2019
 */
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief LoginWindow
 * This class generates the main menu, and includes functions which control all other windows
 */
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_exitButton_clicked()
	 * Closes the program
	 */
	void on_exitButton_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_mainButton_clicked()
	 * Sends a signal to move to the mainWindow
	 */
	void on_mainButton_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToMain()
	 * Proceeds to the mainWindow
	 */
	void moveToMain();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToView_clicked()
	 * Sends a signal to move to the viewWindow
	 */
	void on_moveToView_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToCitySelect()
	 * Proceeds to the CitySelectWindow
	 */
	void moveToCitySelect();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveTo11Cities_clicked()
	 * Sends a signal to move to the 11 cities trip plan
	 */
	void on_moveTo11Cities_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToLondon_clicked()
	 * Sends a signal to move to the london trip plan
	 */
	void on_moveToLondon_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToCustom_clicked()
	 * Sends a signal to move to the custom trip plan
	 */
	void on_moveToCustom_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToFoodSelect()
	 * Proceeds to the FoodSelectWindow
	 */
	void moveToFoodSelect();

	/**
	 * @author Aaron Geesink
	 * @brief moveToResults()
	 * Proceeds to the ResultsWindow
	 */
	void moveToResults();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToEdit_clicked()
	 * Sends a signal to move to the EditWindow
	 */
	void on_moveToEdit_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToEdit()
	 * Proceeds to the EditWindow
	 */
	void moveToEdit();


private:
	Ui::MainWindow *ui;

	ViewWindow viewWind;	/// ViewWindow object
	LoginWindow loginWind;	/// LoginWindow object
	EditWindow editWind;	/// EditWindow Object
	CitySelectWindow citySelectWind;	///CitySelectWindow object
	FoodSelectWindow foodSelectWind;	///FoodSelectWindow object
	ResultsWindow resultsWind;			/// ResultsWindow object

	//std::vector<City> loadedCities;
};
#endif // MAINWINDOW_H
