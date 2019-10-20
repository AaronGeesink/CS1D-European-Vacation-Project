#include "editwindow.h"
#include "ui_editwindow.h"

EditWindow::EditWindow(QWidget *parent) :
	QWidget(parent), ui(new Ui::EditWindow)
{
	ui->setupUi(this);
}

EditWindow::~EditWindow()
{
	delete ui;
}

void EditWindow::loadCities()
{
	on_loadCities_clicked();
}

void EditWindow::on_loadCities_clicked()
{
	currentTable = 1;
	model = new QSqlTableModel(this);
	model->setTable("city");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();

	model->setHeaderData(0, Qt::Horizontal, tr("City Name"));
	model->setHeaderData(1, Qt::Horizontal, tr("Active"));

	ui->databaseView->verticalHeader()->setVisible(false);
	ui->databaseView->setModel(model);
}

void EditWindow::on_loadFood_clicked()
{
	currentTable = 2;

	model = new QSqlTableModel(this);
	model->setTable("food");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	model->select();
	model->setHeaderData(0, Qt::Horizontal, tr("Food ID"));
	model->setHeaderData(1, Qt::Horizontal, tr("City"));
	model->setHeaderData(2, Qt::Horizontal, tr("Food Name"));
	model->setHeaderData(3, Qt::Horizontal, tr("Price"));

	ui->databaseView->verticalHeader()->setVisible(false);
	ui->databaseView->setModel(model);
}

void EditWindow::on_loadDistances_clicked()
{
	currentTable = 1;

	QSqlQueryModel * qmodel;
	qmodel = new QSqlQueryModel;
	QSqlQuery query(QSqlDatabase::database());

	query.exec("select * from distance");
	qmodel->setQuery(query);
	ui->databaseView->setModel(qmodel);
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

void EditWindow::on_deleteFoodItem_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 2)
		{
			ui->statusLabel->setText("Error: Load Food before deleting");
		}
		else
		{
			QString foodValue;
			foodValue = ui->deleteLineEdit->text();
			QSqlQuery query(QSqlDatabase::database());
			query.prepare("DELETE FROM food WHERE foodID='"+foodValue+"'");
			if(!query.exec())
			{
				qDebug("Failed to delete");
			}
			else
			{
				ui->deleteLineEdit->setText("");
			}
			model->select();
			ui->databaseView->setModel(model);
		}
	}
}

void EditWindow::on_addFoodButton_clicked()
{
	if(checkConnection())
	{
		QSqlQuery query(QSqlDatabase::database());
		if(currentTable != 2)
		{
			ui->statusLabel->setText("Error: Load Food before adding");
		}
		else
		{
			QString cityName, foodName, foodPrice;
			cityName = ui->cityComboBox->currentText();
			foodName = ui->foodLineEdit->text();
			foodPrice = ui->priceLineEdit->text();

			bool isFloat;
			foodPrice.toFloat(&isFloat);

			if (isFloat == true)
			{
				query.prepare("INSERT INTO food VALUES(NULL,'"+cityName+"','"+foodName+"','"+foodPrice+"')");
			}
			else
			{
				ui->statusLabel->setText("Error: Not a valid price!");
			}
		}
		if(!query.exec())
		{
			qDebug("Failed to add new record");
		}
		else
		{
			ui->foodLineEdit->setText("");
			ui->priceLineEdit->setText("");
		}
		model->select();
		ui->databaseView->setModel(model);
	}
}
