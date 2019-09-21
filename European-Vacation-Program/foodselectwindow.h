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

private:
	Ui::FoodSelectWindow *ui;
};

#endif // FOODSELECTWINDOW_H
