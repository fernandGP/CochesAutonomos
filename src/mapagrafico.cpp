#include "../headers/mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones, bool opt):
QGridLayout(), x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones){

<<<<<<< HEAD
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            CeldaGrafica *pb1 = new CeldaGrafica(0);
            connect(pb1, &QPushButton::released, pb1, &CeldaGrafica::toggleCeldaValor);
=======

    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            QPushButton *pb1 = new CeldaGrafica(x,y,0);
>>>>>>> 0d3386ce537bd015500db469223ec49177376511
            addWidget(pb1, i, j, 1, 1);
        }
    }

    addObstaculos();
    //addPeatones();
    setHorizontalSpacing(0);
    setVerticalSpacing(0);
}

MapaGrafico::~MapaGrafico(){}

<<<<<<< HEAD
void MapaGrafico::addObstaculos(){
  //Asignación automática
    vaciarMapa();

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(rand()%100 < porcentajeObstaculos_){
                QLayoutItem* lit = itemAtPosition(i, j);
                QWidget* wid = lit-> widget();
                CeldaGrafica* cg = dynamic_cast<CeldaGrafica*>(wid);
                /* AQUI ES DONDE IRÍA LA INSERCIÓN DE IMÁGENES PARA CADA ICONO / OBSTÁCULO */
                cg->setValor(1);
=======
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
>>>>>>> 0d3386ce537bd015500db469223ec49177376511
            }
        }
    }
        //Envio de señal para el cambio de evento

}

void MapaGrafico::vaciarMapa() {

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {

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

