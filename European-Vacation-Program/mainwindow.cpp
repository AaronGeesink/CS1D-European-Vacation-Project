#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->stackedWidget->insertWidget(1,&viewWind);
	ui->stackedWidget->insertWidget(2,&citySelectWind);
	ui->stackedWidget->insertWidget(3,&foodSelectWind);
	ui->stackedWidget->insertWidget(4,&resultsWind);
	ui->stackedWidget->insertWidget(5,&loginWind);
	ui->stackedWidget->insertWidget(6,&editWind);

	connect(&citySelectWind, SIGNAL(moveToFoodSelectClicked()), this, SLOT(moveToFoodSelect()));
	connect(&citySelectWind, SIGNAL(moveToTripClicked()), this, SLOT(moveToTrip()));

	connect(&foodSelectWind, SIGNAL(moveToResultsClicked()), this, SLOT(moveToResults()));
	connect(&foodSelectWind, SIGNAL(moveToCitySelectClicked()), this, SLOT(moveToCitySelect()));

	connect(&resultsWind, SIGNAL(moveToMainClicked()), this, SLOT(moveToMain()));
	connect(&resultsWind, SIGNAL(moveToFoodSelectClicked()), this, SLOT(moveToFoodSelect()));

	connect(&loginWind, SIGNAL(moveToEditClicked()), this, SLOT(moveToEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exitButton_clicked()
{
	this->close();
}

void MainWindow::on_mainButton_clicked()
{
	//Stacked Widget index 0: Main Menu
	ui->stackedWidget->setCurrentIndex(0);
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

// TODO: Replace or modify moveToCitySelect to go back to the desired trip plan
// can do this either by using an tripID integer in one function or using 3 seperate functions
void MainWindow::moveToCitySelect()
{
	citySelectWind.setCitySelection();

	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_moveTo11Cities_clicked()
{
	//Plan number 0 = Paris Plan
	citySelectWind.setPlanNumber(0);
	citySelectWind.setCitySelection();

	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_moveToLondon_clicked()
{
	//Plan number 1 = London Plan
	citySelectWind.setPlanNumber(1);
	citySelectWind.setCitySelection();

	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_moveToCustom_clicked()
{
	//Plan number 1 = Custom Plan
	citySelectWind.setPlanNumber(2);
	citySelectWind.setCitySelection();

	//Stacked Widget index 3: City Select Menu
	ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveToFoodSelect()
{
	foodSelectWind.setFoodSelection(citySelectWind.getLoadedCities());

	//Stacked Widget index 4: Food Select Menu
	ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::moveToResults()
{
	resultsWind.setResults(foodSelectWind.getLoadedCities(), citySelectWind.getNumCities());
	//Stacked Widget index 5: Trip Result Menu
	ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_moveToEdit_clicked()
{
	editWind.loadCities();
	//Stacked Widget index 6: Login Menu
	ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::moveToEdit()
{
	//Stacked Widget index 7: Edit Database Menu
	ui->stackedWidget->setCurrentIndex(6);
}
