#include "administradorDeGen.h"

//  Constructores y destructores

AdministradorDeGen::AdministradorDeGen(unsigned int maximoDeCargaGenetica)
{
    this->maximoDeCargaGenetica = maximoDeCargaGenetica;
    this->indice = 1;
}

AdministradorDeGen::~AdministradorDeGen()
{
    // TODO Auto-generated destructor stub
}

//  Getters

unsigned int AdministradorDeGen::getIndice()
{
    return this->indice;
};

//  Setters

void AdministradorDeGen::setMasUnoIndice()
{
    if (getIndice() == 4)
    {
        this->indice = 1;
    }
    else
    {
        this->indice = getIndice() + 1;
    }
}

//  Funciones

Gen AdministradorDeGen::generar(unsigned int gen1, unsigned int gen2, unsigned int gen3)
{
    // validar que los gen no sean nulos
    Gen* resultado = new Gen(this->maximoDeCargaGenetica);
    switch (getIndice())
    {
    case 1:
        resultado->setCargaGenetica((gen1 + gen2 + gen3) / 3);
        break;
    case 2:
        resultado->setCargaGenetica((gen1 / 2 + (gen2 % gen3)));
        break;
    case 3:
        resultado->setCargaGenetica((gen1 * 2 - gen2 / 2 + gen3));
        break;
    case 4:
        resultado->setCargaGenetica((gen1 % gen2 / 2 + gen3));
        break;
    };
    setMasUnoIndice();

    return *resultado;
}