#include "../headers/celdagrafica.h"


CeldaGrafica::CeldaGrafica(int valor):  QPushButton(), valor_(valor)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    setFixedHeight(height/x);
    setFixedWidth(width/y);

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
