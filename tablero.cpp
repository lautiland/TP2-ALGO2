#include "Tablero.h"

//las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(unsigned int largo, unsigned int ancho, unsigned int alto) {


    this->tablero = new Lista<Lista<Lista<Celda*>*>*>();


    for(int k = 0; k < alto; k++){     // va rellenando el tablero

        Lista<Lista<Celda*>*>* pagina = new Lista<Lista<Celda*>*>();    //crea la pagina 
        
        for(int j = 0; j < ancho; j++){     // va rellenando las paginas

            Lista<Celda*>* columna = new Lista<Celda*>();  // crea la columna

            for(int i = 0; i < largo; i++){      // va rellenando las columnas

                Celda* fila = new Celda(i, j, k, estandar);     // crea la fila

                columna->agregar(fila); // agrega la fila a la columna

            }
            
            pagina->agregar(columna); //agregar la columna a la página

        }

        this->tablero->agregar(pagina);     // agrega la página al tablero

    }

}

Tablero::~Tablero(){
    this->tablero->iniciarCursor();
    while(this->tablero->avanzarCursor()){
        Lista<Lista<Celda> > temp = this->tablero->obtenerCursor();
        temp->iniciarCursor();
        while(temp->avanzarCursor()){
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->tablero;


}