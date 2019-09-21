#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <viewwindow.h>
#include <loginwindow.h>
#include <editwindow.h>
#include <tripwindow.h>
#include <cityselectwindow.h>
#include <foodselectwindow.h>
#include <resultswindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_exitButton_clicked();

	//move functions ordered by their StackedWidget index numbers
	void moveToMain();
	void on_moveToView_clicked();

	void on_moveToTrip_clicked();
	void moveToCitySelect();
	void moveToFoodSelect();
	void moveToResults();

	void on_moveToEdit_clicked();
	void moveToEdit();


private:
	Ui::MainWindow *ui;

	ViewWindow viewWind;

	LoginWindow loginWind;
	EditWindow editWind;

	TripWindow tripWind;
	CitySelectWindow citySelectWind;
	FoodSelectWindow foodSelectWind;
	ResultsWindow resultsWind;
};
#endif // MAINWINDOW_H
