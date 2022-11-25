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
	unsigned int getNumeroDeTurno();
	unsigned int getTotalVivas();
	unsigned int getTotalMuertas();
	unsigned int getRenacidasEnTurno();
	unsigned int getMuertasEnTurno();
	unsigned int getPromedioNacidas();
	unsigned int getPromedioMuertas();
	Ejecucion getEjecucion();

	// setters:

	/**
 	* pre: -
 	* pos: -
 	*/
	void setNumeroDeTurno(unsigned int turno);
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void setTotalVivas(unsigned int nuevoTotalVivas);

	/**
 	* pre: -
 	* pos: -
 	*/
	void setTotalMuertas(unsigned int nuevoTotalMuertas);
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void setRenacidasEnTurno(unsigned int nuevoRenacidasEnTurno);
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void setMuertasEnTurno(unsigned int nuevoMuertasEnTurno);
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void setPromedioNacidas(unsigned int nuevoPromedioNacidas);
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void setPromedioMuertas(unsigned int nuevoPromedioMuertas);
	
	/**
 	* pre: -
 	* pos: -
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
 	* pos: -
 	*/
	void siguienteTurno();
	
	/**
 	* pre: -
 	* pos: -
 	*/
	void imprimirTurno();
};

#endif