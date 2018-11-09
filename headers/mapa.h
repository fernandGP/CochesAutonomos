#ifndef MAPA_H
#define MAPA_H

#define CONST_P_OBSTACULOS 30
#define CONST_N_PEATONES 20

#include <vector>
#include <sstream>
#include <fstream>
#include "celda.h"
//#include <set>
#include <cmath>

using namespace std;

/**
 * Mapa: Matriz de celdas, implementada en la línea de comandos. Desde ella se
 *   gestionan las celdas y sus propiedades.
 */
class Mapa{

private:
    /**
     * rejilla_: Matriz de celdas.
     * porcentajeObstaculos_: Porcentaje que define la cantidad de celdas que
     *   contendrán obstáculos.
     * nPeatones_: Contiene el número de peatones desplegados por el mapa.
     * x_, y_; Tamaño del mapa (anchura y altura).
     */
    vector<vector<Celda> > rejilla_;
    int porcentajeObstaculos_;
    int nPeatones_;
    int x_, y_;

    /**
     * addObstaculos: Añade obstáculos en las celdas del mapa.
     * mod: Booleano que permite alternar la entrada de obstáculos en el mapa:
     *  mod true: Se añaden los obstáculos desde un archivo que los contiene.
     *  mod false: Los obstáculos se generan aleatoriamente.
     */
    void addObstaculos(bool mod);
    void addPeatones();
    int fHeuristica(const Celda&, const Celda&);

    void setVecinos();
    bool is_in_set(const Celda&, const std::vector<Celda>&);

    void reconstruir_camino(vector<Celda> &v, Celda actual, Celda I);

public:
    Mapa(int x, int y, bool autom, int pObst=0, int nPeatones_=0);
    ~Mapa();

    void visualizar();
    vector<Celda> Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);
};

#endif // MAPA_H
