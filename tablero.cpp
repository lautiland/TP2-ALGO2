#include <iostream>
#include "tablero.h"

using namespace std;

// las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(ModoDeJuego configuracion)
{
    setConfiguracion(configuracion);

    // cout << getAlto() << " " << getLargo() << " " <<  getAncho() << endl;

    this->tablero = new Lista<Lista<Lista<Celda *> *> *>();

    for (unsigned int k = 0; k < getAlto(); k++)
    { // va rellenando el tablero

        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>(); // crea la pagina

        for (unsigned int j = 0; j < getLargo(); j++)
        { // va rellenando las paginas

            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna

            for (unsigned int i = 0; i < getAncho(); i++)
            { // va rellenando las columnas

                Celda *fila = new Celda(i, j, k, estandar); // crea la fila

                columna->agregar(fila); // agrega la fila a la columna
            }

            pagina->agregar(columna); // agregar la columna a la página
        }

        this->tablero->agregar(pagina); // agrega la página al tablero
    }

    for (unsigned int i = 0; i < numeroAleatorio((int(getAlto()) * int(getLargo()) * int(getAncho()) * 100 / 5)); i++)
    {

        unsigned int x = numeroAleatorio(getAncho());
        unsigned int y = numeroAleatorio(getLargo());
        unsigned int z = numeroAleatorio(getAlto());
        getTablero()->obtener(x)->obtener(y)->obtener(z)->setTipo(Tipo(numeroAleatorio(6)));
    };
    this->turno = new Turno();
}
Tablero::Tablero(Tablero *tableroOriginal)
{
    this->tablero = new Lista<Lista<Lista<Celda *> *> *>();
    this->alto = tableroOriginal->getAlto();
    this->ancho = tableroOriginal->getAncho();
    this->largo = tableroOriginal->getLargo();
    this->X1 = tableroOriginal->getX1();
    this->X2 = tableroOriginal->getX2();
    this->X3 = tableroOriginal->getX3();
    this->turno = tableroOriginal->getTurno();

    for (unsigned int i = 0; i < tableroOriginal->getLargo(); i++)
    {
        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>();
        for (unsigned int j = 0; j < tableroOriginal->getAncho(); j++)
        {
            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna
            for (unsigned int k = 0; k < tableroOriginal->getAlto(); k++)
            {
                Celda *fila = new Celda(i, j, k, tableroOriginal->getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1)->getTipo()); // crea la fila
                *fila = *tableroOriginal->getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1);
                columna->agregar(fila);
            }
            pagina->agregar(columna); // agregar la columna a la página
        }
        this->tablero->agregar(pagina); // agrega la página al tablero
    }
}
Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero()
{
    return this->tablero;
};

void Tablero::setConfiguracion(ModoDeJuego configuracion)
{
    // la idea es que el usuario ponga 2 o 3, que serian las cofig automaticas y la 1 seria la manual
    // es medio a lo bruto este metodo pero lo puedo pulir si es necesario, es lo primero que se me ocurrió
    // los numeros que ponemos en los modos automaticos pueden ir en constantes globales ahora que lo pienso
    switch (configuracion)
    {
    case manual:
        cout << "Ingrese el ancho del tablero deseado: " << endl;
        cin >> this->ancho;
        cout << "Ingrese el largo del tablero deseado: " << endl;
        cin >> this->largo;
        cout << "Ingrese el alto del tablero deseado: " << endl;
        cin >> this->alto;
        cout << "Ingrese la cantidad de celulas vecinas vivas necesarias para que nazca una celula: " << endl;
        cin >> this->X1;
        cout << "Ingrese la cantidad minima de celulas vecinas vivas para que nazca una nueva celula: " << endl;
        cin >> this->X2;
        cout << "Ingrese la cantidad maxima de celulas vecinas vivas para que muera una celulaS: " << endl;
        cin >> this->X3;
        cout << endl;
        break;

    case configuracion1:
        this->alto = 5;
        this->ancho = 5;
        this->largo = 5;
        this->X1 = 3;
        this->X2 = 2;
        this->X3 = 4;
        break;
    case configuracion2:
        this->alto = 10;
        this->ancho = 10;
        this->largo = 10;
        this->X1 = 3;
        this->X2 = 2;
        this->X3 = 4;
        break;
    case configuracion3:
        this->alto = 20;
        this->ancho = 20;
        this->largo = 20;
        this->X1 = 3;
        this->X2 = 2;
        this->X3 = 4;
        break;
    }
}

unsigned int Tablero::getX1()
{
    return X1;
}

unsigned int Tablero::getX2()
{
    return X2;
}

unsigned int Tablero::getX3()
{
    return X3;
}

unsigned int Tablero::getAlto()
{
    return this->alto;
}

unsigned int Tablero::getAncho()
{
    return this->ancho;
}

unsigned int Tablero::getLargo()
{
    return this->largo;
}

Turno *Tablero::getTurno()
{
    return turno;
}

Tablero::~Tablero()
{
    this->tablero->iniciarCursor();
    while (this->tablero->avanzarCursor())
    {
        Lista<Lista<Celda *> *> *temp = this->tablero->obtenerCursor();
        temp->iniciarCursor();
        while (temp->avanzarCursor())
        {
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->tablero;
}

void Tablero::definirCelulasVivas()
{
    int metodo;
    char otroMetodo;
    do
    {

        do
        {
            cout << "Elija el metodo para ingresar celulas vivas: " << endl;
            cout << "1: Ingresar individualmente." << endl;
            cout << "2: Ingresar por rango." << endl
                 << endl;
            cin >> metodo;
            cout << endl;

        } while ((metodo != 1) && (metodo != 2));
        if (metodo == 1)
        {

            char seguir;

            do
            {
                unsigned int coordenadaX, coordenadaY, coordenadaZ;
                do
                {
                    cout << "Ingrese la primera cordenada: " << endl;
                    cin >> coordenadaX;
                } while ((coordenadaX <= 0) || (coordenadaX > getAncho()));
                do
                {
                    cout << "Ingrese la segunda cordenada: " << endl;
                    cin >> coordenadaY;
                } while ((coordenadaY <= 0) || (coordenadaY > getLargo()));
                do
                {
                    cout << "Ingrese la tercera cordenada: " << endl;
                    cin >> coordenadaZ;
                } while ((coordenadaZ <= 0) || (coordenadaZ > getAlto()));

                getTablero()->obtener(coordenadaZ)->obtener(coordenadaY)->obtener(coordenadaX)->getCelula()->setEstado(vivo);

                cout << "Se ha ingresado con exito la celula (" << coordenadaX << ", " << coordenadaY << ", " << coordenadaZ << ")." << endl;
                cout << endl;

                do
                {
                    cout << "Desea seguir ingresando celulas con este metodo? s/n." << endl
                         << endl;
                    cin >> seguir;
                    cout << endl;
                } while ((seguir != 's') && (seguir != 'n') && (seguir != 'S') && (seguir != 'N'));

            } while ((seguir == 's') || (seguir == 'S'));
        }
        else if (metodo == 2)
        {

            char seguir;

            do
            {
                unsigned int coordenadaX1, coordenadaY1, coordenadaZ1;
                do
                {
                    cout << "Ingrese la primera cordenada de la primera celula: " << endl;
                    cin >> coordenadaX1;
                } while ((coordenadaX1 <= 0) || (coordenadaX1 > getAncho()));
                do
                {
                    cout << "Ingrese la segunda cordenada de la primera celula: " << endl;
                    cin >> coordenadaY1;
                } while ((coordenadaY1 <= 0) || (coordenadaY1 > getLargo()));
                do
                {
                    cout << "Ingrese la tercera cordenada de la primera celula: " << endl;
                    cin >> coordenadaZ1;
                } while ((coordenadaZ1 <= 0) || (coordenadaZ1 > getAlto()));

                unsigned int coordenadaX2, coordenadaY2, coordenadaZ2;
                do
                {
                    cout << "Ingrese la primera cordenada de la segunda celula: " << endl;
                    cin >> coordenadaX2;
                } while ((coordenadaX2 <= 0) || (coordenadaX2 > getAncho()));
                do
                {
                    cout << "Ingrese la segunda cordenada de la segunda celula: " << endl;
                    cin >> coordenadaY2;
                } while ((coordenadaY2 <= 0) || (coordenadaY2 > getLargo()));
                do
                {
                    cout << "Ingrese la tercera cordenada de la segunda celula: " << endl;
                    cin >> coordenadaZ2;
                } while ((coordenadaZ2 <= 0) || (coordenadaZ2 > getAlto()));

                if (coordenadaX1 > coordenadaX2)
                {
                    unsigned int aux = coordenadaX1;
                    coordenadaX1 = coordenadaX2;
                    coordenadaX2 = aux;
                }
                if (coordenadaY1 > coordenadaY2)
                {
                    unsigned int aux = coordenadaY1;
                    coordenadaY1 = coordenadaY2;
                    coordenadaY2 = aux;
                }
                if (coordenadaZ1 > coordenadaZ2)
                {
                    unsigned int aux = coordenadaZ1;
                    coordenadaZ1 = coordenadaZ2;
                    coordenadaZ2 = aux;
                }

                for (unsigned int z = coordenadaZ1; z <= coordenadaZ2; z++)
                {
                    for (unsigned int y = coordenadaY1; y <= coordenadaY2; y++)
                    {
                        for (unsigned int x = coordenadaX1; x <= coordenadaX2; x++)
                        {
                            getTablero()->obtener(z)->obtener(y)->obtener(x)->getCelula()->setEstado(vivo);
                        }
                    }
                }

                cout << "Se ha ingresado con exito el rango entre (" << coordenadaX1 << ", " << coordenadaY1 << ", " << coordenadaZ1 << ") y (";
                cout << coordenadaX2 << ", " << coordenadaY2 << ", " << coordenadaZ2 << ").";
                cout << endl;

                do
                {
                    cout << "Desea seguir ingresando rangos de celulas con este metodo? s/n." << endl
                         << endl;
                    cin >> seguir;
                    cout << endl;

                } while ((seguir != 's') && (seguir != 'n') && (seguir != 'S') && (seguir != 'N'));

            } while ((seguir == 's') || (seguir == 'S'));
        }

        do
        {
            cout << "Desea utilizar otro metodo para ingresar celulas? s/n." << endl
                 << endl;
            cin >> otroMetodo;
            cout << endl;
        } while ((otroMetodo != 's') && (otroMetodo != 'n') && (otroMetodo != 'S') && (otroMetodo != 'N'));

    } while ((otroMetodo == 's') || (otroMetodo == 'S'));

    cout << "Las celulas fueron ingresadas con exito." << endl
         << endl;
}

void Tablero::contadorCelulasVecinas(unsigned int pagina, unsigned int columna, unsigned int fila, Tablero *temp)
{ // x1: cels nesesarias para nacer; x2 y x3: cels para permanecer viva; en otro caso mueren
    int vecinasVivas = 0;
    unsigned int vecinaX;
    unsigned int vecinaY;
    unsigned int vecinaZ;
    Lista<Celda *> *listaVecinasVivas = new Lista<Celda *>;

    Celda *celdaCentro = this->tablero->obtener(pagina)->obtener(columna)->obtener(fila);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int k = -1; k <= 1; ++k)
            {

                if ((int(pagina) + i) == 0)
                {
                    vecinaZ = getLargo();
                }
                else if ((int(pagina) + i) == (int(getLargo()) + 1))
                {
                    vecinaZ = 1;
                }
                else
                {
                    vecinaZ = int(pagina) + i;
                }

                //--------------------------------------------------//

                if ((int(columna) + j) == 0)
                {
                    vecinaY = getAncho();
                }
                else if ((int(columna) + j) == (int(getAncho()) + 1))
                {
                    vecinaY = 1;
                }
                else
                {
                    vecinaY = int(columna) + j;
                }

                //--------------------------------------------------//

                if ((int(fila) + k) == 0)
                {
                    vecinaX = getAlto();
                }
                else if ((int(fila) + k) == (int(getAlto()) + 1))
                {
                    vecinaX = 1;
                }
                else
                {
                    vecinaX = int(fila) + k;
                }



                if (!(i == 0 && j == 0 && k == 0))
                {   

                    if (getTablero()->obtener(vecinaZ)->obtener(vecinaY)->obtener(vecinaX)->getCelula()->getEstado() == vivo)
                    {
                        vecinasVivas++;
                        if (listaVecinasVivas->contarElementos() < getX1())
                        {
                            listaVecinasVivas->agregar(getTablero()->obtener(vecinaZ)->obtener(vecinaY)->obtener(vecinaX));

                        }
                    }
                }
            }
        }
    }

    temp->getTablero()->obtener(pagina)->obtener(columna)->obtener(fila)->actualizarEstadoCelula(vecinasVivas, getX1(), getX2(), getX3(), listaVecinasVivas);
    Estado aux = temp->getTablero()->obtener(pagina)->obtener(columna)->obtener(fila)->getCelula()->getEstado();
    temp->contabilizarCasos(aux, celdaCentro);

    listaVecinasVivas->iniciarCursor();
    while (listaVecinasVivas->avanzarCursor())
    {
        delete listaVecinasVivas->obtenerCursor();
    }
    delete listaVecinasVivas;
}

void Tablero::contabilizarCasos(Estado aux, Celda *celdaCentro)
{
    if ((celdaCentro->getCelula()->getEstado() != aux))
    {
        if (aux == muerto)
        {
            getTurno()->setRenacidasEnTurno(getTurno()->getRenacidasEnTurno() + 1);
        }
        else
        {
            getTurno()->setMuertasEnTurno(getTurno()->getMuertasEnTurno() + 1);
        }
    }
}

unsigned int Tablero::numeroAleatorio(unsigned int maximo)
{
    srand(time(NULL));
    return rand() % maximo + 1;
};

void Tablero::devolverTablero(unsigned int i, unsigned int j, unsigned int k)
{
    if (getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1)->getCelula()->getEstado() == vivo)
    {
        cout << 1 << " ";
    }else{
        cout << 0 << " ";
    }
}

void Tablero::resolverTurno()
{
    Tablero *temp = new Tablero(this);

    for (unsigned int i = 0; i < temp->getLargo(); i++)
    {
        for (unsigned int j = 0; j < temp->getAncho(); j++)
        {
            for (unsigned int k = 0; k < temp->getAlto(); k++)
            {
                
                contadorCelulasVecinas(i+1, j+1, k+1, temp);
                getTurno()->setPromedioNacidas(getTurno()->getRenacidasEnTurno());
                getTurno()->setPromedioMuertas(getTurno()->getMuertasEnTurno());
            }
        }
    }


    getTurno()->comparacionDeTurnos(temp->getTurno());

    
    Lista<Lista<Lista<Celda *> *> *> * aux = getTablero();
    this->tablero = temp->getTablero();

    aux->iniciarCursor();
    while (aux->avanzarCursor())
    {
        Lista<Lista<Celda *> *> *temp2 = aux->obtenerCursor();
        temp2->iniciarCursor();
        while (temp2->avanzarCursor())
        {
            delete temp2->obtenerCursor();
        }
        delete temp2;
    }
    delete aux;

}

void Tablero::imprimirTablero()
{
    
    for (unsigned int i = 0; i < getAlto(); i++)
    {
        cout << "Pagina numero " << i+1 << ":" << endl << endl;
        for (unsigned int j = 0; j < getLargo(); j++)
        {
            cout << "     ";
            for (unsigned int k = 0; k < getAncho(); k++)
            {
                devolverTablero(i, j, k);
            };
            cout << endl;
        }
        cout << endl;
    }
}

//int(getTablero()->obtener(i)->obtener(j)->obtener(k)->getCelula()->getEstado())

