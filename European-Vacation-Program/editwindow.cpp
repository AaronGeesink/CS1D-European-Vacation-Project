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

void EditWindow::on_saveButton_clicked()
{
	checkConnection();
}
