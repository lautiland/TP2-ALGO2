#include <iostream>
#include "principal.h"
using namespace std;

void bienvenida(){
    cout << endl << endl;
    cout << "       ______ _     _                              _        _               _     _       " << endl;
    cout << "      |  ____| |   (_)                            | |      | |             (_)   | |      " << endl;
    cout << "      | |__  | |    _ _   _  ___  __ _  ___     __| | ___  | | __ _  __   ___  __| | __ _ " << endl;
    cout << "      |  __| | |   | | | | |/ _ \\/ _` |/ _ \\   / _` |/ _ \\ | |/ _` | \\ \\ / / |/ _` |/ _` |" << endl;
    cout << "      | |____| |   | | |_| |  __/ (_| | (_) | | (_| |  __/ | | (_| |  \\ V /| | (_| | (_| |" << endl;
    cout << "      |______|_|   | |\\__,_|\\___|\\__, |\\___/   \\__,_|\\___| |_|\\__,_|   \\_/ |_|\\__,_|\\__,_|" << endl;
    cout << "                  _/ |            __/ |                                                   " << endl;
    cout << "                 |__/            |___/                                                    " << endl;
    cout << endl << endl << endl;
}

void resolverTurno(Tablero* tablero){
    for (unsigned int i = 0; i < tablero->getLargo(); i++){
        for (unsigned int j = 0; j < tablero->getAncho(); j++){
            for (unsigned int k = 0; k < tablero->getAlto(); k++){
                tablero->contadorCelulasVecinas(i, j, k);
            }   
        }
    }
}
ModoDeJuego configurar(){
    ModoDeJuego configuracion;
    int opcion;
    cout << "Elija una configuracion para las dimensiones del Tablero:" << endl;
    cout << "1: Configuracion manual."<< endl;
    cout << "2: Tablero de 5x5x5 con estandares bajos de generacion de celulas."<< endl;
    cout << "3: Tablero de 10x10x10 con estandares medios de generacion de celulas."<< endl;
    cout << "4: Tablero de 20x20x20 con estandares altos de generacion de celulas."<< endl << endl;
    cin >> opcion;
    cout << endl;

    switch (opcion){
    case 1:
        configuracion = manual;
        break;
    case 2:
        configuracion = configuracion1;
        break;
    case 3:
        configuracion = configuracion2;
        break;
    case 4:
        configuracion = configuracion3;
        break;
    default:
        break;
    }
    return configuracion;
}

int main (){

    bienvenida();

    Tablero* partida = new Tablero(configurar());

    partida->definirCelulasVivas();

    cout << "fin";

    partida->~Tablero();

    return 0;

}