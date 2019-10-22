#include "cityselectwindow.h"
#include "ui_cityselectwindow.h"

CitySelectWindow::CitySelectWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CitySelectWindow)
{
	ui->setupUi(this);
    ui->cityTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

CitySelectWindow::~CitySelectWindow()
{
	delete ui;
}

void CitySelectWindow::setCitySelection()
{
	loadedCities.clear();
	cityNames.clear();
    ui->cityTable->clear();

	if (planNumber == 0)
	{
		setParisPlan();
	}
	else if (planNumber == 1)
	{
		cityNames = queryCityNames();
		setLondonPlan();
	}
	else
	{
		cityNames = queryCityNames();
		setCustomPlan();
	}
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

int CitySelectWindow::getNumCities()
{
	return numCities;
}

bool CitySelectWindow::getError()
{
	return error;
}

void CitySelectWindow::setError(bool value)
{
	error = value;
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

void CitySelectWindow::loadSelectedCities(QString startingCity)
{
	loadedCities.clear();

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
	}
}

void CitySelectWindow::setParisPlan()
{
	QString parisCities[13] = { "Paris", "Amsterdam", "Berlin", "Brussels", "Budapest", "Hamburg", "Lisbon", "London", "Madrid", "Prague", "Rome", "Stockholm", "Vienna"};

	for (int i = 0; i < (sizeof(parisCities)/sizeof(parisCities[0])); ++i)
	{
		cityNames.push_back(parisCities[i]);
	}

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
	// if London isn't on the list of active cities, add it by force
	bool london = false;
	for (int i = 0; i < cityNames.size(); i++)
	{
		if (cityNames[i] == "London")
			london = true;
	}
	if (!london)
		cityNames.push_back(QString("London"));

	// set up the city select ui elements
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

	QRadioButton *button = qobject_cast<QRadioButton *>(ui->cityTable->cellWidget(0, 1));
	if (button && button->isChecked())
	{
		cityNames.erase(cityNames.end() - 1);
		cityNames.erase(cityNames.end() - 1);
	}

	setError(false);

	loadSelectedCities(startingCity);
	numCities = loadedCities.size();
}

void CitySelectWindow::loadLondonPlan()
{
	QString startingCity("London");

	QLineEdit *lineEdit = qobject_cast<QLineEdit *>(ui->cityTable->cellWidget(0, 1));
	if (lineEdit)
	{
		numCities = lineEdit->text().toInt();
		qDebug() << numCities;
	}

	if (numCities < 2 || numCities > cityNames.size())
	{
		error = true;
		QMessageBox::information(this, tr("Input Error"), tr("Please select a number\nfrom 2 to the total number of cities"));
	}
	else
	{
		error = false;
		loadSelectedCities(startingCity);
		sortLondonCities();
		loadSelectedCities(startingCity);
	}
}

void CitySelectWindow::sortLondonCities()
{
	std::vector<City> londonCities = loadedCities;
	std::vector<QString> visited;
	QString current;
	City city;
	for (int i = 0; i < londonCities.size(); i++)
	{
		if (loadedCities[i].getIsStart() == true)
		{
			city = loadedCities[i];
		}
	}

	for (int i = 0; i < numCities; i++)
	{

		for (int j = 0; j < visited.size(); j++)
		{
			city.removeCityDistance(visited[j]);
		}

		visited.push_back(city.getShortestDistance().endCity);
		if (i == 0)
			visited.push_back(city.getName());

		city = londonCities[0];
		for (int i = 0; i < londonCities.size(); i++)
		{
			if (londonCities[i].getName() == city.getShortestDistance().endCity)
			{
				city = loadedCities[i];
			}
		}
	}
	cityNames = visited;
}

void CitySelectWindow::loadCustomPlan()
{
	QString startingCity("");
	cityNames = queryCityNames();

	for (int i = cityNames.size(); i > 0; i--)
	{
		QRadioButton *radio = qobject_cast<QRadioButton *>(ui->cityTable->cellWidget(i-1, 2));
		if (radio && radio->isChecked())
		{
			startingCity = cityNames[i - 1];
		}

		QCheckBox *checkbox = qobject_cast<QCheckBox *>(ui->cityTable->cellWidget(i-1, 1));
		if (checkbox && !checkbox->isChecked())
		{
			cityNames.erase(cityNames.begin() + i - 1);
		}

	}

	// check if the starting city is selected and valid
	if (startingCity == "" || !isValidStart(startingCity))
	{
		qDebug() << startingCity;
		error = true;
		setCitySelection();
		QMessageBox::information(this, tr("Input Error"), tr("Please Select\na valid starting city"));
	}
	else if (cityNames.size() < 2)
	{
		error = true;
		setCitySelection();
		QMessageBox::information(this, tr("Input Error"), tr("Please Select\n2 or more cities"));
	}
	else
	{
		error = false;
		loadSelectedCities(startingCity);
		numCities = loadedCities.size();
	}
}

bool CitySelectWindow::isValidStart(QString startingCity)
{
	for (int i = 0; i < cityNames.size(); i++)
	{
		if (cityNames[i] == startingCity)
			return true;
	}
	return false;
}
