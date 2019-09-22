#include "tripwindow.h"
#include "ui_tripwindow.h"

TripWindow::TripWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TripWindow)
{
	ui->setupUi(this);
}

TripWindow::~TripWindow()
{
	delete ui;
}

void TripWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}

void TripWindow::on_moveTo11Cities_clicked()
{
	emit moveTo11CitiesClicked();
}

void TripWindow::on_moveToLondon_clicked()
{
	emit moveToLondonClicked();
}

void TripWindow::on_moveToCustom_clicked()
{
	emit moveToCustomClicked();
}
