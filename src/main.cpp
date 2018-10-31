#include "../headers/mapa.h"
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

        QWidget *w = new MainWindow(new MapaGrafico());

        w -> show();

        return a.exec();
    }
}
