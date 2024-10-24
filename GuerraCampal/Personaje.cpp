#include "Personaje.h"
Personaje::Personaje()
{
    vida=0;
    daño=0;
    vivo=true;
}

Personaje::Personaje(int vida, int daño)
{
    this->vida=vida;
    this->daño=daño;
    vivo=true;
}

Personaje::~Personaje(){}

void Personaje::atacar(Personaje*& enemigo)
{
    enemigo->setVida(enemigo->getVida()-daño);
}

int Personaje::getVida()
{
    return vida;
}
        
void Personaje::setVida(int nuevaVida)
{
    vida=nuevaVida;
    if(vida<=0)
    {
        vivo=false;
    }
}

string Personaje::getEstado()
{
    if(vivo==true)
    {
        return "Vivo";
    }
    else
    {
        return "Muerto";
    }
}