#include "mapa.h"

void Mapa::addObstaculos(bool mod){

    if(mod){    //Modo guiado

    }
    else{       //Asignación automática
        for(int i = 0; i < rejilla_.size(); i++){
            for(int j = 0; j < rejilla_[i].size(); j++){
                if(rand()%100 < porcentajeObstaculos_)  rejilla_[i][j].setValor(1);
            }
        }
    }
}

void Mapa::addPeatones(){}

Mapa::Mapa(int x, int y, int pObst, int nPeatones):x_(x), y_(y){

    if(pObst == -1) porcentajeObstaculos_ = CONST_P_OBSTACULOS;
    else porcentajeObstaculos_ = pObst;

    if(nPeatones == -1) nPeatones_ = CONST_N_PEATONES;
    else nPeatones_ = nPeatones;

    Celda aux;

    for(int i = 0; i < x_; i++){
        vector<Celda> vectorY;
        for(int j = 0; j < y_; j++){
            vectorY.push_back(aux);
        }
        rejilla_.push_back(vectorY);
    }

    addObstaculos(false);
    addPeatones();
}

Mapa::~Mapa(){}

void Mapa::visualizar(){

    for(int i = 0; i < rejilla_.size(); i++){
        cout << "|";
        for (int j = 0; j < rejilla_[i].size(); j++){
            rejilla_[i][j].visualizar();
        }
        cout << "|" << endl;
    }
}
