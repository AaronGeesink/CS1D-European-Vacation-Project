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

void ViewWindow::populateCombo()
{
	QStringList cities;		/// Create QStringList (Doubly Linked List of strings)

	QSqlQuery query;
	query.exec("SELECT name FROM city WHERE active=1");

	/// Populate cities QStringList with cities from city table
	if(!query.exec())
	{
		qDebug("Failed to populate comboBox");
	}
	else
	{
	while(query.next())
		{
			cities.push_back(query.value(0).toString());
		}
	}

	for(int i = 0; i < cities.size(); ++i)
		ui->cityComboBox->addItem(cities.at(i));
}

void ViewWindow::on_loadCities_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from city");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadFood_clicked()
{
	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from food");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadDistances_clicked()
{
	model = new QSqlQueryModel;
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from distance");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadCity_clicked()
{

}
