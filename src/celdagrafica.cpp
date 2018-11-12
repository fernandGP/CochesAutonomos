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


void CeldaGrafica::setValor(int val){
    valor_ = val;
    switch (valor_){
    case 0: {
        setStyleSheet("");
        break;
    }
    case 1: {
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/gato.png);");
        break;
    }
    case 2: {
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/mouse.gif)");
        break;
    }
    default: {
        //throw a excepción personalizada
        break;
    }
    }
}

int CeldaGrafica::getValor(){ return valor_; }

void CeldaGrafica::toggleCeldaValor() {
    if (valor_ == 0 || valor_ == 1) {
        setValor(valor_ += 1);
    } else {
        setValor(0);
    }
}
