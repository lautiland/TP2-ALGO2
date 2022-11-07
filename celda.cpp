#include "celda.h"

//  Constructores

Celda::Celda(unsigned int posicionX = 0, unsigned int posicionY = 0, unsigned int posicionZ = 0, Tipo tipo = estandar, Celula celula){
    setPosicionX(posicionX);
    setPosicionY(posicionY);
    setPosicionZ(posicionZ);
    setTipo(tipo);
    setCelula(celula);
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
Celula Celda::getCelula(){
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
void Celda::setCelula(Celula nuevaCelula   

    // = no se que poner

                                        ){
    this->celula = nuevaCelula;          //uso la funcion del operador asignacion
}

//  Funciones

void Celda::operator=(Celda nuevaCelda){           //esta funcion permite igualar dos celdas y que se copien sus datos
    setPosicionX(nuevaCelda.getPosicionX());
    setPosicionY(nuevaCelda.getPosicionY());
    setPosicionZ(nuevaCelda.getPosicionZ());
    setTipo(nuevaCelda.getTipo());
    setCelula(nuevaCelda.getCelula());
}