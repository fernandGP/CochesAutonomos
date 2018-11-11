#include "../headers/f_heuristicas.h"

f_heuristica::f_heuristica(){}

f_heuristica::~f_heuristica(){}

//-----------------------------------------------------

int d_euclidea::operator()(const Celda& i, const Celda& f){
    return static_cast<int>(sqrt(pow((i.getX() - f.getX()),2) + pow((i.getY() - f.getY()), 2)));
}

//-----------------------------------------------------

int d_manhattan::operator()(const Celda& i, const Celda& f){
    return static_cast<int>(fabs(static_cast<double>(i.getX() - f.getX())) + fabs(static_cast<double>(i.getY() - f.getY())));
}
