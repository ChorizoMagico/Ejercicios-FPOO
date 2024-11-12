#include "Funcionario.h"

Funcionario::Funcionario(): Persona()
{
    salario=0;
    cargo="";
}

Funcionario::Funcionario(string nombre, int edad, double salario, string cargo): Persona(nombre, edad)
{
    this->salario=salario;
    this->cargo=cargo;
}
        
Funcionario::~Funcionario(){}
        
double Funcionario::getSalario()
{
    return salario;
}

string Funcionario::getCargo()
{
    return cargo;
}

string Funcionario::getInfo()
{
    return "Los datos de la persona son: \nNombre: "+getNombre()+" \tEdad: "+to_string(getEdad())+"\tSalario: "+to_string(getSalario())+"\tCargo: "+getCargo()+"\n";
}