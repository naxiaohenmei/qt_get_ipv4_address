#include "mainwindow.h"
#include "ipconfig.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    std::cout << "hello" << std::endl;
    ipconfig ip;
    w.show();
    return a.exec();
}
