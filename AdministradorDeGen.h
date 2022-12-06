#ifndef ADMINISTRADORDEGENH
#define ADMINISTRADORDEGENH

#include "Gen.h"

//SOLO EN VISUAL
//#include "gen.cpp"

class AdministradorDeGen
{

private:
    unsigned int maximoDeCargaGenetica;
    unsigned int indice;

public:
    //  Constructores y destructor
        /**
         * pre: maximoDeCargaGenetica tiene que ser mayor a 0.
         * pos: setea el indice en 1 y el maximo de la carga genetica
         */
        AdministradorDeGen(unsigned int maximoDeCargaGenetica);

        /**
         * pre: -
         * pos: elimina la memoria dinamica del administrador de gen.
         */
        virtual ~AdministradorDeGen();

    //  Getters

        /**
         * pre: -
         * pos: devuelve el indice del aministrador de gen
         */
        unsigned int getIndice();

    //  Setters
        /**
         * pre: -
         * pos: le suma 1 a el indice del administrador de gen
         */
        void setMasUnoIndice();

    //  Funciones
    /**
     * pre: que los genes no sean nulos
     * pos: devuelve un gen con maximoDeCargaGenetica en "maximoDeCargaGenetica" y cargaGenetica como el promedio
     */
    Gen generar(unsigned int gen1, unsigned int gen2, unsigned int gen3);


};

#endif /* ADMINISTRADORDEGENH */
