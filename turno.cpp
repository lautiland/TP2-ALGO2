#include "turno.h"
#include <iostream>
using namespace std;

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
void Turno::sumarViva(){
	setTotalVivas(getTotalVivas()+1);
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
void Turno::comparacionDeTurnos(Turno *otroTurno)
{
	if (getTotalVivas() == otroTurno->getTotalVivas() && getTotalMuertas() == otroTurno->getTotalMuertas() && getRenacidasEnTurno() == otroTurno->getRenacidasEnTurno() && getMuertasEnTurno() == otroTurno->getMuertasEnTurno())
	{
		setEjecucion(congelado);
	}
};

void Turno::imprimirTurno()
{
	cout << "Resumen del turno " << this->getNumeroDeTurno() << ": " << endl;
	cout << " - Total Vivas: " << this->getTotalVivas() << endl;
	cout << " - Total Muertas: " << this->getTotalMuertas() << endl;
	cout << " - Renacidas en el turno: " << this->getRenacidasEnTurno() << endl;
	cout << " - Muertas en el turno: " << this->getMuertasEnTurno() << endl;
	cout << " - Promedio de Celulas Nacidas: " << this->getPromedioNacidas() << endl;
	cout << " - Promedio de Celulas Muertas: " << this->getPromedioMuertas() << endl;
}

void Turno::operator=(Turno nuevoTurno){
	setTotalVivas(nuevoTurno.getTotalVivas());
	setTotalMuertas(nuevoTurno.getTotalMuertas());
}