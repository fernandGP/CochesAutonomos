#include "mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones):
x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones),
QGridLayout()
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            QPushButton *pb1 = new CeldaGrafica(0);
            addWidget(pb1, i, j, 1, 1);
        }
    }
}

MapaGrafico::~MapaGrafico(){}
