#include "cityselectwindow.h"
#include "ui_cityselectwindow.h"

CitySelectWindow::CitySelectWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CitySelectWindow)
{
	ui->setupUi(this);
}

CitySelectWindow::~CitySelectWindow()
{
	delete ui;
}

void CitySelectWindow::setCitySelection()
{
	loadedCities.clear();
	cityNames.clear();
	cityNames = queryCityNames();

	// Table Setup
	ui->cityTable->setRowCount(cityNames.size());
	ui->cityTable->setColumnCount(3);

	ui->cityTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
	ui->cityTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Cities to Add"));
	ui->cityTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Starting City"));

	ui->cityTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < cityNames.size(); i++)
	{
		name = new QLabel();
		name->setText(cityNames[i]);
		ui->cityTable->setCellWidget(i, 0, name);

		ui->cityTable->setCellWidget(i, 1, new QCheckBox());
		ui->cityTable->setCellWidget(i, 2, new QRadioButton());
	}
}

std::vector<City> CitySelectWindow::getLoadedCities()
{
	return loadedCities;
}

void CitySelectWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void CitySelectWindow::on_moveToFoodSelect_clicked()
{
	loadSelectedCities();
	emit moveToFoodSelectClicked();
}

void CitySelectWindow::loadSelectedCities()
{
	QString startingCity;

	for (int i = cityNames.size(); i > 0; i--)
	{
		QCheckBox *checkbox = qobject_cast<QCheckBox *>(ui->cityTable->cellWidget(i-1, 1));
		if (checkbox && !checkbox->isChecked())
		{
			//qDebug() << cityNames[i-1] << " erased";
			cityNames.erase(cityNames.begin() + i - 1);
		}

		QRadioButton *radio = qobject_cast<QRadioButton *>(ui->cityTable->cellWidget(i-1, 2));
		if (radio && radio->isChecked())
		{
			startingCity = cityNames[i - 1];
		}
	}

	//qDebug() << "remaining cities:";
	for (int start = 0; start < cityNames.size(); start++)
	{
		std::vector<CityDistance> cityDistances;
		std::vector<Food> foods;

		for (int end = 0; end < cityNames.size(); end++)
		{
			if (start != end)
			{
				cityDistances.push_back(queryDistance(cityNames[start], cityNames[end]));
				foods = queryFoods(cityNames[start]);
			}
		}

		City city(cityNames[start], cityDistances, foods);
		if (cityNames[start] == startingCity)
		{
			city.setIsStart(true);
			qDebug() << "Start is: " << city.getName();
		}

		loadedCities.push_back(city);
		//qDebug() << cityNames[start];
	}
}
