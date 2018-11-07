#include "../headers/mapa.h"
<<<<<<< HEAD
#include "../headers/mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int m,n,option;
    cout << "--Dimensiones mapa--" << endl;
    cout << "Introduce largo: "; cin >> m; cout << endl;
    cout << "Introduce ancho:"; cin >> n; cout << endl;
    cout << "--Modo de Visualización--" << endl;
    cout << "1. Modo Consola" << endl;
    cout << "2. Modo Gráfico" << endl;
    cin >> option;


    if(option == 1){
        int obs, pea;
        cout << "¿Cuánto porcentaje de obstáculos quiere?" << endl;
        cin >> obs; cout << endl;
        cout << "¿Cuánto porcentaje de peatones quiere?" << endl;
        cin >> pea;

        Mapa map(m,n,obs,pea);
        map.visualizar();
        while(true){sleep(200);}
    }
    else if(option == 2){
        QApplication a(argc, argv);

        MainWindow *w = new MainWindow(new QWidget);

        w -> show();

        return a.exec();
    }
=======
//#include "../headers/mainwindow.h"
//#include <QApplication>
//#include <iostream>
//#include <ctime>

int main(int argc, char *argv[])
{

    Mapa mapa(5, 5, 20, 2);
    vector<Celda> result = mapa.Astar(0,0, 4,4);
    mapa.visualizar();
    /*for(int i = result.size()-1; i >= 0; i--){
        cout << "(" << result[i].getX() << "," << result[i].getY() << ")"
             << endl;
    }*/
    return 0;
>>>>>>> a* funcionando
}
