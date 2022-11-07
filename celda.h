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
        Celula celula;
        
    public:
    //  Constructores
        Celda();
        Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo, Celula celula);

    //  Getters
        unsigned int getPosicionX();
        unsigned int getPosicionY();
        unsigned int getPosicionZ();
        Tipo getTipo();
        Celula getCelula();

    //  Setters
        void setPosicionX(unsigned int nuevaPosicionX);
        void setPosicionY(unsigned int nuevaPosicionY);
        void setPosicionZ(unsigned int nuevaPosicionZ);
        void setTipo(Tipo nuevoTipo);
        void setCelula(Celula nuevaCelula);

    //  Funciones
    //...
};

#endif