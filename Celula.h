#ifndef CELULA_H_
#define CELULA_H_

#include "administradorDeGen.h"

//SOLO EN VISUAL

#include "administradorDeGen.cpp"

enum Estado{
    vivo = 0,
    muerto = 1
};

class Celula{
    private:
        Estado estado;
        Gen* gen1;
        Gen* gen2;
        Gen* gen3;

    public:
        //  Constructores y destructor
            /**
             * pre: -
             * pos: -
             */
            Celula(Estado estado, unsigned int gen1, unsigned int gen2, unsigned int gen3);
            
            //falta hacer el destructor

        //  Getters
            /**
             * pre: -
             * pos: -
             */
            Estado getEstado();
            /**
             * pre: -
             * pos: -
             */
            unsigned int getGen1();
            /**
             * pre: -
             * pos: -
             */
            unsigned int getGen2();
            /**
             * pre: -
             * pos: -
             */
            unsigned int getGen3();
              /**
             * pre: -
             * pos: -
             */

            int getEstadoInt();

            //  Setters
            /**
             * pre: -
             * pos: -
             */
            void setEstado(Estado nuevoEstado);
            /**
             * pre: -
             * pos: -
             */
            void setGen1(unsigned int nuevoGen1);
            /**
             * pre: -
             * pos: -
             */
            void setGen2(unsigned int nuevoGen2);
            /**
             * pre: -
             * pos: -
             */
            void setGen3(unsigned int nuevoGen3);
        
        //  Funciones
            
            /**
             * pre: -
             * pos: -
             */
            void mezclarGenes();

            /**
             * pre: -
             * pos: -
             */
            void operator=(Celula nuevaCelula);

            
};

#endif