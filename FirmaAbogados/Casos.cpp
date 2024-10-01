#include "Casos.h"

Casos::Casos()
{
    número=-1;
}
Casos::~Casos(){}

int Casos::getNúmero()
{
    return número;
}

string Casos::getID()
{
    return id;
}

string Casos::getCliente()
{
    return cliente;
}

void Casos::setNúmero(int número)
{
    this->número=número;
}

void Casos::setID(string id)
{
    this->id=id;
}

void Casos::setCliente(string cliente)
{
    this->cliente=cliente;
}