#include "../headers/mapagrafico.h"

MapaGrafico::MapaGrafico(int x, int y, int pObst, int nPeatones, bool opt):
x_(x), y_(y), porcentajeObstaculos_(pObst), nPeatones_(nPeatones),
QGridLayout()
{
    addObstaculos(opt);               //De momento directamente aleatorio. Pruena
}

MapaGrafico::~MapaGrafico(){}

void MapaGrafico::addObstaculos(bool mod){
    if(mod){    //Modo guiado
       /* int x, y;
        ifstream InputFile;
        InputFile.open ("coordenadas.txt", ios::in);

        while(!InputFile.eof()){
            InputFile >> x >> y;
            rejilla_[x][y].setValor(1);
        }
        InputFile.close();
        */
    }
    else{       //Asignación automática
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(rand()%100 < porcentajeObstaculos_){
                    QPushButton *pb1 = new CeldaGrafica(1);
                    addWidget(pb1, i, j, 1, 1);
                }
                else{
                    QPushButton *pb1 = new CeldaGrafica(0);
                    addWidget(pb1, i, j, 1, 1);
                }
            }
        }
    }
}

