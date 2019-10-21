#include "viewwindow.h"
#include "ui_viewwindow.h"

ViewWindow::ViewWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ViewWindow)
{
	ui->setupUi(this);
    ui->databaseView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
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

	query.exec("select * from city WHERE active=1");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadFood_clicked()
{
	QString city;
	city = ui->cityComboBox->currentText();

	model = new QSqlQueryModel;

	checkConnection();
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from food WHERE cityName='"+city+"'");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}

void ViewWindow::on_loadDistances_clicked()
{
	QString city;
	city = ui->cityComboBox->currentText();
	model = new QSqlQueryModel;
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from distance WHERE start='"+city+"'");
	model->setQuery(query);
	ui->databaseView->setModel(model);
}
