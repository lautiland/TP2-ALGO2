#ifndef CELULA_H_
#define CELULA_H_

#include "AdministradorDeGen.h"

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

            ~Celula();

        //  Getters
            /**
             * pre: -
             * pos: devuelve el estado de la celula.
             */
            Estado getEstado();
            /**
             * pre: -
             * pos: devuelve el valor de carga genetica del primer gen.
             */
            unsigned int getGen1();
            /**
             * pre: -
             * pos: devuelve el valor de carga genetica del segundo gen.
             */
            unsigned int getGen2();
            /**
             * pre: -
             * pos: devuelve el valor de carga genetica del tercer gen.
             */
            unsigned int getGen3();

            //  Setters

            /**
             * pre: -
             * pos: define el estado de la celula.
             */
            void setEstado(Estado nuevoEstado);
            /**
             * pre: -
             * pos: define el valor del primer gen de la celula.
             */
            void setGen1(unsigned int nuevoGen1);
            /**
             * pre: -
             * pos: define el valor del segundo gen de la celula.
             */
            void setGen2(unsigned int nuevoGen2);
            /**
             * pre: -
             * pos: define el valor del tercer gen de la celula.
             */
            void setGen3(unsigned int nuevoGen3);

        //  Funciones

            /**
             * pre: -
             * pos: mezcla los genes.
             */
            void mezclarGenes();



};

#endif
