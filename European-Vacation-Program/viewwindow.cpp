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

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from city");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadFood_clicked()
{
	QSqlQueryModel * model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from food");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadDistances_clicked()
{
	QSqlQueryModel * model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from distance");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}
