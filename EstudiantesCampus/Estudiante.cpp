#include "Estudiante.h"

Estudiante::Estudiante(): Persona()
{
    código="";
    carrera="";
}
        
Estudiante::Estudiante(string nombre, int edad, string código, string carrera): Persona(nombre, edad)
{
    this->código=código;
    this->carrera=carrera;
}

Estudiante::~Estudiante(){}

string Estudiante::getCódigo()
{
    return código;
}
        
string Estudiante::getCarrera()
{
    return carrera;
}
        
string Estudiante::getInfo()
{
    return "Los datos de la persona son: \nNombre: "+getNombre()+" \tEdad: "+to_string(getEdad())+"\tCódigo: "+getCódigo()+"\tCarrera: "+getCarrera()+"\n";
}