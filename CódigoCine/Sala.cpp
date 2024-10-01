#include "Sala.h"
/*
Constructor*/
Sala::Sala()
{
    nombre="Sin nombre";
}
/*
Destructor*/
Sala::~Sala(){}
/*
Le asigna un string al atributo nombre del objeto sala*/
void Sala::setNombre(string nombreAsignar)
{
    nombre=nombreAsignar;
}

/*
Le asigna a un solo objeto Programación  del arreglo de objetos programaciónDía[5] sus atributos de horaInicio, minInicio, horaFin y minFin*/
void Sala::setProgramación(int número, int horaInicio, int minInicio, int horaFin, int minFin)
{
    programaciónDía[número].setHoraInicio(horaInicio);
    programaciónDía[número].setMinInicio(minInicio);
    programaciónDía[número].setHoraFin(horaFin);
    programaciónDía[número].setMinFin(minFin);
}
/*
Devuelve un objeto Programación del arreglo de objetos programaciónDía[5]*/
Programación& Sala::getProgramación(int número)
{
    return programaciónDía[número];
}
/*
Devuelve el atributo nombre del objeto sala*/

string Sala::getNombre()
{
    return nombre;
}