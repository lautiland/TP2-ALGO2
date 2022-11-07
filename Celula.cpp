#include "celula.h"

//  Constructores

Celula::Celula(Estado estado = muerto, unsigned int gen1 = 0, unsigned int gen2 = 0, unsigned int gen3 = 0){
    setEstado(estado);
    setGen1(gen1);
    setGen2(gen2);
    setGen3(gen3);

}

//  Getters

Estado Celula::getEstado(){
    return estado;
}
unsigned int Celula::getGen1(){
    return gen1.getCargaGenetica();
}
unsigned int Celula::getGen2(){
    return gen2.getCargaGenetica();
}
unsigned int Celula::getGen3(){
    return gen3.getCargaGenetica();
}

//  Setters

void Celula::setEstado(Estado nuevoEstado = muerto){
    this->estado = nuevoEstado;
}
void Celula::setGen1(unsigned int nuevoGen1 = 0){
    this->gen1.setCargaGenetica(nuevoGen1);
}
void Celula::setGen2(unsigned int nuevoGen2 = 0){
    this->gen2.setCargaGenetica(nuevoGen2);
}
void Celula::setGen3(unsigned int nuevoGen3 = 0){
    this->gen3.setCargaGenetica(nuevoGen3);
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