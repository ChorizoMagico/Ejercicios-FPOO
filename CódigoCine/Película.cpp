#include "Película.h"

/*
Constructor*/
Película::Película(){}
/*Destructor
*/
Película::~Película(){}

/*Asigna un string al atributo nombre del objeto película*/
void Película::setNombre(string nombre)
{
    this->nombre=nombre;
}

/*Asigna un string al atributo género del objeto película*/
void Película::setGénero(string género)
{
    this->género=género;
}

/*En base al atributo género y a la variable global precioBase, asigna un double al atributo precio*/
void Película::setPrecio(double precioBase)
{
    if(género=="comedia" or género=="drama")
        precio=precioBase+precioBase*0.1;
    else
    {
        if(género=="romance" or género=="acción")
            precio=precioBase+precioBase*0.15;
        else
        {
            if(género=="suspenso" or género=="terror")
                precio=precioBase+precioBase*0.18;
            else
            {
                if(género=="ciencia ficción" or género=="fantasía")
                    precio=precioBase+precioBase*0.23;
            }
        }
    }
}
/*Le asigna al objeto programación los atributos horaInicio, minInicio, horaFin y minFin*/
void Película::setProgramación(int horaInicio, int minInicio, int horaFin, int minFin)
{
    programación.setHoraInicio(horaInicio);
    programación.setMinInicio(minInicio);
    programación.setHoraFin(horaFin);
    programación.setMinFin(minFin);
}
/*Devuelve un string que corresponde con el atributo nombre*/
string Película::getNombre()
{
    return nombre;
}
/*Devuelve un string que corresponde con el atributo género*/
string Película::getGénero()
{
    return género;
}
/*Devuelve un objeto Programación que corresponde con el atributo programación*/
Programación Película::getProgramación()
{
    return this-> programación;
}