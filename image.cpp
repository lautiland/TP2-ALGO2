#include <iostream>
#include <fstream>
#include "EasyBMP.h"
#include "EasyBMP.cpp"
#include "tablero.h"

//SOLO PARA VISUAL
#include "tablero.cpp"

using namespace std;
int imagenesBitmap(Tablero *tablero)
{

    for (unsigned int i = 0; i < tablero->getLargo(); i++)
    {
        BMP imagen;
        imagen.SetSize(tablero->getAncho(), tablero->getAlto());
        imagen.SetBitDepth(8);

        for (unsigned int j = 1; j < imagen.TellWidth() - 1; ++j)
            for (unsigned int k = 1; k < imagen.TellHeight() - 1; ++k)
            {
                imagen(j, k)->Red = tablero->getTablero()->obtener(k)->obtener(i)->obtener(j)->getCelula()->getGen1();
                imagen(j, k)->Blue = tablero->getTablero()->obtener(k)->obtener(i)->obtener(j)->getCelula()->getGen2();
                imagen(j, k)->Green = tablero->getTablero()->obtener(k)->obtener(i)->obtener(j)->getCelula()->getGen3();
            }
        imagen.WriteToFile(char(i) + ".bmp");
    };

    return 0;
};