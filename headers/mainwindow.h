#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include "../headers/mapagrafico.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int x, int y, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MapaGrafico* mapa;
};

#endif // MAINWINDOW_H
