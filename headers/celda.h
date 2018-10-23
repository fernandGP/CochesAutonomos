#ifndef CELDA_H
#define CELDA_H

#include <iostream>

class Celda
{
private:
    int valor_;                     //0 vacío, 1 obstáculo, 2 usuario
public:
    Celda();
    Celda(int valor);
    ~Celda();

    int getValor();
    void setValor(int valor);

    void visualizar();
};

#endif // CELDA_H
