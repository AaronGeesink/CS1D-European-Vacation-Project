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
