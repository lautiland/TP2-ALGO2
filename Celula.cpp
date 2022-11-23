#include "celula.h"
#include <iostream>

//  Constructores y destructor

Celula::Celula(Estado estado = muerto, unsigned int gen1 = 0, unsigned int gen2 = 0, unsigned int gen3 = 0){

    this->gen1 = new Gen(255, gen1);
    this->gen2 = new Gen(255, gen2);
    this->gen3 = new Gen(255, gen3);

    setEstado(estado);

}

//  Getters

Estado Celula::getEstado(){
    return estado;
}
unsigned int Celula::getGen1(){
    return this->gen1->getCargaGenetica();
}
unsigned int Celula::getGen2(){
    return this->gen2->getCargaGenetica();
}
unsigned int Celula::getGen3(){
    return this->gen3->getCargaGenetica();
}

//  Setters

void Celula::setEstado(Estado nuevoEstado = muerto){
    this->estado = nuevoEstado;
    if (nuevoEstado == muerto){
        setGen1(0);
        setGen2(0);
        setGen3(0);
    }else{
        setGen1(127);
        setGen2(127);
        setGen3(127);
    }
}
void Celula::setGen1(unsigned int nuevoGen1 = 0){
    this->gen1->setCargaGenetica(nuevoGen1);
}
void Celula::setGen2(unsigned int nuevoGen2 = 0){
    this->gen2->setCargaGenetica(nuevoGen2);
}
void Celula::setGen3(unsigned int nuevoGen3 = 0){
    this->gen3->setCargaGenetica(nuevoGen3);
}

//  Funciones

void Celula::mezclarGenes(){            // agregar lo del archivo AdministradorDeGen.h

}
void Celula::operator=(Celula nuevaCelula){         //esta funcion permite igualar dos celulas y que se copien los datos
    setEstado(nuevaCelula.getEstado());
    setGen1(nuevaCelula.getGen1());
    setGen2(nuevaCelula.getGen2());
    setGen3(nuevaCelula.getGen3());
}