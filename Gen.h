/*
 * Gen.h
 *
 *  Created on: 30/09/2022
 *      Author: algo2
 */

#ifndef GEN_H_
#define GEN_H_

class Gen
{

private:
	unsigned int maximoDeCargaGenetica;
	unsigned int cargaGenetica;

public:
	/**
	 * pre: maximoDeCargaGenetica es un valor 0 o positivo
	 * pos: deja el gen creado con maximoDeCargaGenetica en "maximoDeCargaGenetica", y cargaGenetica en 0.
	 */
	Gen(unsigned int maximoDeCargaGenetica);

	/**
	 * pre: maximoDeCargaGenetica es un valor 0 o positivo, cargaGenetica tiene un valor entre 0 y maximoDeCargaGenetica inclusive
	 * pos: deja el gen creado con maximoDeCargaGenetica en "maximoDeCargaGenetica", y cargaGenetica en cargaGenetica.
	 */
	Gen(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica);

	/**
	 * pre: -
	 * pos: -
	 */
	virtual ~Gen();

	/**
	 * pre: -
	 * pos: devuelve la cargaGenetica
	 */
	unsigned int getCargaGenetica();

	/**
	 * pre: -
	 * pos: devuelve el maximoDeCargaGenetica
	 */
	unsigned int getMaximoDeCargaGenetica();

	/**
	 * pre: la cargaGenetica debe ser un valor entre 0 y maximoDeCargaGenetica inclusive
	 * pos: cambia el valor de cargaGenetica
	 */
	void setCargaGenetica(unsigned int cargaGenetica);

private:
	/**
	 * pre: -
	 * pos: da error si maximoDeCargaGenetica o cargaGenetica no respeta los rangos
	 */
	unsigned int verificar(unsigned int maximoDeCargaGenetica, unsigned int cargaGenetica);
};

#endif /* GEN_H_ */