
#include "malla.h"

Celda ** Malla::getCursor(){ //devuelve un int xd;
    Celda ** pcursor;
    pcursor = &cursor;
    return pcursor;
}

Dimension Malla::getEspacio(){
    return espacio;
}

void Malla::setEspacio(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho){
    espacio.setAlto(nuevoAlto);
    espacio.setLargo(nuevoLargo);
    espacio.setAncho(nuevoAncho);
}

void Malla::setCursor(unsigned int nuevoCursor){
    this->cursor = nuevoCursor;
}

void Malla::setCursor(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho){
    this->cursor = ((z * getAlto() * getLargo()) + (y * getLargo()) + x);
}

void Malla::Malla(){


    *getCursor() = new Celda[getEspacio().getMaximo()];
    

    setLargo();
    setAncho();
    setAlto();

    for (int pagina = 0; pagina < getAncho(); ++pagina)
    {
        for (int columna = 0; columna < getLargo(); ++columna)
       {
            for (int fila = 0; fila < getAlto(); ++fila)
            {   
                   matriz[ pagina*getAlto()*getLargo + columna*getLargo + fila ] = Celda(fila, columna, pagina);
            }
        }
    }

}