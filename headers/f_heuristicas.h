#ifndef F_HEURISTICAS_H
#define F_HEURISTICAS_H

#include <cmath>
#include "celda.h"

class f_heuristica
{
public:
    f_heuristica();
    virtual ~f_heuristica();

    virtual int operator()(const Celda&, const Celda&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class d_euclidea : public f_heuristica
{
public:
    d_euclidea();
    int operator()(const Celda&, const Celda&);
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class d_manhattan : public f_heuristica
{
public:
    d_manhattan();
    int operator()(const Celda&, const Celda&);
};

#endif // F_HEURISTICAS_H
