/*
 * Gen.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "gen.h"

Gen::Gen(unsigned int maximoDeCargaGenetica)
{
    unsigned int cargaVerificada = verificar(maximoDeCargaGenetica, 0);
    this->cargaGenetica = cargaVerificada;
    this->maximoDeCargaGenetica = maximoDeCargaGenetica;
}

Gen::Gen(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica)
{
    unsigned int cargaVerificada = verificar(maximoDeCargaGenetica, cargaGenetica);
    this->maximoDeCargaGenetica = maximoDeCargaGenetica;
    this->cargaGenetica = cargaVerificada;
}

Gen::~Gen() {}

unsigned int Gen::getMaximoDeCargaGenetica()
{
    return this->maximoDeCargaGenetica;
}

unsigned int Gen::getCargaGenetica()
{
    return this->cargaGenetica;
}

void Gen::setCargaGenetica(unsigned int cargaGenetica)
{
    unsigned int cargaVerificada = verificar(this->maximoDeCargaGenetica, cargaGenetica);
    this->cargaGenetica = cargaVerificada;
}

unsigned int Gen::verificar(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica)
{
    if (maximoDeCargaGenetica < 0)
    {
        throw "El maximo de Carga Genetica no puede ser menor a 0";
    }
    if (cargaGenetica < 0)
    {
        cargaGenetica = 0;
    };
    if (maximoDeCargaGenetica < cargaGenetica)
    {
        cargaGenetica = maximoDeCargaGenetica;
    };
    return cargaGenetica;
}