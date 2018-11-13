#include "../headers/mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones, bool opt):
QGridLayout(), x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones){


    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            QPushButton *pb1 = new CeldaGrafica(x,y,0);
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
        for(int i = 0; i < x_; i++) {
            for(int j = 0; j < y_; j++) {
                //srand(time(NULL));
                if(rand()%100 < porcentajeObstaculos_){     //sigue sin ser aleatorio
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

