#include "Producto.h"

Producto::Producto()
{
    nombre="";
    stock=0;
}

Producto::~Producto(){}

void Producto::setNombre(string nombre)
{
    this->nombre=nombre;
}

void Producto::setPrecio(double precio)
{
    this->precio=precio;
}

void Producto::setStock(int stock)
{
    this->stock=stock;
}

string Producto::getNombre()
{
    return nombre;
}

double Producto::getPrecio()
{
    return precio;
}

int Producto::getStock()
{
    return stock;
}
