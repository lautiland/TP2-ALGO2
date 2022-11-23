#include <iostream>
#include "principal.h"
using namespace std;

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
    cout << "Elija una configuración para las dimensiones del Tablero." << endl;
    cout << "1: Configuración manual."<< endl;
    cout << "2: Tablero de 5x5x5 con estandares bajos de generación de células."<< endl;
    cout << "3: Tablero de 10x10x10 con estandares medios de generación de células."<< endl;
    cout << "4: Tablero de 20x20x20 con estandares altos de generación de células."<< endl;
    cin >> opcion;

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

    Tablero* partida = new Tablero(configurar());

    partida->definirCelulasVivas();

    

    cout << "fin";

    partida->~Tablero();

    return 0;

}