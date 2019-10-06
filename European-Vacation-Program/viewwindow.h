#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

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

	void on_loadCities_clicked();

private:
	Ui::ViewWindow *ui;
};

#endif // VIEWWINDOW_H
