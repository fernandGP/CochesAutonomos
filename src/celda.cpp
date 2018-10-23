#include "../headers/celda.h"

Celda::Celda():valor_(0){}

Celda::Celda(int valor):valor_(valor){}

Celda::~Celda(){}

int Celda::getValor(){ return valor_; }

void Celda::setValor(int valor){ valor_ = valor; }

void Celda::visualizar(){
    switch (valor_){
    case 0: {
        std::cout << " X ";
        break;
    }
    case 1: {
        std::cout << " O ";
        break;
    }
    case 2: {
        std::cout << " ! ";
        break;
    }
    default: {
        //throw a excepción personalizada
        break;
    }
    }
}
