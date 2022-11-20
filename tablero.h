#ifndef TABLEROH
#define TABLEROH

#include "Lista.h"
#include "Celda.h"

class Tablero
{
private:
    Lista<Lista<Lista<Celda *> *> *> *tablero;
    unsigned int alto;
    unsigned int largo;
    unsigned int ancho;

public:
    //  Constructores y destructores
        /**
         * pre: -
         * pos: -
         */
        Tablero(unsigned int largo, unsigned int ancho, unsigned int alto);
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
        void setDimensiones();
    
    //  Funciones
        /**
         * pre: -
         * pos: -
         */
        void contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina , unsigned int x1, unsigned int x2, unsigned int x3);

};

#endif /* TABLEROH */