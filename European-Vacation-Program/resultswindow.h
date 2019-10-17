#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QWidget>
#include <vector>
#include <queue>
#include <QLabel>
#include "City.h"

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ResultsWindow(QWidget *parent = nullptr);
	~ResultsWindow();

	void setResults(std::vector<City>& loadedCities);

	City getClosestCity(std::vector<City> loadedCities, QString name);

signals:
	void moveToTripClicked();
	void moveToMainClicked();

private slots:
	void on_moveToTrip_clicked();

	void on_moveToMain_clicked();

private:
	Ui::ResultsWindow *ui;
};

#endif // RESULTSWINDOW_H
