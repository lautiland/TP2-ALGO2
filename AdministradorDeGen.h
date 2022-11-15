#ifndef ADMINISTRADORDEGENH
#define ADMINISTRADORDEGENH
#include "Gen.h"
class AdministradorDeGen
{

private:
    unsigned int maximoDeCargaGenetica;
    unsigned int indice;

public:
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

    /**
     * pre: que los genes no sean nulos
     * pos: devuelve un gen con maximoDeCargaGenetica en "maximoDeCargaGenetica" y cargaGenetica como el promedio
     */
    Gengenerar(Gen gen1, Gen gen2, Gen gen3);
    unsigned int getIndice();
    void setMasUnoIndice();
};

#endif /* ADMINISTRADORDEGENH */