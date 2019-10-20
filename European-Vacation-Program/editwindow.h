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

private slots:

	void on_loadCities_clicked();

	void on_loadFood_clicked();

	void on_loadDistances_clicked();

	void on_submitButton_clicked();

	void on_revertButton_clicked();

	void on_deleteFoodItem_clicked();

	void on_addFoodButton_clicked();

private:
	Qt::ItemFlags flags(const QModelIndex & index) const;
	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role);

	Ui::EditWindow *ui;
	QSqlTableModel * model;
	QSqlQueryModel * queryModel;
	int currentTable = 1;
};

#endif // EDITWINDOW_H
