#ifndef MAPAGRAFICO_H
#define MAPAGRAFICO_H

#include <QGridLayout>
#include <fstream>
#include "celdagrafica.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "f_heuristicas.h"

using namespace std;

/** MapaGrafico: Matriz de celdas mostrada desde la interfaz gráfica. Desde ella se
 *   gestionan las celdas y sus propiedades.
 */
class MapaGrafico : public QGridLayout {


private:
    Q_OBJECT
    /**
     * porcentajeObstaculos_: Porcentaje que define la cantidad de celdas que
     *   contendrán obstáculos.
     * nPeatones_: Contiene el número de peatones desplegados por el mapa.
     * x_, y_; Tamaño del mapa (anchura y altura).
     */ 
    int x_, y_;
    int porcentajeObstaculos_;
    int nPeatones_;
    f_heuristica* heuristica_;
    /**
     * addObstaculos: Añade obstáculos en las celdas del mapa.
     * mod: Booleano que permite alternar la entrada de obstáculos en el mapa:
     *  mod true: Se añaden los obstáculos desde un archivo que los contiene.
     *  mod false: Los obstáculos se generan aleatoriamente.
     */

    void addPeatones();
    void vaciarMapa();

    void setVecinos();
    bool is_in_set(const Celda&, const std::vector<Celda>&);
    void reconstruir_camino(vector<Celda> &v, Celda actual, Celda I);
    vector<Celda> Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);

public:
    explicit MapaGrafico(int x = 10, int y = 10, bool h = false, int pObst = CONST_P_OBSTACULOS, int nPeatones_ = CONST_P_PEATONES, bool opt = 0);
    virtual ~MapaGrafico();

    void caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);
    void visualizar();                              //Redundante en el modo grafico
    void addObstaculos();
    void toggleButton(CeldaGrafica*& cg);
    void startCaminoMinimo();

};

#endif // MAPAGRAFICO_H
