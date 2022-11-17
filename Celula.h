#ifndef CELULA_H_
#define CELULA_H_

#include "gen.h"

enum Estado{
    vivo,
    muerto
};

class Celula{
    private:
        Estado estado;
        Gen* gen1;
        Gen* gen2;
        Gen* gen3;

    public:
        //  Constructores
        Celula(Estado estado, unsigned int gen1, unsigned int gen2, unsigned int gen3);

        //  Getters
        Estado getEstado();
        unsigned int getGen1();
        unsigned int getGen2();
        unsigned int getGen3();

        //  Setters
        void setEstado(Estado nuevoEstado);
        void setGen1(unsigned int nuevoGen1);
        void setGen2(unsigned int nuevoGen2);
        void setGen3(unsigned int nuevoGen3);
        
        //  Funciones
        void mezclarGenes();
        void operator=(Celula nuevaCelula);

};

#endif