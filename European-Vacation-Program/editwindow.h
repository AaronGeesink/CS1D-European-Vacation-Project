#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>
#include "database.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QWidget
{
	Q_OBJECT

public:
	explicit EditWindow(QWidget *parent = nullptr);
	~EditWindow();

signals:
	void moveToMainClicked();

private slots:
	void on_moveToMain_clicked();

	void on_loadCities_clicked();

	void on_loadFood_clicked();

	void on_loadDistances_clicked();

	void on_submitButton_clicked();

	void on_revertButton_clicked();

private:
	Ui::EditWindow *ui;
	QSqlTableModel * model;
};

#endif // EDITWINDOW_H
