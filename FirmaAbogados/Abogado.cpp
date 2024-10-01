#include "Abogado.h"
#include "Casos.h"
#include <string>
using namespace std;

Abogado::Abogado()
{
    nombre="";
}
Abogado::~Abogado(){}
void Abogado::setID(string id)
{
    this->id=id;
}

void Abogado::setNombre(string nombre)
{
    this->nombre=nombre;
}

void Abogado::setTeléfono(string teléfono)
{
    this->teléfono=teléfono;
}
        
void Abogado::setEmail(string email)
{
    this->email=email;
}

void Abogado::setEspecialidad(string especialidad)
{
    this->especialidad=especialidad;
}
        
string Abogado::getNombre()
{
    return nombre;
}

string Abogado::getID()
{
    return id;
}

string Abogado::getTeléfono()
{
    return teléfono;
}
    
string Abogado::getEmail()
{
    return email;
}

string Abogado::getEspecialidad()
{
    return especialidad;
}

Casos& Abogado::getCasos(int índice)
{
    return totalCasos[índice];
}