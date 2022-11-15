#ifndef TABLEROH
#define TABLEROH

#include "Lista.h"
#include "Celda.h"

class Tablero {
private:
    Lista < Lista < Lista < Celda* > * > * > * tablero;
    
public:
    Tablero(unsigned int alto, unsigned int ancho, unsigned int largo);
    ~Tablero();
};




#endif /* TABLEROH */