#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <viewwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void on_exitButton_clicked();
	void on_moveToView_clicked();

	void moveToMain();

private:
	Ui::MainWindow *ui;
	ViewWindow ViewWind;
};
#endif // MAINWINDOW_H
