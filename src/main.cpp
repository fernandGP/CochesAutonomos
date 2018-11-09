#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int m,n,option;
    bool modo;
    cout << "--Dimensiones mapa--" << endl;
    cout << "Introduce largo: "; cin >> m; cout << endl;
    cout << "Introduce ancho:"; cin >> n; cout << endl;
    cout << "--Modo de Visualización--" << endl;
    cout << "1. Modo Consola" << endl;
    cout << "2. Modo Gráfico" << endl;
    cin >> option;



    if(option == 1){                //modo consola
        int obs, pea;
        cout << "¿Quiere meter los obstaculos manualmente? Pulse 1, sino pulse 0 para aleatorio" << endl;
        cin >> modo;
        if(modo==true){             //si el modo es manual, falta que el usuario pueda clicar donde poner obstaculo
            Mapa mapa(m,n,modo);    //mapa con dimensiones
            vector<Celda> result = mapa.Astar(0,0, 4,4);
            while(true){            //no funciona, no se muestra el mapa
                mapa.visualizar();
                sleep(200);
            }

        }
        else{
            cout << "¿Cuánto porcentaje de obstáculos quiere?" << endl;
            cin >> obs; cout << endl;
            cout << "¿Cuánto porcentaje de peatones quiere?" << endl;
            cin >> pea;
            Mapa mapa2(m,n,modo,obs,pea);
            vector<Celda> result2 = mapa2.Astar(0,0, 4,4);
            while(true){
                mapa2.visualizar();
                sleep(200);
            }
        }
    }
    else if(option == 2){
        QApplication a(argc, argv);

        MainWindow *w = new MainWindow(m,n,new QWidget);

        w -> show();

        return a.exec();
    }
}
