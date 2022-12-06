#ifndef TABLEROH
#define TABLEROH

#include "celda.h"
#include "turno.h"
#include <cstdlib>
#include <ctime>

// SOLO EN VISUAL
//#include "celda.cpp"
//#include "turno.cpp"

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
    Lista<Lista<Lista<Celda *> *> *> *matriz;
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
     * pre: configuracion debe estar definido.
     * pos: inicializa el tablero con su respectiva configuracion.
     */
    Tablero(ModoDeJuego configuracion);

    /**
     * pre: tableroOriginal debe estar definido y debe ser no vacio.
     * pos: se crea una copia del tablero original.
     */
    Tablero(Tablero* taberoOriginal);

    /**
     * pre: el tablero debe estar definido y no debe ser vacio.
     * pos: destruye el tablero creado.
     */
    ~Tablero();


    //  Getters

    /**
     * pre: la matriz debe estar creada e inicializada.
     * pos: devuelve un puntero a la matriz.
     */
    Lista<Lista<Lista<Celda *> *> *> *getTablero();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas necesarias para que una celula nazca.
     */
    unsigned int getX1();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas vivas necesarias para que muera por soledad.
     */
    unsigned int getX2();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas vivas necesarias para que muera por sobrepoblacion.
     */
    unsigned int getX3();

    /**
     * pre: -
     * pos: devuelve el numero de paginas del tablero.
     */
    unsigned int getAlto();

    /**
     * pre: -
     * pos: devuelve el numero de columnas del tablero.
     */
    unsigned int getAncho();

    /**
     * pre: -
     * pos: devuelve el numero de filas del tablero.
     */
    unsigned int getLargo();

    /**
     * pre: turno no debe ser nulo.
     * pos: devuelve un puntero a turno.
     */
    Turno* getTurno();
    

    //  Setters

    /**
     * pre: configuracion no debe ser nulo.
     * pos: configura los distintos modos de juego.
     */
    void setConfiguracion(ModoDeJuego configuracion);


    //  Funciones

    /**
     * pre: la matriz debe estar definida y no debe estar vacia.
     * pos: por medio de consola se ingresan las celulas que empezaran el juego como vivas.
     */
    void definirCelulasVivas();

    /**
     * pre: aux y celdaCentro no deben ser nulos.
     * pos: define los nacimientos y muertes del turno.
     */
    void contabilizarCasos(Estado aux, Celda *celdaCentro);

    /**
     * pre: maximo debe ser positivo.
     * pos: devuelve un numero random positivo con un maximo.
     */
    unsigned int numeroAleatorio(unsigned int maximo);

    /**
     * pre: fila, columna y pagina deben estar entre 0 y sus respectivos maximos.
     * pos: analiza y cuenta la celulas vecinas que estan vivas respecto de una celula central. tambien actualizara los estados
     * de las celulas dentro de un tablero temporario.
     */
    void contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina, Tablero *temp);

    /**
     * pre: el tablero debe estar inicializado y la matriz no debe estar vacia.
     * pos: realiza la accion del turno, recorriendo toda la matriz.
     */
    void resolverTurno();

    /**
     * pre: la matriz tiene que estar inicializada y no vacia.
     * pos: muestra en consola el tablero, pagina por pagina.
     */
    void imprimirTablero();

    /**
    * pre: i, j y k deben ser mayores a 0 y menores a sus respectivos maximos.
    * pos: imprime un valor depende del estado de la celula en la posicion ingresada.
    */
    void devolverTablero(unsigned int i, unsigned int j, unsigned int k);


    //  Condiciones

    /**
    * pre: -
    * pos: devuelve true si la matriz del tablero esta vacia y false si no lo esta.
    */
    bool matrizVacia();
};

#endif /* TABLEROH */
