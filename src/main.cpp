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

    if(option == 1){

        int obs, pea;
        cout << "¿Cuánto porcentaje de obstáculos quiere?" << endl;
        cin >> obs; cout << endl;
        cout << "¿Cuánto porcentaje de peatones quiere?" << endl;
        cin >> pea;

        try {
            srand(static_cast<unsigned int>(time(nullptr)));

            Mapa mapa(m,n,false,obs,pea);
            cout << endl << "\n\nCamino mínimo con Funcion Heuristica: Distancia Euclidea \n\n";
            mapa.caminoMinimo(0,0, 19,19);

            cout << endl << "\n\nCamino mínimo con Funcion Heuristica: Distancia Manhattan \n\n";
            Mapa mapaso(m,n,true,obs,pea);
            mapaso.caminoMinimo(0,0,19,19);

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

        MainWindow *w = new MainWindow(m,n,new QWidget);

        w -> show();

        return a.exec();
    }

    return 0;
}
