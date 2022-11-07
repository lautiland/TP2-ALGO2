
#include "celula.h"

Celula::Celula(Estado estado = muerto, unsigned int gen1 = 0, unsigned int gen2 = 0, unsigned int gen3 = 0){
    setEstado(estado);
    setGen1(gen1);
    setGen2(gen2);
    setGen3(gen3);

}

Estado Celula::getEstado(){
    return estado;
}

unsigned int Celula::getGen1(){
    return gen1.getCargaGentica();
}

unsigned int Celula::getGen2(){
    return gen2.getCargaGentica();
}

unsigned int Celula::getGen3(){
    return gen3.getCargaGentica();
}

void Celula::setEstado(Estado nuevoEstado = muerta){
    this->estado = nuevoEstado;
}

void Celula::setGen1(unsigned int nuevoGen1 = 0){
    this->gen1.setCargaGentica(nuevoGen1);
}

void Celula::setGen2(unsigned int nuevoGen2 = 0){
    this->gen2.setCargaGentica(nuevoGen2);
}

void Celula::setGen3(unsigned int nuevoGen3 = 0){
    this->gen3.setCargaGentica(nuevoGen3);
}

void Celula::mezclarGenes(){

}
