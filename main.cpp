#include "mainwindow.h"

#include <QApplication>

#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create and run window
    MainWindow w;
    w.show();
    return a.exec();
}
