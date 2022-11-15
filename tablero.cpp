#include "Tablero.h"
#define N 5
#define M 5
#define L 5

//las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(unsigned int alto, unsigned int ancho, unsigned int largo) {
    alto=N;
    ancho=M;
    largo=L;

    this->tablero = new Lista<Lista<Lista<Celda*>*>*>();
    for(int i=0; i<N; i++){
        //Lista<Lista<Celda> >* temp1 = new Lista<Lista<Celda>>();
        tablero->agregar(new Lista<Lista<Celda*>*>);
        for(int j=0; j<M; j++){
            //temp-> agregar(new Lista<Celda>)
            Lista<Celda>* temp2 = new Lista<Celda>();
            for(int k=0; k<L, k++){
                temp2-> agregar(new Celda(Celula()));

            }
        }
        this->tablero->agregar(temp);
    }

    for(int i = 0; i < N; i++){

        Lista<Lista<Celda*>*>* temp1 = new Lista<Lista<Celda*>*>();

        for(int j = 0; j < M; j++){

            Lista<Celda*>* temp2 = new Lista<Celda*>();

            for(int k = 0; k < L; k++){

                temp2-> agregar(new Celda());

            }

            temp1-> agregar(temp2);

        }

        this->tablero->agregar(temp1);

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