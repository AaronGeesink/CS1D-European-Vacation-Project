#ifndef CITYSELECTWINDOW_H
#define CITYSELECTWINDOW_H

#include <QWidget>
#include "database.h"
#include <QLabel>
#include <QString>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include "city.h"

/**
 *@author Aaron Geesink
 *@brief Header file for the CitySelectWindow
 *@date October 2019
 */
namespace Ui {
class CitySelectWindow;
}

class CitySelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit CitySelectWindow(QWidget *parent = nullptr);
	~CitySelectWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setCitySelection()
	 * Sets the city selection of the CitySelectWindow
	 */
	void setCitySelection();

	/**
	 * @author Aaron Geesink
	 * @brief getLoadedCities()
	 * Returns a vector containing the currently loaded cities
	 * @return vector<City>
	 */
	std::vector<City>& getLoadedCities();

	/**
	 * @author Aaron Geesink
	 * @brief getPlanNumber()
	 * Returns the value of the selected trip plan
	 * @return int
	 */
	int getPlanNumber();

	/**
	 * @author Aaron Geesink
	 * @brief setPlanNumber()
	 * Sets the value of the selected trip plan
	 * @param int number
	 */
	void setPlanNumber(int number);

	/**
	 * @author Aaron Geesink
	 * @brief getNumCities()
	 * Returns the number of cities loaded
	 * @return int
	 */
	int getNumCities();

	/**
	 * @author Aaron Geesink
	 * @brief getError()
	 * Returns at error message for contingency handling
	 * @return bool
	 */
	bool getError();

	/**
	 * @author Aaron Geesink
	 * @brief setError(bool value)
	 * Sets the error message to display
	 * @param bool value
	 */
	void setError(bool value);

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToFoodSelectClicked
	 * Proceeds to the Food Select window
	 */
	void moveToFoodSelectClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToFoodSelect_clicked()
	 * Sends a signal to proceed the the food select menu
	 */
	void on_moveToFoodSelect_clicked();

private:
	Ui::CitySelectWindow *ui;

	std::vector<QString> cityNames;		/// A vector containing the names of cities
	std::vector<City> loadedCities;		/// A vector containing the currently loaded cities
	int planNumber;						/// The plan number for the current trip
	int numCities;						/// The number of currently loaded cities
	bool error;							/// A bool for handling errors

	/**
	 * @author Aaron Geesink
	 * @brief setParisPlan()
	 * Sets the city selection to the Paris plan
	 */
	void setParisPlan();

	/**
	 * @author Aaron Geesink
	 * @brief setLondonPlan()
	 * Sets the city selection to the London plan
	 */
	void setLondonPlan();

	/**
	 * @author Aaron Geesink
	 * @brief setCustomPlan()
	 * Sets the city selection to the Custom plan
	 */
	void setCustomPlan();

	/**
	 * @author Aaron Geesink
	 * @brief loadSelectedCities(QString startingCity)
	 * loads the cities selected by the user for their trip
	 */
	void loadSelectedCities(QString startingCity);

	/**
	 * @author Aaron Geesink
	 * @brief loadParisPlan()
	 * loads the Paris plan to the city select window
	 */
	void loadParisPlan();

	/**
	 * @author Aaron Geesink
	 * @brief sortLondonCities()
	 * Sorts the cities in the london trip plan
	 */
	void sortLondonCities();

	/**
	 * @author Aaron Geesink
	 * @brief loadLondonPlan()
	 * loads the Paris plan to the city select window
	 */
	void loadLondonPlan();

	/**
	 * @author Aaron Geesink
	 * @brief loadCustomPlan()
	 * loads the Paris plan to the city select window
	 */
	void loadCustomPlan();

	/**
	 * @author Aaron Geesink
	 * @brief isValidStart(QString startingCity)
	 * Checks whether or not a city is a valid starting city
	 * @param QString startingCity
	 * @return bool
	 */
	bool isValidStart(QString startingCity);
};

#endif // CITYSELECTWINDOW_H
