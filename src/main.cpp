//#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* w = new MainWindow(new QWidget);

    w -> show();

    return a.exec();
}
