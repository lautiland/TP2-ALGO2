#ifndef MALLA_H_
#define MALLA_H_

#include "celda.h"
#include "dimension.h"

class Malla{
    private:
        Dimension espacio;
        Celda * cursor;  // 1 2 3 -> 45(?

    public:
    //  Constructores
        void crearMalla();

    //  Setters
        void setEspacio(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho);
        void setCursor(unsigned int nuevoCursor);//calculo
        void setCursor(unsigned int nuevoLargo, unsigned int nuevoAlto, unsigned int nuevoAncho);//calculo

    //  Getters
        Celda ** getCursor();//devuelve resultado
        Dimension getEspacio();

    //  Funciones
        void aniadirCelula(celula newCelula);

};


#endif