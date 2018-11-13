#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int x, int y, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* w = new QWidget;
    mapa = new MapaGrafico(x,y);

    w -> setLayout(mapa);

    setCentralWidget(w);

    //setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


