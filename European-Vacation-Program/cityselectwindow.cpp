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
	ui->cityTable->clear();

	if (planNumber == 0)
		setParisPlan();
	else if (planNumber == 1)
		setLondonPlan();
	else
		setCustomPlan();
}

std::vector<City>& CitySelectWindow::getLoadedCities()
{
	return loadedCities;
}

int CitySelectWindow::getPlanNumber()
{
	return planNumber;
}

void CitySelectWindow::setPlanNumber(int number)
{
	planNumber = number;
}

void CitySelectWindow::on_moveToFoodSelect_clicked()
{
	if (planNumber == 0)
		loadParisPlan();
	else if (planNumber == 1)
		loadLondonPlan();
	else
		loadCustomPlan();
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

void CitySelectWindow::setParisPlan()
{
	ui->cityTable->setRowCount(cityNames.size());
	ui->cityTable->setColumnCount(3);
	ui->cityTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Cities to Visit"));
	ui->cityTable->setHorizontalHeaderItem(1, new QTableWidgetItem("11 Cities"));
	ui->cityTable->setHorizontalHeaderItem(2, new QTableWidgetItem("13 Cities"));
	ui->cityTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < cityNames.size(); i++)
	{
		name = new QLabel();
		name->setText(cityNames[i]);
		ui->cityTable->setCellWidget(i, 0, name);
	}
	ui->cityTable->setCellWidget(0,1, new QRadioButton());
	ui->cityTable->setCellWidget(0,2, new QRadioButton());

}

void CitySelectWindow::setLondonPlan()
{
	ui->cityTable->setRowCount(cityNames.size());
	ui->cityTable->setColumnCount(2);
	ui->cityTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Cities"));
	ui->cityTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Number to Visit"));
	ui->cityTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	for (int i = 0; i < cityNames.size(); i++)
	{
		name = new QLabel();
		name->setText(cityNames[i]);
		ui->cityTable->setCellWidget(i, 0, name);
	}
	ui->cityTable->setCellWidget(0,1,new QLineEdit());
}

void CitySelectWindow::setCustomPlan()
{
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

void CitySelectWindow::loadParisPlan()
{
	QString startingCity("Paris");
	QString parisCities[13] = { "Paris", "Rome", "Madrid", "Amsterdam", "Brussels", "Budapest", "Hamburg", "London", "Lisbon", "Prague", "Stockholm", "Vienna"};

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

void CitySelectWindow::loadLondonPlan()
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

void CitySelectWindow::loadCustomPlan()
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
