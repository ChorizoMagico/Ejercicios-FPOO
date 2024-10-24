#include "Ejército.h"

Ejército::Ejército()
{
    finados=0;
    for(int i=0; i<7; i++)
    {
        soldados[i]=nullptr;
    }
       
}
Ejército::~Ejército(){}

void Ejército::setFinados()
{
    finados++;
}

Personaje*& Ejército::getSold(int índice)
{
    return soldados[índice];
}

int Ejército::getFinados()
{
    return finados;
}