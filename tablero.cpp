#include <iostream>
#include "tablero.h"

using namespace std;

//las globales son temporales para probar, lo mismo con eso de ancho alto etc

Tablero::Tablero(ModoDeJuego configuracion)
{
    setConfiguracion(configuracion);

    //cout << getAlto() << " " << getLargo() << " " <<  getAncho() << endl;

    this->tablero = new Lista<Lista<Lista<Celda *> *> *>();

    for (unsigned int k = 0; k < getAlto(); k++)
    { // va rellenando el tablero
        

        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>(); // crea la pagina

        for (unsigned int j = 0; j < getLargo(); j++)
        { // va rellenando las paginas
            

            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna

            for (unsigned int i = 0; i < getAncho(); i++)
            { // va rellenando las columnas


                Celda* fila = new Celda(i, j, k, estandar); // crea la fila

                columna->agregar(fila); // agrega la fila a la columna
            }

            pagina->agregar(columna); // agregar la columna a la página
        }

        this->tablero->agregar(pagina);     // agrega la página al tablero

    }

    for (unsigned int i = 0; i < numeroAleatorio((int(getAlto()) * int(getLargo()) * int(getAncho())* 100 / 5)); i++)
    {

        unsigned int x = numeroAleatorio(getAncho());
        unsigned int y = numeroAleatorio(getLargo());
        unsigned int z = numeroAleatorio(getAlto());
        getTablero()->obtener(x)->obtener(y)->obtener(z)->setTipo(Tipo(numeroAleatorio(6)));
    };

}

Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero()
{
    return this->tablero;
};

void Tablero::setConfiguracion(ModoDeJuego configuracion){
    //la idea es que el usuario ponga 2 o 3, que serian las cofig automaticas y la 1 seria la manual
    //es medio a lo bruto este metodo pero lo puedo pulir si es necesario, es lo primero que se me ocurrió
    //los numeros que ponemos en los modos automaticos pueden ir en constantes globales ahora que lo pienso
    switch(configuracion){
        case manual:
            cout << "Ingrese el alto del tablero deseado: " << endl;
            cin >> this->alto;
            cout << "Ingrese el ancho del tablero deseado: " << endl;
            cin >> this->ancho;
            cout << "Ingrese el largo del tablero deseado: " << endl;
            cin >> this->largo;
            cout << "Ingrese la cantidad de células vecinas vivas necesarias para que nazca una célula: " << endl;
            cin >> this->X1;
            cout << "Ingrese la minima cantidad de células vecinas vivas para que se reproduzcan: " << endl;
            cin >> this->X2;
            cout << "Ingrese la minima cantidad de células vecinas vivas para que mueran por soprepoblación: " << endl;
            cin >> this->X3;
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
            this->X1 = 4;
            this->X2 = 3;
            this->X3 = 5;
            break;
        case configuracion3:
            this->alto = 20;
            this->ancho = 20;
            this->largo = 20;
            this->X1 = 5;
            this->X2 = 4;
            this->X3 = 6;
            break;
    }
   
    
}

unsigned int Tablero::getX1(){
    return X1;
}

unsigned int Tablero::getX2(){
    return X2;
}

unsigned int Tablero::getX3(){
    return X3;
}


unsigned int Tablero::getAlto(){
    return this->alto;
}

unsigned int Tablero::getAncho(){
    return this->ancho;
}

unsigned int Tablero::getLargo(){
    return this->largo;
}

Turno Tablero::getTurno(){
    return this->turno;
}

Tablero::~Tablero()
{
    this->tablero->iniciarCursor();
    while(this->tablero->avanzarCursor()){
        Lista<Lista<Celda*>*>* temp = this->tablero->obtenerCursor();
        temp->iniciarCursor();
        while(temp->avanzarCursor()){
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->tablero;


}

void Tablero::definirCelulasVivas(){
    int metodo;
    char otroMetodo;
    do{

        do{
            cout << "Elija el método para ingresar células vivas: " << endl;
            cout << "1: Ingresar individualmente" << endl;
            cout << "2: Ingresar por rango" << endl;
            cin >> metodo;

        }while((metodo != 1) && (metodo != 2));
        if (metodo == 1){

            char seguir;
            
            do{
                unsigned int coordenadaX, coordenadaY, coordenadaZ;
                do{
                    cout << "Ingrese la primera cordenada: " << endl;
                    cin >> coordenadaX;
                }while((coordenadaX <= 0) || (coordenadaX > getAncho()));
                do{
                    cout << "Ingrese la segunda cordenada: " << endl;
                    cin >> coordenadaY;
                }while((coordenadaY <= 0) || (coordenadaY > getLargo()));
                do{
                    cout << "Ingrese la tercera cordenada: " << endl;
                    cin >> coordenadaZ;
                }while((coordenadaZ <= 0) || (coordenadaZ > getAlto()));

                getTablero()->obtener(coordenadaZ)->obtener(coordenadaY)->obtener(coordenadaX)->getCelula()->setEstado(vivo);

                cout << "La célula se ha ingresado con éxito la célula: (" << coordenadaX << ", " << coordenadaY << ", " << coordenadaZ << ") " << endl;
                do {
                    cout << "¿Desea seguir ingresando células? s/n" << endl;
                    cin >> seguir;
                }while((seguir != 's') && (seguir != 'n') && (seguir != 'S') && (seguir != 'N'));
                
            }while((seguir == 's') || (seguir == 'S'));
        }else if (metodo == 2){

            char seguir;

            do{
                unsigned int coordenadaX1, coordenadaY1, coordenadaZ1;
                do{
                    cout << "Ingrese la primera cordenada de la primera célula: " << endl;
                    cin >> coordenadaX1;
                }while((coordenadaX1 <= 0) || (coordenadaX1 > getAncho()));
                do{
                    cout << "Ingrese la segunda cordenada de la primera célula: " << endl;
                    cin >> coordenadaY1;
                }while((coordenadaY1 <= 0) || (coordenadaY1 > getLargo()));
                do{
                    cout << "Ingrese la tercera cordenada de la primera célula: " << endl;
                    cin >> coordenadaZ1;
                }while((coordenadaZ1 <= 0) || (coordenadaZ1 > getAlto()));

                unsigned int coordenadaX2, coordenadaY2, coordenadaZ2;
                do{
                    cout << "Ingrese la primera cordenada de la segunda célula: " << endl;
                    cin >> coordenadaX2;
                }while((coordenadaX2 <= 0) || (coordenadaX2 > getAncho()));
                do{
                    cout << "Ingrese la segunda cordenada de la segunda célula: " << endl;
                    cin >> coordenadaY2;
                }while((coordenadaY2 <= 0) || (coordenadaY2 > getLargo()));
                do{
                    cout << "Ingrese la tercera cordenada de la segunda célula: " << endl;
                    cin >> coordenadaZ2;
                }while((coordenadaZ2 <= 0) || (coordenadaZ2 > getAlto()));

                if (coordenadaX1 > coordenadaX2){
                    unsigned int aux = coordenadaX1;
                    coordenadaX1 = coordenadaX2;
                    coordenadaX2 = aux;
                }
                if (coordenadaY1 > coordenadaY2){
                    unsigned int aux = coordenadaY1;
                    coordenadaY1 = coordenadaY2;
                    coordenadaY2 = aux;
                }
                if (coordenadaZ1 > coordenadaZ2){
                    unsigned int aux = coordenadaZ1;
                    coordenadaZ1 = coordenadaZ2;
                    coordenadaZ2 = aux;
                }
            
                for (unsigned int z = coordenadaZ1; z <= coordenadaZ2; z++){
                    for (unsigned int y = coordenadaY1; y <= coordenadaY2; y++){
                        for (unsigned int x = coordenadaX1; x <= coordenadaX2; x++){
                            getTablero()->obtener(z)->obtener(y)->obtener(x)->getCelula()->setEstado(vivo);
                        }
                    }
                }

                cout << "El rango se ha ingresado con éxito" << endl;
                do {
                    cout << "¿Desea seguir ingresando rangos de células? s/n" << endl;
                    cin >> seguir;

                }while((seguir != 's') && (seguir != 'n') && (seguir != 'S') && (seguir != 'N'));

            }while((seguir == 's') || (seguir == 'S'));

        }

        do{
            cout << "¿Desea utilizar otro metodo para ingresar células? s/n" << endl;
            cin >> otroMetodo;
        }while((otroMetodo != 's') && (otroMetodo != 'n') && (otroMetodo != 'S') && (otroMetodo != 'N'));

    }while ((otroMetodo == 's') || (otroMetodo == 'S'));

    cout << "Las células fueron ingresadas con éxito" << endl;
    
}


void Tablero::contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina)
{ // x1: cels nesesarias para nacer; x2 y x3: cels para permanecer viva; en otro caso mueren
    int vecinasVivas = 0;
    unsigned int vecinaX;
    unsigned int vecinaY;
    unsigned int vecinaZ;
    Lista<Celda *> *listaVecinasVivas = new Lista<Celda *>;

    Celda *celdaCentro = this->tablero->obtener(fila)->obtener(columna)->obtener(pagina);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int k = -1; k < 1; ++k)
            {
                if ((int(fila) + i) == -1)
                {
                    vecinaX = getLargo();
                }
                else if ((int(fila) + i) == (int(getLargo()) + 1))
                {
                    vecinaX = 0;
                }
                else
                {
                    vecinaX = int(fila) + i;
                }

                if ((int(columna) + i) == -1)
                {
                    vecinaY = getAncho();
                }
                else if ((int(columna) + i) == (int(getAncho()) + 1))
                {
                    vecinaY = 0;
                }
                else
                {
                    vecinaY = int(columna) + i;
                }

                if ((int(pagina) + i) == -1)
                {
                    vecinaY = getAlto();
                }
                else if ((int(pagina) + i) == (int(getAlto()) + 1))
                {
                    vecinaY = 0;
                }
                else
                {
                    vecinaY = int(pagina) + i;
                }

                if (!(i == 0 && j == 0 && k == 0))
                {
                    if (this->tablero->obtener(vecinaX)->obtener(vecinaY)->obtener(vecinaZ)->getCelula()->getEstado() == vivo)
                    {
                        vecinasVivas++;
                        if (listaVecinasVivas->contarElementos() < getX1())
                        {
                            listaVecinasVivas->agregar(this->tablero->obtener(vecinaX)->obtener(vecinaY)->obtener(vecinaZ));
                        }
                    }
                }
            }
        }
        
    }

    Estado aux = celdaCentro->getCelula()->getEstado();

    celdaCentro->actualizarEstadoCelula(vecinasVivas, getX1(), getX2(), getX3(),  listaVecinasVivas);

    contabilizarCasos(aux, celdaCentro);


    listaVecinasVivas->iniciarCursor();
    while (listaVecinasVivas->avanzarCursor()){
        delete listaVecinasVivas->obtenerCursor();
    }
    delete listaVecinasVivas;

    
}

void Tablero::contabilizarCasos(Estado aux, Celda* celdaCentro){
    if((celdaCentro->getCelula()->getEstado() != aux)){
        if(aux == muerto){
            getTurno().setRenacidasEnTurno(getTurno().getRenacidasEnTurno() + 1);
        }else{
            getTurno().setMuertasEnTurno(getTurno().getMuertasEnTurno() + 1);
        }
    }
}

unsigned int Tablero::numeroAleatorio(unsigned int maximo)
{
    srand(time(NULL));
    return rand() % maximo + 1;
};

