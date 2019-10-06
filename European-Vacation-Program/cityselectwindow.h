#ifndef CITYSELECTWINDOW_H
#define CITYSELECTWINDOW_H

#include <QWidget>
#include <string>
#include "dbQuery.h"
#include <QLabel>
#include <QString>
#include <QRadioButton>
#include <QCheckBox>
#include<QDebug>

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

signals:
	void moveToTripClicked();
	void moveToFoodSelectClicked();

private slots:
	void on_moveToTrip_clicked();
	void on_moveToFoodSelect_clicked();

private:
	Ui::CitySelectWindow *ui;
	std::vector<QString> cityNames;

	void selectCities();
};

#endif // CITYSELECTWINDOW_H
