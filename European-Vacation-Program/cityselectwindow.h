#ifndef CITYSELECTWINDOW_H
#define CITYSELECTWINDOW_H

#include <QWidget>
#include "database.h"
#include <QLabel>
#include <QString>
#include <QRadioButton>
#include <QCheckBox>
#include <QDebug>
#include "city.h"

namespace Ui {
class CitySelectWindow;
}

class CitySelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit CitySelectWindow(QWidget *parent = nullptr);
	~CitySelectWindow();

	void setCitySelection();
	std::vector<City> getLoadedCities();

signals:
	void moveToTripClicked();
	void moveToFoodSelectClicked();

private slots:
	void on_moveToTrip_clicked();
	void on_moveToFoodSelect_clicked();

private:
	Ui::CitySelectWindow *ui;
	std::vector<QString> cityNames;
	std::vector<City> loadedCities;

	void loadSelectedCities();
};

#endif // CITYSELECTWINDOW_H
