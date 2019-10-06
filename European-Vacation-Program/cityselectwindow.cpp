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

void CitySelectWindow::on_moveToTrip_clicked()
{
	emit moveToTripClicked();
}

void CitySelectWindow::on_moveToFoodSelect_clicked()
{
	selectCities();
	emit moveToFoodSelectClicked();
}

void CitySelectWindow::selectCities()
{
	for (int i = cityNames.size(); i > 0; i--)
	{
		//QWidget *pWidget = ui->cityTable->cellWidget(i - 1, 1);
		//QCheckBox *checkbox = pWidget->findChild<QCheckBox *>();
		QCheckBox *checkbox = qobject_cast<QCheckBox *>(ui->cityTable->cellWidget(i-1, 1));
		if (checkbox && !checkbox->isChecked())
		{
			qDebug() << cityNames[i-1] << " erased";
			cityNames.erase(cityNames.begin() + i - 1);
		}
	}
	qDebug() << "remaining cities:";
	for (int i = 0; i < cityNames.size(); i++)
		qDebug() << cityNames[i];
}
