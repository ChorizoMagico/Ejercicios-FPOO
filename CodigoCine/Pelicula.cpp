#include "Pelicula.h"

/*
Constructor*/
Pelicula::Pelicula()
{
    nombre="";
}
/*Destructor
*/
Pelicula::~Pelicula(){}

/*Asigna un string al atributo nombre del objeto película*/
void Pelicula::setNombre(string nombre)
{
    this->nombre=nombre;
}

/*Asigna un string al atributo género del objeto película*/
void Pelicula::setGénero(string género)
{
    this->género=género;
}

/*En base al atributo género y a la variable global precioBase, asigna un double al atributo precio*/
void Pelicula::setPrecio(double precioBase)
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

/*Le asigna un entero al atributo duraciónH*/
void Pelicula::setDuraciónH(int duraciónH)
{
    this->duraciónH=duraciónH;
}

/*Le asigna un entero al atributo duraciónM*/
void Pelicula::setDuraciónM(int duraciónM)
{
    this->duraciónM=duraciónM;
}

/*Devuelve un string que corresponde con el atributo nombre*/
string Pelicula::getNombre()
{
    return nombre;
}
/*Devuelve un string que corresponde con el atributo género*/
string Pelicula::getGénero()
{
    return género;
}
/*Devuelve un entero que corresponde al atributo duraciónH*/
int Pelicula::getDuraciónH()
{
    return duraciónH;
}
/*Devuelve un entero que corresponde el atributo duraciónM*/
int Pelicula::getDuraciónM()
{
    return duraciónM;
}
