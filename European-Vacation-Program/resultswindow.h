#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <vector>
#include <queue>
#include <QLabel>
#include "city.h"

/**
 *@author Aaron Geesink
 *@brief Header file for the ResultsWindow
 *@date October 2019
 */
namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ResultsWindow(QWidget *parent = nullptr);
	~ResultsWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setResults(std::vector<City>& loadedCities, int numCities)
	 * Sets the results screen to the currently loaded cities
	 * @param vector<city>& loadedCities
	 */
	void setResults(std::vector<City>& loadedCities, int numCities);


	/**
	 * @author Aaron Geesink
	 * @brief getClosestCity(std::vector<City> loadedCities, QString name)
	 * Returns the closest city to the current city
	 * @param vector<city>& loadedCities, QString name
	 */
	City getClosestCity(std::vector<City> loadedCities, QString name);

	/**
	 * @author Aaron Geesink
	 * @brief getStartingCity(std::vector<City> loadedCities)
	 * Returns the starting city of a trip
	 * @param vector<city>& loadedCities
	 */
	City getStartingCity(std::vector<City> loadedCities);

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToMainClicked()
	 * Proceeds to the MainWindow
	 */
	void moveToMainClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToFoodSelectClicked()
	 * Proceeds to the FoodSelectWindow
	 */
	void moveToFoodSelectClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToMain_clicked()
	 * Sends a signal to move to the MainWindow
	 */
	void on_moveToMain_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToFoodSelect_clicked()
	 * Sends a signal to move to the FoodSelectWindow
	 */
	void on_moveToFoodSelect_clicked();

private:
	Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
