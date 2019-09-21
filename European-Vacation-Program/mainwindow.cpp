#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->stackedWidget->insertWidget(1,&ViewWind);

	connect(&ViewWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
	this->close();
}

void MainWindow::on_moveToView_clicked()
{
	ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::moveToMain()
{
	ui->stackedWidget->setCurrentIndex(0);
}
