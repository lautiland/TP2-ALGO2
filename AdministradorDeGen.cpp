/*
 * AdministradorDeGen.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "AdministradorDeGen.h"

AdministradorDeGen::AdministradorDeGen(unsigned int maximoDeCargaGenetica) {
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
}

AdministradorDeGen::~AdministradorDeGen() {
	// TODO Auto-generated destructor stub
}

Gen * AdministradorDeGen::generar(Gen * gen1, Gen * gen2, Gen * gen3) {
	//validar que los gen no sean nulos
	Gen * resultado = new Gen(this->maximoDeCargaGenetica);
	resultado->setCargaGenetica((gen1->getCargaGenetica() + gen2->getCargaGenetica() + gen3->getCargaGenetica()) / 3);
	return resultado;
}