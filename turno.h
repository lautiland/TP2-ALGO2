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
	void setNumeroDeTurno(unsigned int turno);
	void setTotalVivas(unsigned int nuevoTotalVivas);
	void setTotalMuertas(unsigned int nuevoTotalMuertas);
	void setRenacidasEnTurno(unsigned int nuevoRenacidasEnTurno);
	void setMuertasEnTurno(unsigned int nuevoMuertasEnTurno);
	void setPromedioNacidas(unsigned int nuevoPromedioNacidas);
	void setPromedioMuertas(unsigned int nuevoPromedioMuertas);
	void setEjecucion(Ejecucion nuevoEjecucion);
	Ejecucion comparacionDeTurnos(Turno *otroTurno);
	// funciones:
	void siguienteTurno();
};

#endif