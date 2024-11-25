#include "Programacion.h"
#include <iostream>
#include <string>
using namespace std;

/*Constructor*/
Programacion::Programacion()
{
    nombrePelícula="vacío";
    horaFin=0;
    minFin=0;
    horaInicio=0;
    minInicio=0;
}
/*Destructor*/
Programacion::~Programacion(){}

/*Devuelve el atributo horaInicio*/
int Programacion::getHoraInicio()
{
    return horaInicio;
}
/*Devuelve el atributo minInicio*/
int Programacion::getMinInicio()
{
    return minInicio;
}
/*Devuelve el atributo horaFin*/
int Programacion::getHoraFin()
{
    return horaFin;
}
/*Devuelve el atributo minFin*/
int Programacion::getMinFin()
{
    return minFin;
}
/*Le asigna un string al atributo nombrePelícula*/
void Programacion::setNombre(string nombre)
{
    nombrePelícula=nombre;
}
/*Asigna un entero al atributo horaInicio*/
void Programacion::setHoraInicio(int horaInicio)
{
    this->horaInicio=horaInicio;
}
/*Asigna un entero al atributo minInicio*/
void Programacion::setMinInicio(int minInicio)
{
    this->minInicio=minInicio;
}
/*Asigna un entero al atributo horaFin*/
void Programacion::setHoraFin(int horaFin)
{
    this->horaFin=horaFin;
}
/*Asigna un entero al atributo minFin*/
void Programacion::setMinFin(int minFin)
{
    this->minFin=minFin;
}
/*Devuelve el atributo nombrePelícula*/
string Programacion::getNombre()
{
    return nombrePelícula;
}

