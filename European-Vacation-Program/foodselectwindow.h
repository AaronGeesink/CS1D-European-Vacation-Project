#ifndef FOODSELECTWINDOW_H
#define FOODSELECTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QSpinBox>
#include <QDebug>
#include "city.h"

/**
 *@author Aaron Geesink
 *@brief Header file for the FoodSelectWindow
 *@date October 2019
 */
namespace Ui {
class FoodSelectWindow;
}

/**
 * @brief LoginWindow
 * This class generates the window which allows the user to select food to purchase
 */
class FoodSelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit FoodSelectWindow(QWidget *parent = nullptr);
	~FoodSelectWindow();

	/**
	 * @author Aaron Geesink
	 * @brief setFoodSelection(std::vector<City>& loadedCities)
	 * Sets the food selection of the CitySelectWindow
	 * @param vector<city>& loadedCities
	 */
	void setFoodSelection(std::vector<City>& loadedCities);

	/**
	 * @author Aaron Geesink
	 * @brief loadFoodQuantities()
	 * Loads the quantities of food on the CitySelectWindow
	 */
	void loadFoodQuantities();

	/**
	 * @author Aaron Geesink
	 * @brief getLoadedCities()
	 * Returns a vector containing the currently loaded cities
	 * @return vector<City>
	 */
	std::vector<City>& getLoadedCities();

signals:
	/**
	 * @author Aaron Geesink
	 * @brief moveToCitySelectClicked()
	 * Proceeds to the city select window
	 */
	void moveToCitySelectClicked();

	/**
	 * @author Aaron Geesink
	 * @brief moveToResultsClicked()
	 * Proceeds to the city results window
	 */
	void moveToResultsClicked();

private slots:
	/**
	 * @author Aaron Geesink
	 * @brief on_moveToCitySelect_clicked()
	 * Triggers a signal to move to the CitySelect menu
	 */
	void on_moveToCitySelect_clicked();

	/**
	 * @author Aaron Geesink
	 * @brief on_moveToResults_clicked()
	 * Triggers a signal to move to the Results menu
	 */
	void on_moveToResults_clicked();

private:
	Ui::FoodSelectWindow *ui;
	std::vector<City>* loadedCities;	/// A vector containing the currently loaded cities
};

#endif // FOODSELECTWINDOW_H
