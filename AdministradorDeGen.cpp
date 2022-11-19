#include "AdministradorDeGen.h"

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
    if (getIndice() == 3)
    {
        this->indice = 1;
    }
    else
    {
        this->indice = getIndice() + 1;
    }
}

//  Funciones

Gen AdministradorDeGen::generar(Gen gen1, Gen gen2, Gen gen3)
{
    // validar que los gen no sean nulos
    Gen* resultado = new Gen(this->maximoDeCargaGenetica);
    switch (getIndice())
    {
    case 1:
        resultado->setCargaGenetica((gen1.getCargaGenetica() + gen2.getCargaGenetica() + gen3.getCargaGenetica()) / 3);
    case 2:
        resultado->setCargaGenetica((gen1.getCargaGenetica() / 2 + gen2.getCargaGenetica()));
    case 3:
        resultado->setCargaGenetica((gen1.getCargaGenetica() * 2 - gen2.getCargaGenetica() / 2 + gen3.getCargaGenetica()));
    };
    setMasUnoIndice();

    return *resultado;
}