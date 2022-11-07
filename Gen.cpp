/*
 * Gen.cpp
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#include "gen.h"

Gen::Gen(unsigned int maximoDeCargaGenetica) {
	verificar(maximoDeCargaGenetica, 0);
	this->cargaGenetica = 0;
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
}

Gen::Gen(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica) {
	verificar( maximoDeCargaGenetica, cargaGenetica);
	this->maximoDeCargaGenetica = maximoDeCargaGenetica;
	this->cargaGenetica = cargaGenetica;
}

Gen::~Gen() {}

unsigned int Gen::getMaximoDeCargaGenetica(){
	return this->maximoDeCargaGenetica;
}

unsigned int Gen::getCargaGenetica() {
	return this->cargaGenetica;
}

void Gen::setCargaGenetica(unsigned int cargaGenetica) {
	verificar(this->maximoDeCargaGenetica, cargaGenetica);
	this->cargaGenetica = cargaGenetica;
}

void Gen::verificar(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica) {
	if (maximoDeCargaGenetica < 0) {
		//dar error con excepciones
	}
	if (cargaGenetica < 0) {
		//dar error con excepciones
	}
	if (maximoDeCargaGenetica < cargaGenetica) {
		//dar error con excepciones
	}
}