#include <iostream>
#include "tablero.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(ModoDeJuego configuracion)
{
    setConfiguracion(configuracion);

    this->tablero = new Lista<Lista<Lista<Celda *> *> *>();

    for (int k = 0; k < getAlto(); k++)
    { // va rellenando el tablero

        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>(); // crea la pagina

        for (int j = 0; j < getAncho(); j++)
        { // va rellenando las paginas

            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna

            for (int i = 0; i < getLargo(); i++)
            { // va rellenando las columnas

                Celda *fila = new Celda(i, j, k, estandar); // crea la fila

                columna->agregar(fila); // agrega la fila a la columna
            }

            pagina->agregar(columna); // agregar la columna a la página
        }

        this->tablero->agregar(pagina);     // agrega la página al tablero

    }

    for (int i = 0; i < numeroAleatorio(int((getAlto() * getLargo() * getAncho()) % 5)); i++)
    {
        unsigned int x = numeroAleatorio(getAncho());
        unsigned int y = numeroAleatorio(getLargo());
        unsigned int z = numeroAleatorio(getAlto());
        getTablero()->obtener(x)->obtener(y)->obtener(z)->setTipo(Tipo(numeroAleatorio(6)));
    };

}

Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero()
{
    return this->tablero;
};

void Tablero::setConfiguracion(ModoDeJuego configuracion){
    //la idea es que el usuario ponga 2 o 3, que serian las cofig automaticas y la 1 seria la manual
    //es medio a lo bruto este metodo pero lo puedo pulir si es necesario, es lo primero que se me ocurrió
    //los numeros que ponemos en los modos automaticos pueden ir en constantes globales ahora que lo pienso
    switch(configuracion){
        case manual:
            cout << "Ingrese el alto del tablero deseado: " << endl;
            cin >> this->alto;
            cout << "Ingrese el ancho del tablero deseado: " << endl;
            cin >> this->ancho;
            cout << "Ingrese el largo del tablero deseado: " << endl;
            cin >> this->largo;
            cout << "Ingrese la cantidad de células vecinas vivas necesarias para que nazca una célula: " << endl;
            cin >> this->X1;
            cout << "Ingrese la minima cantidad de células vecinas vivas para que se reproduzcan: " << endl;
            cin >> this->X2;
            cout << "Ingrese la minima cantidad de células vecinas vivas para que mueran por soprepoblación: " << endl;
            cin >> this->X3;
            break;

        case configuracion1:
            this->alto = 5;
            this->ancho = 5;
            this->largo = 5;
            this->X1 = 3;
            this->X2 = 2;
            this->X3 = 4;
            break;
        case configuracion2:
            this->alto = 10;
            this->ancho = 10;
            this->largo = 10;
            this->X1 = 4;
            this->X2 = 3;
            this->X3 = 5;
            break;
        case configuracion3:
            this->alto = 20;
            this->ancho = 20;
            this->largo = 20;
            this->X1 = 5;
            this->X2 = 4;
            this->X3 = 6;
            break;
    }
   
    
}

unsigned int Tablero::getX1(){
    return X1;
}

unsigned int Tablero::getX2(){
    return X2;
}

unsigned int Tablero::getX3(){
    return X3;
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

                                                    //posicion de la celda                                     //configuracion de usuario
void Tablero::contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina){  // x1: cels nesesarias para nacer; x2 y x3: cels para permanecer viva; en otro caso mueren
    int vecinasVivas = 0;
    unsigned int vecinaX;
    unsigned int vecinaY;
    unsigned int vecinaZ;

    Celda * celdaCentro = this->tablero->obtener(fila)->obtener(columna)->obtener(pagina);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int k = -1; k < 1; ++k)
            {
                if ((fila + i) == -1){
                    vecinaX = getLargo();
                }else if ((fila + i) == (getLargo() + 1)){
                    vecinaX = 0;
                }else{
                    vecinaX = fila + i;
                }

                if ((columna + i) == -1){
                    vecinaY = getAncho();
                }else if ((columna + i) == (getAncho() + 1)){
                    vecinaY = 0;
                }else{
                    vecinaY = columna + i;
                }

                if ((pagina + i) == -1){
                    vecinaY = getAlto();
                }else if ((pagina + i) == (getAlto() + 1)){
                    vecinaY = 0;
                }else{
                    vecinaY = pagina + i;
                }
                
                if (!(i == 0 && j == 0 && k == 0)){
                    if (this->tablero->obtener(vecinaX)->obtener(vecinaY)->obtener(vecinaZ)->getCelula()->getEstado() == vivo){
                        vecinasVivas++;
                    }
                }

            }

        }
    }

    celdaCentro->actualizarEstadoCelula(vecinasVivas, getX1(), getX2(), getX3());
}

unsigned int numeroAleatorio(int maximo)
{
    srand(time(NULL));
    return rand() % maximo + 1;
};