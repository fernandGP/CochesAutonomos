#include "../headers/mapa.h"

void Mapa::addObstaculos(bool mod){

    if(mod){                                                            //Modo guiado
        int x, y;
        ifstream InputFile;
        InputFile.open ("coordenadas.txt", ios::in);

        while(!InputFile.eof()){
            InputFile >> x >> y;
            if(x < 0 || y < 0 || static_cast<unsigned int>(x) >= rejilla_.size() || static_cast<unsigned int>(y) >= rejilla_[0].size()){
                //Out of borders control
                throw initException();
            }
            rejilla_[static_cast<unsigned int>(x)][static_cast<unsigned int>(y)].setValor(1);
        }
        InputFile.close();
    }
    else{       //Asignación automática
        srand(static_cast<unsigned int>(time(nullptr)));
        for(unsigned int i = 0; i < rejilla_.size(); i++){
            for(unsigned int j = 0; j < rejilla_[i].size(); j++){
                if(rand()%100 < porcentajeObstaculos_)  rejilla_[i][j].setValor(1);
            }
        }
    }
}

void Mapa::addPeatones(){}

void Mapa::setVecinos(){        //Definitivamente necesitamos que sean enteros normales, asi que... C++11 type-cast
    for(int i = 0; static_cast<unsigned int>(i) < rejilla_.size(); i++){
        for(int j = 0; static_cast<unsigned int>(j) < rejilla_[static_cast<unsigned int>(i)].size(); j++){
            if(rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].getValor() != 1){
                if(i-1 >= 0){
                    if(rejilla_[static_cast<unsigned int>(i-1)][static_cast<unsigned int>(j)].getValor() != 1){
                        rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].addVecino(rejilla_[static_cast<unsigned int>(i-1)][static_cast<unsigned int>(j)]);
                    }
                }
                if(static_cast<unsigned int>(i+1) < rejilla_.size()){
                    if(rejilla_[static_cast<unsigned int>(i+1)][static_cast<unsigned int>(j)].getValor() != 1){
                        rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].addVecino(rejilla_[static_cast<unsigned int>(i+1)][static_cast<unsigned int>(j)]);
                    }
                }
                if(j-1 >= 0){
                    if(rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j-1)].getValor() != 1){
                        rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].addVecino(rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j-1)]);
                    }
                }
                if(static_cast<unsigned int>(j+1) < rejilla_[static_cast<unsigned int>(i)].size()){
                    if(rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j+1)].getValor() != 1){
                        rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j)].addVecino(rejilla_[static_cast<unsigned int>(i)][static_cast<unsigned int>(j+1)]);
                    }
                }
            }
        }
    }
}

int Mapa::fHeuristica(const Celda& i, const Celda& f){
    return (int)(sqrt(pow((i.getX() - f.getX()),2) + pow((i.getY() - f.getY()), 2)));        //Distancia euclídea, trust me
}

Mapa::Mapa(int x, int y, int pObst, int nPeatones):x_(x), y_(y){

    if(pObst < 0) porcentajeObstaculos_ = CONST_P_OBSTACULOS;
    else porcentajeObstaculos_ = pObst;

    if(nPeatones < 0) nPeatones_ = CONST_N_PEATONES;
    else nPeatones_ = nPeatones;

    try {
        for(int i = 0; i < x_; i++){
            vector<Celda> vectorY;
            for(int j = 0; j < y_; j++){
                Celda aux(i, j);
                vectorY.push_back(aux);
            }
            rejilla_.push_back(vectorY);
        }
    } catch (initException &e) {
           throw e;
    }

    addObstaculos(false);
    addPeatones();

    setVecinos();
}

Mapa::~Mapa(){}

vector<vector<Celda> >& Mapa::getsetRejilla(){ return rejilla_; }

void Mapa::visualizar(){

    try {
        for(unsigned int i = 0; i < rejilla_.size(); i++){
            cout << "|";
            for (unsigned int j = 0; j < rejilla_[i].size(); j++){
                rejilla_[i][j].visualizar();
            }
            cout << "|" << endl;
        }
    } catch (oobException &e) {
        throw e;                    //Re-throws exception to upper calling method
    }

}

bool Mapa::is_in_set(const Celda& c, const std::vector<Celda>& s){
    for(int i = 0; i < s.size(); i++)
        if(s[i].getX()==c.getX() && s[i].getY()==c.getY())
            return true;

    return false;
}

void Mapa::reconstruir_camino(vector<Celda> &v, Celda actual, Celda I){
    Celda a = actual;
    v.push_back(a);
    while(a.getX() != I.getX() || a.getY() != I.getY()){           //Mientras no llegue a la celda inicial
        a = rejilla_[static_cast<unsigned int>(a.getPadre().first)][static_cast<unsigned int>(a.getPadre().second)];
        v.push_back(a);
    }
}

vector<Celda> Mapa::Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal){

    vector<Celda> result;                                               // Almacena el camino optimo
    vector<Celda> setAbierto;
    vector<Celda> setCerrado;

    Celda& Inicial = rejilla_[xInicio][yInicio];
    Celda& Final = rejilla_[xFinal][yFinal];

    Inicial.setg_(0);                                                   //Cambiamos valores heuristicos de la primera Celda
    Inicial.setf_(fHeuristica(Inicial, Final));

    setAbierto.push_back(Inicial);                                      //Setup completada

    while(!setAbierto.empty()){
        unsigned int winner = 0;
        for(unsigned int i = 0; i < setAbierto.size(); i++){            //Se busca la Celda con menor f_valor
            if(setAbierto[i].getf_() < setAbierto[winner].getf_())
                winner = i;
        }

        //Celda copia a la que tenemos en la rejilla y en el set.
        Celda actual = rejilla_[setAbierto[winner].getX()][setAbierto[winner].getY()];

        if((actual.getX() == xFinal) && (yFinal == actual.getY())){     //Es la misma celda -> Hemos llegado al final con camino óptimo

            reconstruir_camino(result, actual, Inicial);
            return result;
        }

        setAbierto.erase(setAbierto.begin() + winner);                  //Cambiamos actual de set
        setCerrado.push_back(actual);

        for(int i = 0; i < actual.sizeVecinos(); i++){                  //Miramos los vecinos de la Celda actual
            int x = actual.getVecino(i).first;
            int y = actual.getVecino(i).second;
            Celda vecino = rejilla_[x][y];                              //Valor copia de la Celda vecina

            if(is_in_set(vecino, setCerrado))
                continue;

            int tent_g = actual.getg_() + 1;

            if(!is_in_set(vecino, setAbierto)){
                setAbierto.push_back(vecino);
            }
            else if(tent_g >= vecino.getg_())
                continue;

            //Este camino es el mejor! Guárdalo
            rejilla_[vecino.getX()][vecino.getY()].setPadre(actual);
            rejilla_[vecino.getX()][vecino.getY()].setg_(tent_g);
            rejilla_[vecino.getX()][vecino.getY()].setf_(tent_g + fHeuristica(vecino, Final));
        }
    }

    return result;                                                      //Si revisa todas las celdas posibles y no ve nada,
                                                                        //el problema no tiene solución
}

void Mapa::caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal){

    vector<Celda> result = Astar(xInicio, yInicio, xFinal, yFinal);

    for(unsigned int i = 0; i < result.size(); i++){
        //cout << "(" << result[i].getX() << "," << result[i].getY() << ")" << endl;
        rejilla_[result[i].getX()][result[i].getY()].setValor(2);
    }

    cout << "\n\n" << endl;

    visualizar();
}
