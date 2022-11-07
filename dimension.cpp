#include "dimension.h"
#include <iostream>

using namespace std;

Dimension::Dimension(unsigned int ALTO = 0, unsigned int LARGO = 0, unsigned int ANCHO = 0){
    setAlto(ALTO);
    setLargo(LARGO);
    setAncho(ANCHO);
    setMaximo();
}

unsigned int Dimension::getMaximo(){
    return this->MAXIMO;
}

unsigned int Dimension::getAncho(){
    return this->ANCHO;
}

unsigned int Dimension::getLargo(){
    return this->LARGO;
}

unsigned int Dimension::getAlto(){
    return this->ALTO;
}

void Dimension::setMaximo(){
    if (getAlto() != 0 && getLargo() != 0 && getAncho != 0){
        this->MAXIMO = getAlto() * getLargo() * getAncho();
    }else{
        throw"Las coordenadas no son validas"
    }
}

void Dimension::setAlto(unsigned int nuevoAlto){
    this->ALTO = nuevoAlto;
}

void Dimension::setLargo(unsigned int nuevoLargo){
    this->LARGO = nuevoLargo;
}

void Dimension::setAncho(unsigned int nuevoAncho){
    this->ANCHO = nuevoAncho;
}

