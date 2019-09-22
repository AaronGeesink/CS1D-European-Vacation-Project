#ifndef CITYSELECTWINDOW_H
#define CITYSELECTWINDOW_H

#include <QWidget>

namespace Ui {
class CitySelectWindow;
}

class CitySelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit CitySelectWindow(QWidget *parent = nullptr);
	~CitySelectWindow();

signals:
	void moveToTripClicked();
	void moveToFoodSelectClicked();

private slots:
	void on_moveToTrip_clicked();

	void on_moveToFoodSelect_clicked();

private:
	Ui::CitySelectWindow *ui;
};

#endif // CITYSELECTWINDOW_H
