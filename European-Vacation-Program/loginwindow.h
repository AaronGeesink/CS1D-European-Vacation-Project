#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QtSql>
#include "database.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	explicit LoginWindow(QWidget *parent = nullptr);
	~LoginWindow();

signals:
	void moveToMainClicked();
	void moveToEditClicked();

private slots:
	void on_moveToMain_clicked();
	void on_loginButton_clicked();

private:
	Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
