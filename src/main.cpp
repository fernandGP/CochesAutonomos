#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
<<<<<<< HEAD
//    int m,n,option;
//    cout << "--Dimensiones mapa--" << endl;
//    cout << "Introduce largo: "; cin >> m; cout << endl;
//    cout << "Introduce ancho:"; cin >> n; cout << endl;
//    cout << "--Modo de Visualización--" << endl;
//    cout << "1. Modo Consola" << endl;
//    cout << "2. Modo Gráfico" << endl;
//    cin >> option;


//    if(option == 1){
//        int obs, pea;
//        cout << "¿Cuánto porcentaje de obstáculos quiere?" << endl;
//        cin >> obs; cout << endl;
//        cout << "¿Cuánto porcentaje de peatones quiere?" << endl;
//        cin >> pea;

//        Mapa map(m,n,obs,pea);
//        map.visualizar();
//        while(true){sleep(200);}
//    }
//    else if(option == 2){
=======
    int m,n,option;
    bool modo;
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
            mapa.caminoMinimo(xInicio, yInicio, xFinal, yFinal);

        } catch (initException &e) {
            cout << e.what() << '\n';
            return -1;
        } catch (oobException &e) {
            cout << e.what() << '\n';
            return -2;
        }
    }
    else if(option == 2){
>>>>>>> 0d3386ce537bd015500db469223ec49177376511
        QApplication a(argc, argv);

        MainWindow *w = new MainWindow(m,n,new QWidget);

        w -> show();

        return a.exec();
<<<<<<< HEAD
//    }
=======
    }

    return 0;
>>>>>>> 0d3386ce537bd015500db469223ec49177376511
}
