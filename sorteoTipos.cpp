#include "sorteoTipos.h"

using namespace std;

int numeroAleatorio(int maximo)
{
    srand(time(NULL));
    return rand() % maximo + 1;
};

void editaTipo(int alto, int largo, int ancho, Tablero *tablero)
{

    for (int i = 0; i < numeroAleatorio(int((alto * largo * ancho) % 5)); i++)
    {
        unsigned int x = numeroAleatorio(ancho);
        unsigned int y = numeroAleatorio(largo);
        unsigned int z = numeroAleatorio(alto);
        tablero->getTablero()->obtener(x)->obtener(y)->obtener(z)->setTipo(Tipo(numeroAleatorio(6)));
    };
};
