#include "Programación.h"
#include <iostream>
#include <string>
using namespace std;

/*Constructor*/
Programación::Programación(){}
/*Destructor*/
Programación::~Programación(){}

/*Devuelve el atributo horaInicio*/
int Programación::getHoraInicio()
{
    return horaInicio;
}
/*Devuelve el atributo minInicio*/
int Programación::getMinInicio()
{
    return minInicio;
}
/*Devuelve el atributo horaFin*/
int Programación::getHoraFin()
{
    return horaFin;
}
/*Devuelve el atributo minFin*/
int Programación::getMinFin()
{
    return minFin;
}
/*Le asigna un string al atributo nombrePelícula*/
void Programación::setNombre(string nombre)
{
    nombrePelícula=nombre;
}
/*Asigna un entero al atributo horaInicio*/
void Programación::setHoraInicio(int horaInicio)
{
    this->horaInicio=horaInicio;
}
/*Asigna un entero al atributo minInicio*/
void Programación::setMinInicio(int minInicio)
{
    this->minInicio=minInicio;
}
/*Asigna un entero al atributo horaFin*/
void Programación::setHoraFin(int horaFin)
{
    this->horaFin=horaFin;
}
/*Asigna un entero al atributo minFin*/
void Programación::setMinFin(int minFin)
{
    this->minFin=minFin;
}
/*Devuelve el atributo nombrePelícula*/
string Programación::getNombre()
{
    return nombrePelícula;
}

