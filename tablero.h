#ifndef TABLEROH
#define TABLEROH

#include "Lista.h"
#include "Celda.h"
#include <cstdlib>
#include <ctime>

//SOLO EN VISUAL
#include "celda.cpp"

enum ModoDeJuego{
    manual,
    configuracion1,
    configuracion2,
    configuracion3
};

class Tablero
{
private:
    Lista<Lista<Lista<Celda *> *> *> *tablero;
    unsigned int alto;
    unsigned int largo;
    unsigned int ancho;
    unsigned int X1;
    unsigned int X2;
    unsigned int X3;

public:
    //  Constructores y destructores
        /**
         * pre: -
         * pos: -
         */
        Tablero(ModoDeJuego configuracion);
        /**
         * pre: -
         * pos: -
         */
        ~Tablero();

    //  Getters
        /**
         * pre: -
         * pos: -
         */
        Lista<Lista<Lista<Celda *> *> *> *getTablero();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getX1();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getX2();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getX3();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getAlto();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getAncho();
        /**
         * pre: -
         * pos: -
         */
        unsigned int getLargo();
        //se me ocurre poner un metodo que meta las celulas onda setCelulas() que cambie el estado de las celulas a vivas
        //onda que ponga this->estado=Viva, el tema seria ver como hacemos las coordenadas ya que van metidas una por una
        //o se puede hacer un diccionario o array que vaya guardando lo que meta el usuario y despues leerlo y meterlas asi

    //  Setters
        /**
         * pre: -
         * pos: -
         */
        void setConfiguracion(ModoDeJuego configuracion);
    
    //  Funciones
        /**
         * pre: -
         * pos: -
         */
        void definirCelulasVivas();
        /**
         * pre: -
         * pos: -
         */
        void contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina);
        /**
         * pre: -
         * pos: -
         */
        unsigned int numeroAleatorio(unsigned int maximo);
};

#endif /* TABLEROH */