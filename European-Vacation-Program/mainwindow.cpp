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

	connect(&tripWind, SIGNAL(moveTo11CitiesClicked()), this, SLOT(moveTo11Cities()));
	connect(&tripWind, SIGNAL(moveToLondonClicked()), this, SLOT(moveToLondon()));
	connect(&tripWind, SIGNAL(moveToCustomClicked()), this, SLOT(moveToCustom()));

	connect(&citySelectWind, SIGNAL(moveToFoodSelectClicked()), this, SLOT(moveToFoodSelect()));
	connect(&citySelectWind, SIGNAL(moveToTripClicked()), this, SLOT(moveToTrip()));

	connect(&foodSelectWind, SIGNAL(moveToResultsClicked()), this, SLOT(moveToResults()));
	connect(&foodSelectWind, SIGNAL(moveToCitySelectClicked()), this, SLOT(moveToCitySelect()));

	connect(&resultsWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
	connect(&resultsWind, SIGNAL(moveToTripClicked()), this, SLOT(moveToTrip()));

	connect(&loginWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
	connect(&loginWind, SIGNAL(moveToEditClicked()), this, SLOT(moveToEdit()));

	connect(&editWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));

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

void MainWindow::moveToTrip()
{
	//Stacked Widget index 2: Plan a Trip Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveTo11Cities()
{
	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(3);
	citySelectWind.setCitySelection();
}

void MainWindow::moveToLondon()
{
	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(3);
	citySelectWind.setCitySelection();
}

void MainWindow::moveToCustom()
{
	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(3);
	citySelectWind.setCitySelection();
}

// TODO: Replace or modify moveToCitySelect to go back to the desired trip plan
// can do this either by using an tripID integer in one function of my using 3 seperate functions
void MainWindow::moveToCitySelect()
{
	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(3);
	citySelectWind.setCitySelection();
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
