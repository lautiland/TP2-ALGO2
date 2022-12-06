#include "celula.h"
#include <iostream>

//  Constructores y destructor

Celula::Celula(Estado estado = muerto, unsigned int gen1 = 0, unsigned int gen2 = 0, unsigned int gen3 = 0){

    this->gen1 = new Gen(255, gen1);
    this->gen2 = new Gen(255, gen2);
    this->gen3 = new Gen(255, gen3);

    setEstado(estado);

}

Celula::~Celula(){
    delete this->gen1;
    delete this->gen2;
    delete this->gen3;
}

//  Getters

Estado Celula::getEstado(){
    return this->estado;
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
        this->setGen1(0);
        this->setGen2(0);
        this->setGen3(0);
    }else{
        this->setGen1(127);
        this->setGen2(127);
        this->setGen3(127);
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

