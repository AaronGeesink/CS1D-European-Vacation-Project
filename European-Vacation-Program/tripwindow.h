#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QWidget>

namespace Ui {
class TripWindow;
}

class TripWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TripWindow(QWidget *parent = nullptr);
	~TripWindow();

signals:
	void moveToMainClicked();
	void moveTo11CitiesClicked();
	void moveToLondonClicked();
	void moveToCustomClicked();

private slots:
	void on_moveToMain_clicked();

	void on_moveTo11Cities_clicked();

	void on_moveToLondon_clicked();

	void on_moveToCustom_clicked();

private:
	Ui::TripWindow *ui;
};

#endif // TRIPWINDOW_H
