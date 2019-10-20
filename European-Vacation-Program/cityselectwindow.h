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
	std::vector<City>& getLoadedCities();

	int getPlanNumber();
	void setPlanNumber(int number);

signals:
	void moveToFoodSelectClicked();

private slots:
	void on_moveToFoodSelect_clicked();

private:
	Ui::CitySelectWindow *ui;
	std::vector<QString> cityNames;
	std::vector<City> loadedCities;
	int planNumber;

	void setParisPlan();
	void setLondonPlan();
	void setCustomPlan();

	void loadSelectedCities();
	void loadParisPlan();
	void loadLondonPlan();
	void loadCustomPlan();
};

#endif // CITYSELECTWINDOW_H
