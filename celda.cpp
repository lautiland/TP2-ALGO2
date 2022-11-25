#include "celda.h"

//  Constructores y destructores

Celda::Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo)
{
    this->setPosicionX(posicionX);
    this->setPosicionY(posicionY);
    this->setPosicionZ(posicionZ);
    this->setTipo(tipo);

    this->celula = new Celula(); // es por tema de incluciones de archivos, en visual no anda
}

//  Getters

unsigned int Celda::getPosicionX()
{
    return this->posicionX;
}
unsigned int Celda::getPosicionY()
{
    return this->posicionY;
}
unsigned int Celda::getPosicionZ()
{
    return this->posicionZ;
}
Tipo Celda::getTipo()
{
    return this->tipo;
}
Celula *Celda::getCelula()
{
    return this->celula;
}

//  Setters

void Celda::setPosicionX(unsigned int nuevaPosicionX = 0)
{
    this->posicionX = nuevaPosicionX;
}
void Celda::setPosicionY(unsigned int nuevaPosicionY = 0)
{
    this->posicionY = nuevaPosicionY;
}
void Celda::setPosicionZ(unsigned int nuevaPosicionZ = 0)
{
    this->posicionZ = nuevaPosicionZ;
}
void Celda::setTipo(Tipo nuevoTipo = estandar)
{
    this->tipo = nuevoTipo;
}

//  Funciones

void Celda::operator=(Celda nuevaCelda)
{ // esta funcion permite igualar dos celdas y que se copien sus datos
    this->setPosicionX(nuevaCelda.getPosicionX());
    this->setPosicionY(nuevaCelda.getPosicionY());
    this->setPosicionZ(nuevaCelda.getPosicionZ());
    this->setTipo(nuevaCelda.getTipo());
    this->celula = nuevaCelda.getCelula();
}
void Celda::actualizarEstadoCelula(unsigned int celulasVecinas, unsigned int x1, unsigned int x2, unsigned int x3, Lista<Celda *> *listaVecinasVivas)
{
    
    if (getTipo() == procreadora)
    {
        x1 = x1 - 1;
    };
    
    if ((celulasVecinas == x1) && (getCelula()->getEstado() == muerto) && (getTipo() != contaminada))
    {
        getCelula()->setEstado(vivo);
        actualizaGenesCelula(listaVecinasVivas);
    }
    else if ((celulasVecinas < x2 || celulasVecinas > x3) && (getCelula()->getEstado() == vivo))
    {
        getCelula()->setEstado(muerto);
    };
}

void Celda::actualizaGenesCelula(Lista<Celda *> *listaVecinasVivas)
{
    if (listaVecinasVivas == NULL)
    {
        throw "no se pueden cambiar los genes si no tengo una lista de progenitoras";
    }
    if (this->getCelula()->getEstado() == vivo)
    {
        AdministradorDeGen *nuevoGen = new AdministradorDeGen(255);
        for (unsigned int i = 0; i < listaVecinasVivas->contarElementos(); i++)
        {   
            std::cout << listaVecinasVivas->obtener(i+1)->getCelula()->getGen1() << " " << listaVecinasVivas->obtener(i+1)->getCelula()->getGen2() << " " << listaVecinasVivas->obtener(i+1)->getCelula()->getGen3() << std::endl;
            switch (i)
            {
            case 1:
                getCelula()->setGen1(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            case 2:
                getCelula()->setGen2(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            case 3:
                getCelula()->setGen3(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            default:
                break;
            }
        }
        delete nuevoGen;
    }
}