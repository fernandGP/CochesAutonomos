#include "mapa.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGridLayout *l1 = new MapaGrafico(10,10,20,10);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            QPushButton *pb1 = new CeldaGrafica(0);
            l1 -> addWidget(pb1, i, j, 1, 1);
        }
    }

    QWidget *w = new MainWindow(l1);
    w -> show();

    return a.exec();
}
