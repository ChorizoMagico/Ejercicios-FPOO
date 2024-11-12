#include "Persona.h"

Persona::Persona()
{
    nombre="";
    unLibro=nullptr;
}

Persona::Persona(string nombre)
{
    this->nombre=nombre;
    unLibro=nullptr;
}

Persona::~Persona(){}
        
Libro* Persona::prestar(Libro* libroAPrestar)
{
    if(unLibro==nullptr or libroAPrestar->getNombre()!=unLibro->getNombre())
    {
        cout<<"El libro "<<(*libroAPrestar).getNombre()<<" no está en la posesión de "<<nombre<<endl;
        return nullptr;
    }
    else
    {
       Libro* libroCopia= unLibro;
       unLibro=nullptr;
       return libroCopia;
    }
}

string Persona::recibe(Libro* libroRecibido)
{
    if(libroRecibido== nullptr)
    {
        return "No se ha recibido un libro válido\n";
    }
    else
    {
        unLibro=libroRecibido;
        return "Libro "+libroRecibido->getNombre()+" recibido\n";
    }
}

string Persona::rompePáginas(int páginasARomper)
{
    if(unLibro==nullptr)
    {
        return "No hay ningún libro en posesión para romper páginas\n";
    }
    else
    {
        unLibro->romper(páginasARomper);
        return "Páginas rotas.\n";
    }
}

string Persona::getNombre()
{
    return nombre;
}

Libro* Persona::getLibro()
{
    return unLibro;
}

void Persona::setNombre(string nombre)
{
    this->nombre=nombre;
}

void Persona::setLibro(Libro* libro)
{
    unLibro=libro;
}