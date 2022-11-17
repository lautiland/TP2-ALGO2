#ifndef TABLEROH
#define TABLEROH

#include "Lista.h"
#include "Celda.h"

class Tablero {
private:
    Lista < Lista < Lista < Celda* > * > * > * tablero;
    
public:
    Tablero(unsigned int largo, unsigned int ancho, unsigned int alto);
    ~Tablero();
};




#endif /* TABLEROH */