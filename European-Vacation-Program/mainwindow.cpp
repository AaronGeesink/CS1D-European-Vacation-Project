#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->stackedWidget->insertWidget(1,&viewWind);
	ui->stackedWidget->insertWidget(2,&tripWind);
	ui->stackedWidget->insertWidget(3,&citySelectWind);
	ui->stackedWidget->insertWidget(4,&foodSelectWind);
	ui->stackedWidget->insertWidget(5,&resultsWind);
	ui->stackedWidget->insertWidget(6,&loginWind);
	ui->stackedWidget->insertWidget(7,&editWind);

	connect(&viewWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
	connect(&tripWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
	this->close();
}

void MainWindow::moveToMain()
{
	//Stacked Widget index 0: Main Menu
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_moveToView_clicked()
{
	//Stacked Widget index 1: View City Info Menu
	ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_moveToTrip_clicked()
{
	//Stacked Widget index 2: Plan a Trip Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveToCitySelect()
{
	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::moveToFoodSelect()
{
	//Stacked Widget index 4: Food Select Menu
	ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::moveToResults()
{
	//Stacked Widget index 5: Trip Result Menu
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_moveToEdit_clicked()
{
	//Stacked Widget index 6: Login Menu
	ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::moveToEdit()
{
	//Stacked Widget index 7: Edit Database Menu
	ui->stackedWidget->setCurrentIndex(7);
}
