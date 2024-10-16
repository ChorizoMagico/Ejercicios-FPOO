#include "Batalla.h"

Batalla::Batalla()
{
    numTurno=0;
}
Batalla::~Batalla(){}

void Batalla::turno(Validaciones val)
{
    int opc=0;
    numTurno++;
    cout<<"Turno "<<numTurno<<"\nEstado actual de la batalla:\n"
        <<"Ejército 1:\t\tEjército 2"
        <<"Arquero ++ 1: "<<dosEjércitos[0].getSold(0).getEstado()<<"\t\tDraconaurius++ 1: "<<dosEjércitos[1].getSold(0).getEstado();
    opc=stoi(val.leerI("¿Qué desea hacer?\n1. Ataque del primer ejército\n2. Ataque del segundo ejército\n3. Salir\n"));
}