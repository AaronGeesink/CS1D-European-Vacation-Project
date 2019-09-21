#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ViewWindow(QWidget *parent = nullptr);
	~ViewWindow();

private:
	Ui::ViewWindow *ui;

signals:
	void moveToMainClicked();

private slots:
	void on_moveToMain_clicked();
};

#endif // VIEWWINDOW_H
