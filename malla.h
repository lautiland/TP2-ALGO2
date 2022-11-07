#ifndef MALLA_H_
#define MALLA_H_

#include "celda.h"
#include "dimension.h"

class Malla{
    private:
        Dimension espacio;
        Celda * cursor;

    public:
    //  Constructores
        Malla();

    //  Getters
        Celda ** getCursor();       //devuelve resultado
        Dimension getEspacio();

    //  Setters
        void setEspacio(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho);
        void setCursor(unsigned int nuevoCursor);//calculo
        void setCursor(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho);//calculo

    //  Funciones
        void agregarCelula(Celula newCelula);

};


#endif