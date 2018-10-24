#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mapagrafico.h"

/**
 * MainWindow: Ventana gŕafica que contiene los elementos visuales
 *   del programa.
 */
class MainWindow : public QWidget
{
    /** Q_OBJECT: Constante que utiliza QT, para indicar al programa que se debe autogenerar
     *   páginas de código que permite al objeto con la constante definida funcionar como lo haría
     *   un QObject.
     */
    Q_OBJECT

public:
    explicit MainWindow(QGridLayout *layout = 0);
    ~MainWindow();

private:

};

#endif // MAINWINDOW_H
