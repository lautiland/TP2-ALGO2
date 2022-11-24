#include "turno.h"

Turno::Turno()
{
	this->numeroDeTurno = 1;
	this->totalVivas = 0;
	this->totalMuertas = 0;
	this->renacidasEnTurno = 0;
	this->muertasEnTurno = 0;
	this->promedioNacidas = 0;
	this->promedioMuertas = 0;
	this->ejecucion = corriendo;
}

// getters:

unsigned int Turno::getNumeroDeTurno()
{
	return this->numeroDeTurno;
}
unsigned int Turno::getTotalVivas()
{
	return this->totalVivas;
}
unsigned int Turno::getTotalMuertas()
{
	return this->totalMuertas;
}
unsigned int Turno::getRenacidasEnTurno()
{
	return this->renacidasEnTurno;
}
unsigned int Turno::getMuertasEnTurno()
{
	return this->muertasEnTurno;
}
unsigned int Turno::getPromedioNacidas()
{
	return this->promedioNacidas;
}
unsigned int Turno::getPromedioMuertas()
{
	return this->promedioMuertas;
}
Ejecucion Turno::getEjecucion()
{
	return this->ejecucion;
}

// setters:

void Turno::setNumeroDeTurno(unsigned int turno)
{
	this->numeroDeTurno = turno;
}
void Turno::setTotalVivas(unsigned int nuevoTotalVivas)
{
	this->totalVivas = nuevoTotalVivas;
}
void Turno::setTotalMuertas(unsigned int nuevoTotalMuertas)
{
	this->totalMuertas = nuevoTotalMuertas;
}
void Turno::setRenacidasEnTurno(unsigned int nuevoRenacidasEnTurno)
{
	this->renacidasEnTurno = nuevoRenacidasEnTurno;
}
void Turno::setMuertasEnTurno(unsigned int nuevoMuertasEnTurno)
{
	this->muertasEnTurno = nuevoMuertasEnTurno;
}
void Turno::setPromedioNacidas(unsigned int celulasNacidasEnTurno)
{
	this->promedioMuertas = (celulasNacidasEnTurno + getTotalVivas()) / getNumeroDeTurno();
}

void Turno::setPromedioMuertas(unsigned int celulasMuertasEnTurno)
{
	this->promedioMuertas = (celulasMuertasEnTurno + getTotalMuertas()) / getNumeroDeTurno();
}

void Turno::setEjecucion(Ejecucion nuevoEjecucion)
{
	this->ejecucion = nuevoEjecucion;
}

void Turno::siguienteTurno()
{
	this->numeroDeTurno++;
	this->renacidasEnTurno = 0;
	this->muertasEnTurno = 0;
}
Ejecucion Turno::comparacionDeTurnos(Turno *otroTurno)
{
	Ejecucion resultado;
	if (getTotalVivas() == otroTurno->getTotalVivas() && getTotalMuertas() == otroTurno->getTotalMuertas() && getRenacidasEnTurno() == otroTurno->getRenacidasEnTurno() && getMuertasEnTurno() == otroTurno->getMuertasEnTurno())
	{
		resultado = congelado;
	}
	else
	{
		resultado = ejecucion;
	}

	return resultado;
};