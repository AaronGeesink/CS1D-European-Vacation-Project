#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EditWindow)
{
	ui->setupUi(this);
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
	currentTable = 1;
	model = new QSqlTableModel(this);
	model->setTable("city");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	model->setHeaderData(0, Qt::Horizontal, tr("City Name"));

	ui->databaseView->setModel(model);
}

void EditWindow::on_loadFood_clicked()
{
	currentTable = 2;

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
	currentTable = 3;

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
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable == 1)
		{

			query.prepare("INSERT INTO city DEFAULT VALUES ");
			//query.bindValue(":table", currentTable);
		}
		else if (currentTable == 2)
		{
			query.prepare("INSERT INTO food DEFAULT VALUES ");
		}
		else if (currentTable == 3)
		{
			query.prepare("INSERT INTO distance DEFAULT VALUES ");
		}

		if(!query.exec())
		{
			qDebug("Failed to add new record");
		}
	}
	model->select();
	ui->databaseView->setModel(model);
}
