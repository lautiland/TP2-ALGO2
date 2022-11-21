#include "turno.h"

turno::turno(){
	this->totalVivas = 0;
	this->totalMuertas = 0;
	this->renacidasEnTurno = 0;
	this->muertasEnTurno = 0;
	this->promedioNacidas = 0;
	this->promedioMuertas = 0;
	this->ejecucion = corriendo;
}

	//getters:

	unsigned int turno::getTotalVivas(){
		return this->totalVivas;
	}
	unsigned int turno::getTotalMuertas(){
		return this->totalMuertas;
	}
	unsigned int turno::getRenacidasEnTurno(){
		return this->renacidasEnTurno;
	}
	unsigned int turno::getMuertasEnTurno(){
		return this->muertasEnTurno;
	}
	unsigned int turno::getPromedioNacidas(){
		return this->promedioNacidas;
	}
	unsigned int turno::getPromedioMuertas(){
		return this->promedioMuertas;
	}
	Ejecucion turno::getEjecucion(){
		return this->ejecucion;
	}

	//setters:

	void turno::setTotalVivas(unsigned int nuevoTotalVivas){
		this->totalVivas = nuevoTotalVivas;
	}
	void turno::setTotalMuertas(unsigned int nuevoTotalMuertas){
		this->totalMuertas = nuevoTotalMuertas;
	}
	void turno::setRenacidasEnTurno(unsigned int nuevoRenacidasEnTurno){
		this->renacidasEnTurno = nuevoRenacidasEnTurno;
	}
	void turno::setMuertasEnTurno(unsigned int nuevoMuertasEnTurno){
		this->muertasEnTurno = nuevoMuertasEnTurno;
	}
	void turno::setPromedioNacidas(unsigned int nuevoPromedioNacidas){
		this->promedioMuertas = nuevoPromedioNacidas;
	}	
	void turno::setEjecucion(Ejecucion nuevoEjecucion){
		this->ejecucion = nuevoEjecucion;
	}