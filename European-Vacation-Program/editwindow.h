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

	void on_saveButton_clicked();

private:
	Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
