#ifndef CELDA_H
#define CELDA_H

#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include "pers_exceptions.hpp"

/**
 * Celda: Define, en la línea de comandos, las celdas que componen
 *   el mapa. Cada celda puede estar vacía, contener obstáculos o
 *   el vehículo.
 */
class Celda
{
private:
    /** valor_: Indica el contenido de la celda.
     * case 0: Vacío.
     * case 1: Obstáculo.
     * case 2: Usuario.
     * case 3: Camino de coche
     */
    int valor_;
    int g_;                             //Coste principio-celda
    int f_;                             //Coste celda-final
    int x_;                             //La celda necesita sus coordenadas para conocer la funcion heurística
    int y_;

    /**
     * vecinos_: Almacena coordenadas de celdas ACCESIBLES (sin obstáculos) colindantes
     * padre_: Coordenadas de la celda vecina con menor coste de llegada hasta el momento (camino minimo)
     */
    std::vector<std::pair<int, int> > vecinos_;
    std::pair<int, int> padre_;

public:

    static int contador;

    Celda();
    Celda(int x, int y, int valor = 0, int g = INT_MAX , int f = INT_MAX);
    ~Celda();

    /**
     *  Los siguientes metodos son getters y setters del valor interno de la celda,
     *  de sus coordenadas x,y  y de sus valores para heurística g_ y f_
     */

    int getValor();                             void setValor(int valor);
    int getX() const;
    int getY() const;
    int getf_();                                void setf_(int f);
    int getg_();                                void setg_(int g);

    std::pair<int,int> getPadre() const;
    std::pair<int,int> getPadre();
    void setPadre(const Celda&);

    unsigned int sizeVecinos();
    std::pair<int, int> getVecino(int i);
    void resetVecinos();

    /** visualizar(): Muestra el contenido por terminal.
     * ' ': Vacío.
     * 'O': Obstáculo.
     * '!': Usuario.
     */
    void visualizar();

    /**
     * addVecino(const Celda&) Añade un par x,y a su vector de vecinos
     */
    void addVecino(const Celda&);
};

#endif // CELDA_H
