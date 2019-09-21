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
