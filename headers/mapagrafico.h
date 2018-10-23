#ifndef MAPAGRAFICO_H
#define MAPAGRAFICO_H

#include <QGridLayout>
#include "celdagrafica.h"

using namespace std;

class MapaGrafico : public QGridLayout{

private:
    int porcentajeObstaculos_;
    int nPeatones_;
    int x_, y_;

    void addObstaculos(bool mod);                   //mod indica el tipo de creación de obstáculos. Manual o auto
    void addPeatones();

public:
    explicit MapaGrafico(int x = 10, int y = 10, int pObst = 20, int nPeatones_ = 10);
    virtual ~MapaGrafico();

    void visualizar();                              //Redundante en el modo grafico
};

#endif // MAPAGRAFICO_H
