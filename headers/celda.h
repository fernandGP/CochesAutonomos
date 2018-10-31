#ifndef CELDA_H
#define CELDA_H

#include <iostream>

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
     */
    int valor_;

public:
    Celda(int valor = 0);
    ~Celda();

    int getValor();
    void setValor(int valor);

    /** visualizar(): Muestra el contenido por terminal.
     * 'X': Vacío.
     * 'O': Obstáculo.
     * '!': Usuario.
     */
    void visualizar();
};

#endif // CELDA_H
