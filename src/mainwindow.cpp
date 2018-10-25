#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* w = new QWidget;
    w -> setLayout(new MapaGrafico);

    setCentralWidget(w);

    //setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


