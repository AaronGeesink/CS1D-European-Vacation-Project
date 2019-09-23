#include "viewwindow.h"
#include "ui_viewwindow.h"
#include "dbinit.h"

ViewWindow::ViewWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ViewWindow)
{
	ui->setupUi(this);

	// Initialize the database
	QSqlError err = dbinit();
	if (err.type() != QSqlError::NoError) {
		showError(err);
		return;
	}

	// Create the data model:
	QSqlRelationalTableModel model;
	initializeModel(&model);

}

void ViewWindow::showError(const QSqlError &err)
{
	QMessageBox::critical(this, "Unable to initialize Database",
				"Error initializing database: " + err.text());
}

ViewWindow::~ViewWindow()
{
	delete ui;
}

void ViewWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}
