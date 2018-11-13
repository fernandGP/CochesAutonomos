#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QToolBar>
#include "mapagrafico.h"
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int x, int y, bool h, int obs, int pea, QWidget *parent);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MapaGrafico* mapa;
    Menu* menu;
};

#endif // MAINWINDOW_H
