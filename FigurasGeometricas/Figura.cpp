#include "Figura.h"

Figura::Figura()
{
    color="";
}

Figura::Figura(string color)
{
    this->color=color;
}
Figura::~Figura(){}

double Figura::calcularÁrea()
{
    cout<<"La figura genérica no tiene medidas para calcular el área"<<endl;
    return 0.0;
}

double Figura::calcularPerímetro()
{
    cout<<"La figura genérica no tiene medidas para calcular el perímetro"<<endl;
    return 0.0;
}
string Figura::mostrarAtributos()
{
    return "Color: "+color+"\n";
}