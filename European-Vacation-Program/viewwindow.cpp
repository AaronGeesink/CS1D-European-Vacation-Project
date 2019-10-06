#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ViewWindow)
{
	ui->setupUi(this);
}

ViewWindow::~ViewWindow()
{
	delete ui;
}

void ViewWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}

void ViewWindow::on_loadCities_clicked()
{
	QSqlQueryModel * model = new QSqlQueryModel;

}
