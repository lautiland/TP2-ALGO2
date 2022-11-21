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
    //  Constructores y destructor
        /**
         * pre: -
         * pos: -
         */
        Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo);
        //falta hacer el destructor

    //  Getters
        /**
         * pre: -
         * pos: -
         */
        unsigned int getPosicionX();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getPosicionY();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getPosicionZ();
        /**
         * pre: -
         * pos: -
         */
        Tipo getTipo();
        /**
         * pre: -
         * pos: -
         */
        Celula* getCelula();

    //  Setters
        /**
         * pre: -
         * pos: -
         */
        void setPosicionX(unsigned int nuevaPosicionX);
        /**
         * pre: -
         * pos: -
         */
        void setPosicionY(unsigned int nuevaPosicionY);
        /**
         * pre: -
         * pos: -
         */
        void setPosicionZ(unsigned int nuevaPosicionZ);
        /**
         * pre: -
         * pos: -
         */
        void setTipo(Tipo nuevoTipo);
        /**
         * pre: -
         * pos: -
         */
        void setCelula(Celula nuevaCelula);

    //  Funciones
        /**
         * pre: -
         * pos: -
         */
        void operator=(Celda nuevaCelda);       //esta funcion permite igualar dos celdas y que se copien sus datos
        /**
         * pre: -
         * pos: -
         */
        void actualizarEstadoCelula(unsigned int celulasVecinas, unsigned int x1, unsigned int x2, unsigned int x3);

};

#endif