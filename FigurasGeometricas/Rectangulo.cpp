#include "Rectangulo.h"
Rectangulo::Rectangulo(): Figura()
{
    base=0;
    altura=0;
}
        
Rectangulo::Rectangulo(string color, double base, double altura): Figura(color)
{
    this->base=base;
    this->altura=altura;
}
        
Rectangulo::~Rectangulo(){}

double Rectangulo::calcularÁrea()
{
    double área=0;
    área=base*altura;
    return área;
}

double Rectangulo::calcularPerímetro()
{
    double per=0;
    per=2*base+2*altura;
    return per;
}

string Rectangulo::mostrarAtributos()
{
    string lista="";
    lista=color+" "+"Base: "+to_string(base)+" Altura: "+to_string(altura)+"\n"+"Perímetro: "+
        to_string(calcularPerímetro())+ " Área: "+to_string(calcularÁrea());
    return lista;
}

