#include "../headers/mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones, bool opt):
QGridLayout(), x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones){


    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            CeldaGrafica *pb1 = new CeldaGrafica(x, y, 0);
            connect(pb1, &QPushButton::released, pb1, &CeldaGrafica::toggleCeldaValor);
            addWidget(pb1, i, j, 1, 1);
        }
    }

    addObstaculos();
    //addPeatones();
    setHorizontalSpacing(0);
    setVerticalSpacing(0);
}

MapaGrafico::~MapaGrafico(){}

void MapaGrafico::addObstaculos(){
  //Asignación automática
    vaciarMapa();

    for(int i = 0; i < x_; i++) {
        for(int j = 0; j < y_; j++) {
            if(rand()%100 < porcentajeObstaculos_){
                QLayoutItem* lit = itemAtPosition(i, j);
                QWidget* wid = lit-> widget();
                CeldaGrafica* cg = dynamic_cast<CeldaGrafica*>(wid);
                /* AQUI ES DONDE IRÍA LA INSERCIÓN DE IMÁGENES PARA CADA ICONO / OBSTÁCULO */
                cg->setValor(1);
            }
        }
    }
        //Envio de señal para el cambio de evento

}

void MapaGrafico::vaciarMapa() {

    for(int i = 0; i < x_; i++) {
        for(int j = 0; j < y_; j++) {

                QLayoutItem* lit = itemAtPosition(i, j);
                QWidget* wid = lit-> widget();
                CeldaGrafica* cg = dynamic_cast<CeldaGrafica*>(wid);

                cg->setValor(0);
        }
    }

}

void MapaGrafico::toggleButton(CeldaGrafica*& cg) {
    cg->toggleCeldaValor();
}
