#include "resultswindow.h"
#include "ui_resultswindow.h"

ResultsWindow::ResultsWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::ResultsWindow)
{
	ui->setupUi(this);
}

ResultsWindow::~ResultsWindow()
{
	delete ui;
}

void ResultsWindow::setResults(std::vector<City> loadedCities)
{

	std::priority_queue<City, std::vector<City>, CompareCity> cityPQ;

	for (int i = 0; i < loadedCities.size(); i++)
	{
		loadedCities[i].sortDistances();
		cityPQ.push(loadedCities[i]);
		qDebug() << loadedCities[i].getName();
	}


	ui->resultsTable->setRowCount(loadedCities.size());
	ui->resultsTable->setColumnCount(4);

	ui->resultsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Start"));
	ui->resultsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("End"));
	ui->resultsTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Distance"));
	ui->resultsTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Total Distance"));

	ui->resultsTable->setSelectionMode(QAbstractItemView::NoSelection);

	QLabel *name;
	/*for (int i = 0; i < loadedCities.size(); i++)
	{
		name = new QLabel();
		name->setText(loadedCities[i].getName());
		ui->resultsTable->setCellWidget(i, 0, name);

		name = new QLabel();
		name->setText(loadedCities[i].getFirstDistance().endCity);
		ui->resultsTable->setCellWidget(i, 1, name);

		name = new QLabel();
		name->setText(QString::number(loadedCities[i].getFirstDistance().distance));
		ui->resultsTable->setCellWidget(i, 2, name);
	}*/

	int i = 0;
	std::vector<QString> visited;

	while (!cityPQ.empty())
	{
		City city = cityPQ.top();
		qDebug() << city.getName();

		for (int i = 0; i < visited.size(); i++)
		{
			city.removeCityDistance(visited[i]);
		}

		name = new QLabel();
		name->setText(city.getName());
		ui->resultsTable->setCellWidget(i, 0, name);

		name = new QLabel();
		name->setText(city.getFirstDistance().endCity);
		ui->resultsTable->setCellWidget(i, 1, name);

		name = new QLabel();
		name->setText(QString::number(city.getFirstDistance().distance));
		ui->resultsTable->setCellWidget(i, 2, name);

		visited.push_back(city.getFirstDistance().endCity);
		if (i == 0)
			visited.push_back(city.getName());

		cityPQ.pop();
		i++;
	}
}

void ResultsWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void ResultsWindow::on_moveToMain_clicked()
{
	emit moveToMainClicked();
}
