#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <vector>
#include <queue>
#include <QLabel>
#include "city.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ResultsWindow(QWidget *parent = nullptr);
	~ResultsWindow();

	void setResults(std::vector<City>& loadedCities, int numCities);

	City getClosestCity(std::vector<City> loadedCities, QString name);
	City getStartingCity(std::vector<City> loadedCities);

signals:
	void moveToMainClicked();
	void moveToFoodSelectClicked();

private slots:
	void on_moveToMain_clicked();

	void on_moveToFoodSelect_clicked();

private:
	Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
