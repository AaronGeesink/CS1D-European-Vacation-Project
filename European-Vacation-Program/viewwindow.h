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

signals:
	void moveToMainClicked();

private slots:
	void on_moveToMain_clicked();

private:
	Ui::ViewWindow *ui;
};

#endif // VIEWWINDOW_H
