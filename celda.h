#ifndef CELDA_H_
#define CELDA_H_

#include "celula.h"
#include "lista.h"

// SOLO EN VISUAL
#include "celula.cpp"

enum Tipo
{
    estandar, // no hace nada
    contaminada,
    envenenada,
    procreadora,
    portal,
    radioactiva
};

class Celda
{
private:
    unsigned int posicionX;
    unsigned int posicionY;
    unsigned int posicionZ;
    Tipo tipo;
    Celula *celula;

public:
    //  Constructores y destructor

    /*
     * pre: -
     * pos: La celda queda habilitada para controlar el acceso de posicionX, posicionY, posicionZ y el Tipo.
     */
    Celda(Celda* nuevaCelda);
    Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo);
    // falta hacer el destructor

    //  Getters

    /**
     * pre: -
     * pos: devuelve el numero de la posicion de fila.
     */
    unsigned int getPosicionX();
    /**
     * pre: -
     * pos: devuelve el numero de la posicion de columna.
     */
    unsigned int getPosicionY();
    /**
     * pre: -
     * pos: devuelve el numero de la posicion de pagina.
     */
    unsigned int getPosicionZ();
    /**
     * pre: -
     * pos: Devuelve el tipo de la celda
     */
    Tipo getTipo();
    /**
     * pre: -
     * pos: Devuelve un puntero a celula.
     */
    Celula *getCelula();

    //  Setters
    /**
     * pre: nuevaPosicionX debe ser mayor a 0.
     * pos: Actualiza el numero de la posicion de la Fila.
     */
    void setPosicionX(unsigned int nuevaPosicionX);
    /**
     * pre: nuevaPosicionY debe ser mayor a 0.
     * pos: Actualiza el numero de la posicion de la Columna.
     */
    void setPosicionY(unsigned int nuevaPosicionY);
    /**
     * pre: nuevaPosicionZ debe ser mayor a 0.
     * pos: Actualiza el numero de la posicion de la Pagina.
     */
    void setPosicionZ(unsigned int nuevaPosicionZ);
    /**
     * pre: -
     * pos: Actualiza el tipo de celda.
     */
    void setTipo(Tipo nuevoTipo);
    /**
     * pre: -
     * pos: Actualiza el puntero Celula a una nueva celula.
     */
    void setCelula(Celula nuevaCelula);

    //  Funciones
    /**
     * pre: -
     * pos: iguala dos celdas (copia los datos de una Celda con otra pasada por parametro)
     */
    //void operator=(Celda nuevaCelda); // esta funcion permite igualar dos celdas y que se copien sus datos
    /**
     * pre: -
     * pos: -
     */
    void actualizarEstadoCelula(unsigned int celulasVecinas, unsigned int x1, unsigned int x2, unsigned int x3, Lista<Celda *> *listaVecinasVivas);
    /**
     * pre: -
     * pos: -
     */
    void actualizaGenesCelula(Lista<Celda *> *listaVecinasVivas);
};

#endif
