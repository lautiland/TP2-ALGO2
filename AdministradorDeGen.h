#ifndef ADMINISTRADORDEGENH
#define ADMINISTRADORDEGENH
#include "Gen.h"
class AdministradorDeGen
{

private:
    unsigned int maximoDeCargaGenetica;
    unsigned int indice;

public:
    //  Constructores y destructor
        /**
         * pre:
         * pos:
         */
        AdministradorDeGen(unsigned int maximoDeCargaGenetica);

        /**
         * pre: -
         * pos: -
         */
        virtual ~AdministradorDeGen();

    //  Getters
        /**
         * pre: -
         * pos: -
         */
        unsigned int getIndice();

    //  Setters
        /**
         * pre: -
         * pos: -
         */
        void setMasUnoIndice();

    //  Funciones
    /**
     * pre: que los genes no sean nulos
     * pos: devuelve un gen con maximoDeCargaGenetica en "maximoDeCargaGenetica" y cargaGenetica como el promedio
     */
    Gen generar(Gen gen1, Gen gen2, Gen gen3);

    
};

#endif /* ADMINISTRADORDEGENH */