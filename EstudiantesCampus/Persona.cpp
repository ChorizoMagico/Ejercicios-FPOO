#include "Persona.h"

Persona::Persona()
{
    nombre="";
    edad=0;
}

Persona::Persona(string nombre, int edad)
{
    this->nombre=nombre;
    this->edad=edad;
}

Persona::~Persona(){}

string Persona::getNombre()
{
    return nombre;
}

int Persona::getEdad()
{
    return edad;
}

string Persona::getInfo()
{
    return "Los datos de la persona son: \nNombre: "+getNombre()+" \tEdad: "+to_string(getEdad())+"\n";
}