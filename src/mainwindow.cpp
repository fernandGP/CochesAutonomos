#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(int x, int y, bool h, int obs, int pea, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget* w = new QWidget;
    mapa = new MapaGrafico(x, y);
    menu = new Menu;

    setWindowTitle("Ratón");

    w -> setLayout(mapa);

    QPushButton* generarObstaculos = new QPushButton(QString::fromUtf8("Generar obstáculos"));
    connect(generarObstaculos, &QPushButton::released, mapa, &MapaGrafico::addObstaculos);

    QPushButton* calcularTrayectoria = new QPushButton(QString::fromUtf8("Calcular trayectoria"));
    connect(calcularTrayectoria, &QPushButton::released, mapa, &MapaGrafico::startCaminoMinimo);

    setCentralWidget(w);
    addToolBar(Qt::BottomToolBarArea, menu);
    menu->setMovable(false);
    menu->addWidget(generarObstaculos);
    menu->addWidget(calcularTrayectoria);

    void caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);

    //setFixedSize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}
