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
        // Vacío
        setStyleSheet("");
        break;
    }
    case 1: {
        // Obstáculo
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/gato.png);");
        break;
    }
    case 2: {
        // Peatón
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/queso.png)");
        break;
    }
    case 3: {
        // Camino
        setStyleSheet("background-color: rgb(255,255,0);");
        break;
    }
    case 4: {
        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/mouse.gif)");
        break;
    }
    case 5: {

        setStyleSheet("border-image:url(../CochesAutonomos/assets/img/puerta.png)");
        break;
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
    if (valor_ != 5) {
        if (valor_ == 2) {
            setValor(4);
        } else {
            setValor(valor_ += 1);
        }
    } else {
        setValor(0);
    }
}
