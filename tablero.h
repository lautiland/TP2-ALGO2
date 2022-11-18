#ifndef TABLEROH
#define TABLEROH

#include "Lista.h"
#include "Celda.h"

class Tablero
{
private:
    Lista<Lista<Lista<Celda *> *> *> *tablero;

public:
    Tablero(unsigned int largo, unsigned int ancho, unsigned int alto);
    Lista<Lista<Lista<Celda *> *> *> *getTablero();
    ~Tablero();
};

#endif /* TABLEROH */