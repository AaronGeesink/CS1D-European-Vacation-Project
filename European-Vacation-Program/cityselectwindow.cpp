#include "cityselectwindow.h"
#include "ui_cityselectwindow.h"

CitySelectWindow::CitySelectWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CitySelectWindow)
{
	ui->setupUi(this);
}

CitySelectWindow::~CitySelectWindow()
{
	delete ui;
}

void CitySelectWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void CitySelectWindow::on_moveToFoodSelect_clicked()
{
	emit moveToFoodSelectClicked();
}
