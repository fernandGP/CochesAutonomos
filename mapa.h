#ifndef MAPA_H
#define MAPA_H

#define CONST_P_OBSTACULOS 30
#define CONST_N_PEATONES 20

#include <vector>
#include "celda.h"

using namespace std;
class Mapa{

private:
    vector<vector<Celda> > rejilla_;
    int porcentajeObstaculos_;
    int nPeatones_;
    int x_, y_;

    void addObstaculos(bool mod);                   //mod indica el tipo de creación de obstáculos. Manual o auto
    void addPeatones();

public:
    Mapa(int x, int y, int pObst, int nPeatones_);
    ~Mapa();

    void visualizar();
};

#endif // MAPA_H
