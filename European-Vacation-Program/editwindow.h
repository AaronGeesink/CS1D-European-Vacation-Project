#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QWidget>

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

private:
	Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
