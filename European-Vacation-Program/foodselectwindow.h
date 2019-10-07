#ifndef FOODSELECTWINDOW_H
#define FOODSELECTWINDOW_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include <QSpinBox>
#include <QDebug>
#include "city.h"

namespace Ui {
class FoodSelectWindow;
}

class FoodSelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit FoodSelectWindow(QWidget *parent = nullptr);
	~FoodSelectWindow();

	void setFoodSelection(std::vector<City> loadedCities);
	void loadFoodQuantities();
	std::vector<City> getLoadedCities();

signals:
	void moveToCitySelectClicked();
	void moveToResultsClicked();

private slots:
	void on_moveToCitySelect_clicked();

	void on_moveToResults_clicked();

private:
	Ui::FoodSelectWindow *ui;
	std::vector<City> loadedCities;
};

#endif // FOODSELECTWINDOW_H
