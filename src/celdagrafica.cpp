#include "../headers/celdagrafica.h"

CeldaGrafica::CeldaGrafica(int x, int y, int valor): valor_(valor), QPushButton()
{

    setFixedHeight(50);     //establecer diseño responsive celdas (cantidadpixel/x)(cantidadpixel/y)
    setFixedWidth(50);

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
