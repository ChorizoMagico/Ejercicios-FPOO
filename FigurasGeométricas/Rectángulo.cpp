#include "Rectángulo.h"
Rectángulo::Rectángulo(): Figura()
{
    base=0;
    altura=0;
}
        
Rectángulo::Rectángulo(string color, double base, double altura): Figura(color)
{
    this->base=base;
    this->altura=altura;
}
        
Rectángulo::~Rectángulo(){}

double Rectángulo::calcularÁrea()
{
    double área=0;
    área=base*altura;
    return área;
}

double Rectángulo::calcularPerímetro()
{
    double per=0;
    per=2*base+2*altura;
    return per;
}

string Rectángulo::mostrarAtributos()
{
    string lista="";
    lista=color+" "+"Base: "+to_string(base)+" Altura: "+to_string(altura)+"\n"+"Perímetro: "+
        to_string(calcularPerímetro())+ " Área: "+to_string(calcularÁrea());
    return lista;
}

