#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* w = new QWidget;
    mapa = new MapaGrafico;
    menu = new Menu;

    w -> setLayout(mapa);


    setCentralWidget(w);
    addToolBar(menu);

    //setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


