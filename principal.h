#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "EasyBMP.h"
#include "tablero.h"

//SOLO EN VISUAL
#include "tablero.cpp"
#include "EasyBMP.cpp"


enum AccionTurno{
	continuar,
	reiniciar,
	terminar,
};


/**
 * pre: -
 * pos: -
 */
void bienvenida();

/**
 * pre: -
 * pos: -
 */
ModoDeJuego configurar();

/**
 * pre: -
 * pos: -
 */
void eliminarArchivosBitmap(Tablero* partida);

/**
 * pre: -
 * pos: -
 */
AccionTurno preguntarTurno(Tablero *partida);

/**
 * pre: -
 * pos: -
 */
AccionTurno preguntarTurno(Tablero *partida);

/**
 * pre: -
 * pos: -
 */
int imagenesBitmap(Tablero *tablero);

#endif