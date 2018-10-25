#include "../headers/celdagrafica.h"

CeldaGrafica::CeldaGrafica(int valor): valor_(valor), QPushButton()
{

    setFixedHeight(52);
    setFixedWidth(52);

    switch (valor_){
    case 0: {
        setText(" ");
        break;
    }
    case 1: {
        setText("0");
        break;
    }
    case 2: {
        setText("!");
        break;
    }
    default: {
        //throw a excepción personalizada
        break;
    }
    }
}

CeldaGrafica::~CeldaGrafica(){}

void CeldaGrafica::setValor(int val){
    valor_ = val;
    switch (valor_){
    case 0: {
        setText(" ");
        break;
    }
    case 1: {
        setText("0");
        break;
    }
    case 2: {
        setText("!");
        break;
    }
    default: {
        //throw a excepción personalizada
        break;
    }
    }
}

int CeldaGrafica::getValor(){ return valor_; }
