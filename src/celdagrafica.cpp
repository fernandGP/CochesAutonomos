#include "../headers/celdagrafica.h"


CeldaGrafica::CeldaGrafica(int x, int y, int valor):  QPushButton(), valor_(valor)
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
    case 3: {
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/queso.png)");
    }
    default: {
        //throw a excepción personalizada
        break;
    }

    // Añadir casos: objetivo (queso), caminos seleccionados por la heurística (naranja) y camino final (verde).
    }
}

int CeldaGrafica::getValor(){ return valor_; }

void CeldaGrafica::toggleCeldaValor() {
    if (valor_ == 0 || valor_ == 1 || valor_ == 2) {
        setValor(valor_ += 1);
    } else {
        setValor(0);
    }
}
