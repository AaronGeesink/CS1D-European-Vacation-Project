#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LoginWindow)
{
	ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
	delete ui;
}

void LoginWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}

void LoginWindow::on_moveToEdit_clicked()
{
	emit moveToEditClicked();
}
