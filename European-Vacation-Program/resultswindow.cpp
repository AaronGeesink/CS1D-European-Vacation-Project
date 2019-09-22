#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ResultsWindow)
{
	ui->setupUi(this);
}

ResultsWindow::~ResultsWindow()
{
	delete ui;
}

void ResultsWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void ResultsWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}
