#include "Ejercito.h"

Ejercito::Ejercito()
{
    finados=0;
    for(int i=0; i<7; i++)
    {
        soldados[i]=nullptr;
    }
       
}
Ejercito::~Ejercito(){}

void Ejercito::setFinados()
{
    finados++;
}

Personaje*& Ejercito::getSold(int índice)
{
    return soldados[índice];
}

int Ejercito::getFinados()
{
    return finados;
}