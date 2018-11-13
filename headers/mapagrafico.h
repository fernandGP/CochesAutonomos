#ifndef MAPAGRAFICO_H
#define MAPAGRAFICO_H

#include <QGridLayout>
#include <fstream>
#include "celdagrafica.h"

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
    /**
     * addObstaculos: Añade obstáculos en las celdas del mapa.
     * mod: Booleano que permite alternar la entrada de obstáculos en el mapa:
     *  mod true: Se añaden los obstáculos desde un archivo que los contiene.
     *  mod false: Los obstáculos se generan aleatoriamente.
     */

    void addPeatones();
    void vaciarMapa();
    CeldaGrafica* cg2;

public:
    explicit MapaGrafico(int x = 10, int y = 10, int pObst = 20, int nPeatones_ = 10, bool opt = 0);
    virtual ~MapaGrafico();

    void visualizar();                              //Redundante en el modo grafico
    void addObstaculos();
    void toggleButton(CeldaGrafica*& cg);

};

#endif // MAPAGRAFICO_H
