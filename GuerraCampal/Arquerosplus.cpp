#include "Arquerosplus.h"

void Arquerosplus::setVida(int nuevaVida)
{
    vida=nuevaVida;
    if(vida<=0)
    {
        cout<<"Arquero ++ debilitado"<<endl;
        debilitado=true;
    }
}

string Arquerosplus::getEstado()
{
    if(debilitado==false)
    {
        return "Vivo";
    }
    else
    {
        return "Debilitado";
    }
}

Arquerosplus::Arquerosplus(): Personaje() 
{
    debilitado==false;
}

Arquerosplus::Arquerosplus(int vida=7, int daño=5): Personaje(vida, daño){}

Arquerosplus::~Arquerosplus(){}