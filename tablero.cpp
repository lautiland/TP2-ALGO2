#include <iostream>
#include "Tablero.h"

using namespace std;

//las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(unsigned int largo, unsigned int ancho, unsigned int alto)
{

    this->tablero = new Lista<Lista<Lista<Celda *> *> *>();

    for (int k = 0; k < alto; k++)
    { // va rellenando el tablero

        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>(); // crea la pagina

        for (int j = 0; j < ancho; j++)
        { // va rellenando las paginas

            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna

            for (int i = 0; i < largo; i++)
            { // va rellenando las columnas

                Celda *fila = new Celda(i, j, k, estandar); // crea la fila

                columna->agregar(fila); // agrega la fila a la columna
            }

            pagina->agregar(columna); // agregar la columna a la página
        }

        this->tablero->agregar(pagina);     // agrega la página al tablero

    }

}

Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero()
{
    return this->tablero;
};

void Tablero::setDimensiones(){
    //la idea es que el usuario ponga 2 o 3, que serian las cofig automaticas y la 1 seria la manual
    //es medio a lo bruto este metodo pero lo puedo pulir si es necesario, es lo primero que se me ocurrió
    //los numeros que ponemos en los modos automaticos pueden ir en constantes globales ahora que lo pienso
    int configuracion;
    cout << "Elija una configuración para las dimensiones del Tablero." << endl;
    cout << "1: Configuración manual."<< endl;
    cout << "2: Tablero de 5x5x5."<< endl;
    cout << "3: Tablero de 10x10x10."<< endl;
    cin >> configuracion;
    switch(configuracion){
        case 1:
            int alto, ancho, largo;
            cout << "Ingrese el alto del tablero deseado: " << endl;
            cin >> alto;
            cout << "Ingrese el ancho del tablero deseado: " << endl;
            cin >> ancho;
            cout << "Ingrese el largo del tablero deseado: " << endl;
            cin >> largo;
            this->alto = alto;
            this->ancho = ancho;
            this->largo = largo;
            break;
        case 2:
            this->alto = 5;
            this->ancho = 5;
            this->largo = 5;
            break;
        case 3:
            this->alto = 10;
            this->ancho = 10;
            this->largo = 10;
            break;
    }
   
    
}

unsigned int Tablero::getAlto(){
    return this->alto;
}

unsigned int Tablero::getAncho(){
    return this->ancho;
}

unsigned int Tablero::getLargo(){
    return this->largo;
}

Tablero::~Tablero()
{
    this->tablero->iniciarCursor();
    while(this->tablero->avanzarCursor()){
        Lista<Lista<Celda*>*>* temp = this->tablero->obtenerCursor();
        temp->iniciarCursor();
        while(temp->avanzarCursor()){
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->tablero;


}