#ifndef FOODSELECTWINDOW_H
#define FOODSELECTWINDOW_H

#include <QWidget>

namespace Ui {
class FoodSelectWindow;
}

class FoodSelectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit FoodSelectWindow(QWidget *parent = nullptr);
	~FoodSelectWindow();

signals:
	void moveToCitySelectClicked();
	void moveToResultsClicked();

private slots:
	void on_moveToCitySelect_clicked();

	void on_moveToResults_clicked();

private:
	Ui::FoodSelectWindow *ui;
};

#endif // FOODSELECTWINDOW_H
