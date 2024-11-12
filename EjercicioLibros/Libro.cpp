#include "Libro.h"

Libro::Libro()
{
    nombre="";
    numPáginas=0;
    págRotas=0;
}

Libro::Libro(string nombre, int páginas)
{
    this->nombre=nombre;
    numPáginas=páginas;
    págRotas=0;
}

Libro::~Libro(){}

string Libro::romper(int páginas)
{
    if(páginas <=0)
    {
        return "No se pueden romper "+to_string(páginas)+" páginas\n";
    }
    if(numPáginas==0)
    {
        return "No hay páginas para romper\n";
    }
    págRotas+=páginas;
    numPáginas+=-páginas;
    if(numPáginas<=0)
    {
        numPáginas=0;
    }
    return "Páginas rotas: "+to_string(págRotas)+"\n";
}

string Libro::getNombre()
{
    return nombre;
}

int Libro::getPáginas()
{
    return numPáginas;
}

int Libro::getPáginasRotas()
{
    return págRotas;
}

void Libro::setNombre(string nombre)
{
    this->nombre=nombre;
}

void Libro::setPáginas(int páginas)
{
    numPáginas=páginas;
}