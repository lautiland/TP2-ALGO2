#ifndef CELDA_H_
#define CELDA_H_

#include "celula.h"

enum Tipo{
    estandar, //no hace nada
    contaminada,
    envenenada,
    procreadora,
    portal,
    radioactiva
};

class Celda{
    private:
        unsigned int posicionX;
        unsigned int posicionY;
        unsigned int posicionZ;
        Tipo tipo;
        Celula* celula; 
        
    public:
    //  Constructores
        Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo);

    //  Getters
        unsigned int getPosicionX();
        unsigned int getPosicionY();
        unsigned int getPosicionZ();
        Tipo getTipo();
        Celula* getCelula();

    //  Setters
        void setPosicionX(unsigned int nuevaPosicionX);
        void setPosicionY(unsigned int nuevaPosicionY);
        void setPosicionZ(unsigned int nuevaPosicionZ);
        void setTipo(Tipo nuevoTipo);
        void setCelula(Celula nuevaCelula);

    //  Funciones
        void operator=(Celda nuevaCelda);       //esta funcion permite igualar dos celdas y que se copien sus datos
};

#endif