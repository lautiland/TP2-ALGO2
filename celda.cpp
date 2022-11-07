
#include "celda.h"

Celda::Celda(int posicionX = 0, int posicionY = 0, int posicionZ = 0, Tipo tipo = estandar, Celula celula  

    // = no se que poner

                                        ){
    setPosicionX(posicionX);
    setPosicionY(posicionY);
    setPosicionZ(posicionZ);
    setTipo(tipo);
    setCelula(celula);
}

unsigned int Celda::getPosicionX(){
    return posicionX;
}
unsigned int Celda::getPosicionY(){
    return posicionY;
}
unsigned int Celda::getPosicionZ(){
    return posicionZ;
}
Tipo Celda::getTipo(){
    return tipo;
}
Celula Celda::getCelula(){
    return celula;
}

void Celda::setPosicionX(unsigned int nuevaPosicionX = 0){
    this->posicionX = nuevaPosicionX;
}
void Celda::setPosicionY(unsigned int nuevaPosicionY = 0){
    this->posicionY = nuevaPosicionY;
}
void Celda::setPosicionZ(unsigned int nuevaPosicionZ = 0){
    this->posicionZ = nuevaPosicionZ;
}
void Celda::setTipo(Tipo nuevoTipo = estandar){
    this->tipo = nuevoTipo;
}
void Celda::setCelula(Celula nuevaCelula   

    // = no se que poner

                                        ){
    this->celula.setEstado(nuevaCelula.getEstado());
    this->celula.setGen1(nuevaCelula.getGen1());
    this->celula.setGen2(nuevaCelula.getGen2());
    this->celula.setGen3(nuevaCelula.getGen3());
}

