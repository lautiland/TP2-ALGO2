#ifndef TABLEROH
#define TABLEROH

#include "celda.h"
#include "turno.h"
#include <cstdlib>
#include <ctime>

// SOLO EN VISUAL
#include "celda.cpp"
#include "turno.cpp"

enum ModoDeJuego
{
    manual,
    configuracion1,
    configuracion2,
    configuracion3
};

class Tablero
{
private:
    Lista<Lista<Lista<Celda *> *> *> *tablero;
    Turno *turno;
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
     * pre: se pasa por parametro un tablero existente.
     * pos: se crea una copia del tablero original.
     */
    Tablero(Tablero* taberoOriginal);
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
    Turno* getTurno();
    /**
     * pre: -
     * pos: -
     */
    unsigned int getLargo();
    // se me ocurre poner un metodo que meta las celulas onda setCelulas() que cambie el estado de las celulas a vivas
    // onda que ponga this->estado=Viva, el tema seria ver como hacemos las coordenadas ya que van metidas una por una
    // o se puede hacer un diccionario o array que vaya guardando lo que meta el usuario y despues leerlo y meterlas asi

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
    void contabilizarCasos(Estado aux, Celda *celdaCentro);
    /**
     * pre: -
     * pos: -
     */
    void contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina, Tablero *temp);
    /**
     * pre: -
     * pos: -
     */
    //void operator=(Tablero nuevoTablero);
    unsigned int numeroAleatorio(unsigned int maximo);
    void resolverTurno();
    /**
     * pre: -
     * pos: -
     */
    void imprimirTablero();
    /**
    * pre: -
    * pos: -
    */
    void devolverTablero(unsigned int i, unsigned int j, unsigned int k);
};

#endif /* TABLEROH */
