#ifdef _WIN32
  #define WINPAUSE system("pause")
#endif

#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int m,n,option, pasajeros = 1;
    cout << "--Dimensiones mapa--" << endl;
    cout << "Introduce largo: "; cin >> m; cout << endl;
    cout << "Introduce ancho:"; cin >> n; cout << endl;
    cout << "--Modo de Visualizacion--" << endl;
    cout << "1. Modo Consola" << endl;
    cout << "2. Modo Grafico" << endl;
    cin >> option;

    if(option == 1){

        int obs, pea;
        unsigned int xInicio, yInicio, xFinal, yFinal;
        cout << "¿Porcentaje de obstaculos?" << endl;
        cin >> obs; cout << endl;
        cout << "¿Porcentaje de peatones?" << endl;
        cin >> pea;

        try {
            srand(static_cast<unsigned int>(time(nullptr)));

            Mapa mapa(m,n,false,obs,pea);
            mapa.visualizar();
            cout << "\nX Inicio: ";
            cin >> xInicio;
            cout << "\nY Inicio: ";
            cin >> yInicio;
            cout << "\nX Final: ";
            cin >> xFinal;
            cout << "\nY Final: ";
            cin >> yFinal;

            cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Euclidea \n\n";
            mapa.caminoMinimo(xInicio, yInicio, xFinal, yFinal, pasajeros);
            cout << "Pasajeros recogidos: " << pasajeros << endl;
            cout << "Nodos generados: " << mapa.contador << endl;

            mapa.cambiarHeuristica(true);
            pasajeros = 1;
            mapa.contador = 0;

            cout << endl << "\n\nCamino minimo con Funcion Heuristica: Distancia Manhattan \n\n";
            mapa.caminoMinimo(xInicio, yInicio, xFinal, yFinal, pasajeros);
            cout << "Pasajeros recogidos: " << pasajeros << endl;
            cout << "Nodos generados: " << mapa.contador << endl;

            //while(getchar() != '\n');
            WINPAUSE;

        } catch (initException &e) {
            cout << e.what() << '\n';
            return -1;
        } catch (oobException &e) {
            cout << e.what() << '\n';
            return -2;
        }
    }
    else if(option == 2){
        QApplication a(argc, argv);

        MainWindow *w = new MainWindow(m,n,false, 10, 10, new QWidget);

        w -> show();

        return a.exec();
    }

    return 0;
}
