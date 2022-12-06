#ifndef _TURNO_H_
#define _TURNO_H_

enum Ejecucion
{
	congelado,
	corriendo
};

class Turno
{
private:
	unsigned int numeroDeTurno;
	unsigned int totalVivas;
	unsigned int totalMuertas;
	unsigned int renacidasEnTurno;
	unsigned int muertasEnTurno;
	unsigned int promedioNacidas;
	unsigned int promedioMuertas;
	Ejecucion ejecucion;

public:
	// constructores:

	Turno();

	// getters:

	/**
    * pre: -
    * pos: devuelve el número de turno actual.
    */
    unsigned int getNumeroDeTurno();

	/**
    * pre: -
    * pos: devuelve el total de células vivas.
    */
    unsigned int getTotalVivas();

	/**
    * pre: -
    * pos: devuelve el total de células muertas.
    */
    unsigned int getTotalMuertas();

	/**
    * pre: -
    * pos: devuelve la cantidad de células que renacieron en el turno.
    */
    unsigned int getRenacidasEnTurno();

	/**
    * pre: -
    * pos: devuelve la cantidad de células que murieron en el turno actual.
    */
    unsigned int getMuertasEnTurno();

	/**
    * pre: -
    * pos: devuelve el promedio de nacimientos a lo largo del juego.
    */
    unsigned int getPromedioNacidas();

	/**
    * pre: -
    * pos: devuelve el promedio de muertes a lo largo del juego.
    */
    unsigned int getPromedioMuertas();

	/**
    * pre: -
    * pos: devuelve el estado de ejecución actual del juego.
    */
    Ejecucion getEjecucion();

	// setters:

	/**
    * pre: el turno no puede ser cero ni un número negativo
    * pos: actualiza el número de turno.
    */
    void setNumeroDeTurno(unsigned int turno);

	/**
 	* pre: -
 	* pos: agrega uno a viva a totalVivas.
 	*/
	void sumarViva();

	/**
    * pre: nuevoTotalVivas no puede ser un número negativo.
    * pos: actualiza el total de células vivas.
    */
    void setTotalVivas(unsigned int nuevoTotalVivas);

	/**
    * pre: nuevoTotalMuertas no puede ser un número negativo.
    * pos: actualiza el total de células muertas.
    */
    void setTotalMuertas(unsigned int nuevoTotalMuertas);

	/**
    * pre: nuevoRenacidasEnTurno no puede ser un número negativo.
    * pos: actualiza el número de células que renacieron en el turno.
    */
    void setRenacidasEnTurno(unsigned int nuevoRenacidasEnTurno);

	/**
    * pre: nuevoMuertasEnTurno no puede ser un número negativo.
    * pos: actualiza el número de células que murieron en el turno.
    */
    void setMuertasEnTurno(unsigned int nuevoMuertasEnTurno);

	/**
    * pre: -
    * pos: actualiza el promedio de células que nacieron durante el juego.
    */
    void setPromedioNacidas(unsigned int celulasNacidasEnTurno);

	/**
    * pre: -
    * pos: actualiza el promedio de células que murieron durante el juego.
    */
    void setPromedioMuertas(unsigned int celulasMuertasEnTurno);

	/**
    * pre: -
    * pos: actualiza el estado de ejecución del juego.
    */
    void setEjecucion(Ejecucion nuevoEjecucion);

	/**
 	* pre: -
 	* pos: -
 	*/
	void comparacionDeTurnos(Turno *otroTurno);

	// funciones:

	/**
 	* pre: -
 	* pos: copia los datos totales de los turnos
 	*/
	void operator=(Turno nuevoTurno);
	/**
    * pre: el juego debe estar ejecutándose.
    * pos: reinicia el contador de renacidas y muertas en turno, suma 1 al numero de turno.
    */
    void siguienteTurno();

	/**
    * pre: -
    * pos: imprime el numero de turno, el total de células vivas y muertas, las células que renacieron o murieron en el turno,
    * y el promedio de nacimientos y muertes durante el juego.
    */
    void imprimirTurno();
};

#endif
