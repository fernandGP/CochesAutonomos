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

    QPushButton* generarObstaculos = new QPushButton(QString::fromUtf8("Generar obstáculos"));
    connect(generarObstaculos, &QPushButton::released, mapa, &MapaGrafico::addObstaculos);

    setCentralWidget(w);
    addToolBar(Qt::BottomToolBarArea, menu);
    menu->setMovable(false);
    menu->addWidget(generarObstaculos);

    //setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}


