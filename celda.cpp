#include "celda.h"

//  Constructores y destructores

Celda::Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo){
    setPosicionX(posicionX);
    setPosicionY(posicionY);
    setPosicionZ(posicionZ);
    setTipo(tipo);
    this->celula = new Celula();        //es por tema de incluciones de archivos, en visual no anda
}

//  Getters

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
Celula* Celda::getCelula(){
    return celula;
}

//  Setters

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

//  Funciones

void Celda::operator=(Celda nuevaCelda){           //esta funcion permite igualar dos celdas y que se copien sus datos
    setPosicionX(nuevaCelda.getPosicionX());
    setPosicionY(nuevaCelda.getPosicionY());
    setPosicionZ(nuevaCelda.getPosicionZ());
    setTipo(nuevaCelda.getTipo());
    this->celula = nuevaCelda.getCelula();
}

