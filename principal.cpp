#include <iostream>
#include "principal.h"
using namespace std;

void bienvenida()
{
    cout << endl
         << endl;
    cout << "       ______ _     _                              _        _               _     _       " << endl;
    cout << "      |  ____| |   (_)                            | |      | |             (_)   | |      " << endl;
    cout << "      | |__  | |    _ _   _  ___  __ _  ___     __| | ___  | | __ _  __   ___  __| | __ _ " << endl;
    cout << "      |  __| | |   | | | | |/ _ \\/ _` |/ _ \\   / _` |/ _ \\ | |/ _` | \\ \\ / / |/ _` |/ _` |" << endl;
    cout << "      | |____| |   | | |_| |  __/ (_| | (_) | | (_| |  __/ | | (_| |  \\ V /| | (_| | (_| |" << endl;
    cout << "      |______|_|   | |\\__,_|\\___|\\__, |\\___/   \\__,_|\\___| |_|\\__,_|   \\_/ |_|\\__,_|\\__,_|" << endl;
    cout << "                  _/ |            __/ |                                                   " << endl;
    cout << "                 |__/            |___/                                                    " << endl;
    cout << endl
         << endl
         << endl;
}

void resolverTurno(Tablero *tablero)
{
    Tablero *temp = new Tablero(tablero);

    for (unsigned int i = 0; i < tablero->getLargo(); i++)
    {
        for (unsigned int j = 0; j < tablero->getAncho(); j++)
        {
            for (unsigned int k = 0; k < tablero->getAlto(); k++)
            {

                tablero->contadorCelulasVecinas(i, j, k, temp);
                tablero->getTurno()->setPromedioNacidas(tablero->getTurno()->getRenacidasEnTurno());
                tablero->getTurno()->setPromedioMuertas(tablero->getTurno()->getMuertasEnTurno());
            }
        }
    }
    tablero->getTurno()->comparacionDeTurnos(temp->getTurno());
    tablero = temp;
    delete temp;
}

ModoDeJuego configurar()
{
    ModoDeJuego configuracion;
    int opcion;
    cout << "Elija una configuracion para las dimensiones del Tablero:" << endl;
    cout << "1: Configuracion manual." << endl;
    cout << "2: Tablero de 5x5x5 con estandares bajos de generacion de celulas." << endl;
    cout << "3: Tablero de 10x10x10 con estandares medios de generacion de celulas." << endl;
    cout << "4: Tablero de 20x20x20 con estandares altos de generacion de celulas." << endl
         << endl;
    cin >> opcion;
    cout << endl;

    switch (opcion)
    {
    case 1:
        configuracion = manual;
        break;
    case 2:
        configuracion = configuracion1;
        break;
    case 3:
        configuracion = configuracion2;
        break;
    case 4:
        configuracion = configuracion3;
        break;
    default:
        break;
    }
    return configuracion;
}

//------------------------>
AccionTurno preguntarTurno(Tablero *partida)
{
    int respuesta;
    std::cout << "Indique la accion deseada para el siguiente turno: " << std::endl;
    std::cout << "1: Continuar el juego." << std::endl;
    std::cout << "2: Reiniciar la partida." << std::endl;
    std::cout << "3: Terminar el juego." << std::endl;
    std::cin >> respuesta;
    switch (respuesta)
    {
    case 1:
        partida->getTurno()->siguienteTurno();
        return continuar;
        break;
    case 2:
        partida->~Tablero();
        partida = new Tablero(configurar());
        return reiniciar;
        break;
    case 3:
        return terminar;
        break;

    default:
        return preguntarTurno(partida);
        break;
    }
};

int imagenesBitmap(Tablero *tablero)
{
    char nombre[5];
    const char * pagina = &nombre[0];
    for (unsigned int i = 0; i < tablero->getLargo(); i++)
    {
        BMP imagen;
        imagen.SetSize(tablero->getAncho(), tablero->getAlto());
        imagen.SetBitDepth(8);

        for (unsigned int j = 0; j < imagen.TellWidth(); ++j)
            for (unsigned int k = 0; k < imagen.TellHeight(); ++k)
            {
                imagen(j, k)->Red = tablero->getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1)->getCelula()->getGen1();
                imagen(j, k)->Blue = tablero->getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1)->getCelula()->getGen2();
                imagen(j, k)->Green = tablero->getTablero()->obtener(i+1)->obtener(j+1)->obtener(k+1)->getCelula()->getGen3();
                
            }
        nombre[0] = char(65+i);
        nombre[1] = '.';
        nombre[2] = 'b';
        nombre[3] = 'm';
        nombre[4] = 'p';
        imagen.WriteToFile(pagina);
    };
    

    return 0;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    bienvenida();

    Tablero *partida = new Tablero(configurar());

    do
    {
        
        partida->definirCelulasVivas();

        //imagenesBitmap(partida);

        partida->imprimirTablero();

    } while (preguntarTurno(partida) != terminar);

    return 0;
}
