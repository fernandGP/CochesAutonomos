#include "../headers/mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones, bool opt):
x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones),
QGridLayout()
{


    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            QPushButton *pb1 = new CeldaGrafica(0);
            addWidget(pb1, i, j, 1, 1);
        }
    }

    addObstaculos(opt);               //De momento directamente aleatorio. Pruena
    //addPeatones();
    setHorizontalSpacing(0);
    setVerticalSpacing(0);
}

MapaGrafico::~MapaGrafico(){}

void MapaGrafico::addObstaculos(bool mod){
    if(mod){    //Modo guiado
    }
    else{       //Asignación automática
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(rand()%100 < porcentajeObstaculos_){
                    QLayoutItem* lit = itemAtPosition(i, j);
                    QWidget* wid = lit-> widget();
                    CeldaGrafica* cg = dynamic_cast<CeldaGrafica*>(wid);

                    /* AQUI ES DONDE IRÍA LA INSERCIÓN DE IMÁGENES PARA CADA ICONO / OBSTÁCULO */
                    cg->setStyleSheet("border-image:url(../CochesAutonomos/assets/img/gato.png);");
                }
            }
        }

        //Envio de señal para el cambio de evento
    }
}

