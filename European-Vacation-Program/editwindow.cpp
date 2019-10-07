#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EditWindow)
{
	ui->setupUi(this);
	currentTable = "city";
}

EditWindow::~EditWindow()
{
	delete ui;
}

void EditWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}

void EditWindow::on_loadCities_clicked()
{
	currentTable = "city";

	model = new QSqlTableModel(this);
	model->setTable("city");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	model->setHeaderData(0, Qt::Horizontal, tr("City Name"));

	ui->databaseView->setModel(model);
}

void EditWindow::on_loadFood_clicked()
{
	currentTable = "food";

	model = new QSqlTableModel(this);
	model->setTable("food");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("City"));
	model->setHeaderData(1, Qt::Horizontal, tr("Food Name"));
	model->setHeaderData(2, Qt::Horizontal, tr("Price"));

	ui->databaseView->setModel(model);
}

void EditWindow::on_loadDistances_clicked()
{
	currentTable = "distance";

	model = new QSqlTableModel(this);
	model->setTable("distance");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("Start City"));
	model->setHeaderData(1, Qt::Horizontal, tr("End City"));
	model->setHeaderData(2, Qt::Horizontal, tr("Distance"));

	ui->databaseView->setModel(model);
}

void EditWindow::on_submitButton_clicked()
{
	model->database().transaction();
	if (model->submitAll()){
		model->database().commit();
	}
	else {
		model->database().rollback();
		qDebug("Failed to update SQL Database");
	}
}

void EditWindow::on_revertButton_clicked()
{
	model->QSqlTableModel::revertAll();
}

// This one needs some work
void EditWindow::on_addButton_clicked()
{
	if(checkConnection())
	{
		/*
		QSqlQuery query(QSqlDatabase::database());
		query.prepare("INSERT INTO (:table) DEFAULT VALUES ");
		query.bindValue(":table", currentTable);

		if(!query.exec())
		{
			qDebug("Failed to add new record");
		}
		*/
	}

	ui->databaseView->setModel(model);
}
