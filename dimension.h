#ifndef DIMENSION_H_
#define DIMENSION_H_

class Dimension{
    private:
        unsigned int MAXIMO;
        unsigned int ALTO;
        unsigned int LARGO;
        unsigned int ANCHO;

    public:
    //  Constructores
        Dimension(unsigned int ALTO, unsigned int LARGO, unsigned int ANCHO);

    //  Getters
        unsigned int getMaximo();
        unsigned int getAlto();
        unsigned int getLargo();
        unsigned int getAncho();

    //  Setters
        void setMaximo();
        void setAlto(unsigned int nuevoAlto);
        void setLargo(unsigned int nuevoLargo);
        void setAncho(unsigned int nuevoAncho);

};

#endif