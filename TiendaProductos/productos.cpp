#include "productos.h"

Productos::Productos(){
    nombre="";
}
Productos::~Productos(){}

void Productos::setNombre(string nombre)
{
    this->nombre=nombre;
}

void Productos::setPrecio(double precio)
{
    this->precio=precio;
}

void Productos::setStock(int stock)
{
    this->stock=stock;
}

string Productos::getNombre()
{
    return nombre;
}

double Productos::getPrecio()
{
    return precio;
}

int Productos::getStock()
{
    return stock;
}