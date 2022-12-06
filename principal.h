#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "tablero.h"
#include "EasyBMP.h"

//SOLO EN VISUAL
//#include "tablero.cpp"
//#include "EasyBMP.cpp"

enum AccionTurno{
	continuar,
	reiniciar,
	terminar,
};

/**
 * pre: -
 * pos: imprime en consola un mensaje de bienvenida al usuario que ejecuta el juego.
 */
void bienvenida();

/**
 * pre: -
 * pos: pregunta al usuario que configuracion desea. En base a eso devuelve las configuraciones del juego.
 */
ModoDeJuego configurar();

/**
 * pre: partida debe estar inicializado.
 * pos: pregunta al usuario si desea reiniciar, terminar o continuar con el siguiente turno y devuelve el resultado.
 */
AccionTurno preguntarTurno(Tablero *partida);

/**
 * pre: partida debe estar inicializado y debe tener una matriz ya generada con celulas.
 * pos: crea imagenes Bitmap por cada pagina del tablero, representando las celulas con colores segun sus genes
 * y las almacena en la carpeta del contenido del programa.
 */
int generarArchivosBitmap(Tablero *partida);

/**
 * pre: deben estar generados los archivos Bitmap, uno por cada pagina, es decir, cumplir sus precondiciones.
 * pos: borra los archivos generados anteriormente.
 */
void eliminarArchivosBitmap(Tablero* partida);

#endif
