#include "foodselectwindow.h"
#include "ui_foodselectwindow.h"

FoodSelectWindow::FoodSelectWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FoodSelectWindow)
{
	ui->setupUi(this);
}

FoodSelectWindow::~FoodSelectWindow()
{
	delete ui;
}

void FoodSelectWindow::setFoodSelection(std::vector<City> loadedCities)
{
	this->loadedCities = loadedCities;

	// Table Setup
	int numFoods = 0;
	for (int i = 0; i < loadedCities.size(); i++)
	{
		numFoods = numFoods + loadedCities[i].getNumFoods();
	}

	ui->foodTable->setRowCount(numFoods);
	ui->foodTable->setColumnCount(4);

	ui->foodTable->setHorizontalHeaderItem(0, new QTableWidgetItem("City"));
	ui->foodTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Food"));
	ui->foodTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Price"));
	ui->foodTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Quantity to Buy"));

	ui->foodTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *label;

	int foodsLoaded = 0;
	for (int i = 0; i < loadedCities.size(); i++)
	{
		label = new QLabel();
		label->setText(loadedCities[i].getName());
		ui->foodTable->setCellWidget(foodsLoaded, 0, label);

		std::vector<Food> foods = loadedCities[i].getFoods();
		for (int j = 0; j < foods.size(); j++)
		{
			// set the name of the food
			label = new QLabel();
			label->setText(foods[j].getName());
			ui->foodTable->setCellWidget(foodsLoaded, 1, label);

			// set the price of the food
			label = new QLabel();
			label->setText("$" + QString::number(foods[j].getPrice()));
			ui->foodTable->setCellWidget(foodsLoaded, 2, label);

			// add QLineEdit objects for quantity input
			ui->foodTable->setCellWidget(foodsLoaded, 3, new QSpinBox());

			foodsLoaded++;
		}
	}
}

void FoodSelectWindow::loadFoodQuantities()
{
	int foodsLoaded = 0;
	for (int i = 0; i < loadedCities.size(); i++)
	{
		std::vector<Food> foods = loadedCities[i].getFoods();
		for (int j = 0; j < foods.size(); j++)
		{
			QSpinBox *spinBox = qobject_cast<QSpinBox *>(ui->foodTable->cellWidget(foodsLoaded, 3));
			if (spinBox)
			{
				foods[i].setQuantity(spinBox->value());
				//qDebug() << spinBox->value();
			}
			foodsLoaded++;
		}
	}
}

std::vector<City> FoodSelectWindow::getLoadedCities()
{
	return loadedCities;
}

void FoodSelectWindow::on_moveToCitySelect_clicked()
{
	emit moveToCitySelectClicked();
}

void FoodSelectWindow::on_moveToResults_clicked()
{
	loadFoodQuantities();
	emit moveToResultsClicked();
}
