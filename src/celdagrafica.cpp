#include "../headers/celdagrafica.h"

CeldaGrafica::CeldaGrafica(int valor): valor_(valor), QPushButton()
{

    setFixedHeight(30);
    setFixedWidth(30);

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
