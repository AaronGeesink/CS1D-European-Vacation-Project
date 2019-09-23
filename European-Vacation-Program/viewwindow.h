#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QWidget>
#include <QtSql>

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
	void showError(const QSqlError &err);
	QSqlRelationalTableModel *model;
};

#endif // VIEWWINDOW_H
