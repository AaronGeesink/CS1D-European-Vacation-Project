#include "mainwindow.h"

#include <QApplication>
#include <QSql>

int main(int argc, char *argv[])
{
	// Initial setup
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
