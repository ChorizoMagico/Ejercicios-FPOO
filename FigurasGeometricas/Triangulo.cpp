#include "Triangulo.h"
//constructor vacío
Triangulo::Triangulo(): Figura()
{
    lado1=0;
    lado2=0;
    lado3=0;
    base=0;
    altura=0;
    tipo="";
}
//constructor
Triangulo::Triangulo(string color, string tipo, double altura, double base, double lado1, double lado2, double lado3): Figura(color)
{
    this->lado1=lado1;
    this->lado2=lado2;
    this->lado3=lado3;
    this->tipo=tipo;
    this->altura=altura;
    this->base=altura;
}
//destructor
Triangulo::~Triangulo(){}

double Triangulo::calcularÁrea()
{
    double área=0;
    área=base*altura;
    return área;
}

double Triangulo::calcularPerímetro()
{
    double per=0;
    per=lado1+lado2+lado3;
    return per;
}

string Triangulo::mostrarAtributos()
{
    string lista="";
    lista="Color: " + color + " Base: " + to_string(base) + " Altura: "  +to_string(altura) + "\n" +
        "Lado 1: " + to_string(lado1) + " Lado 2: " + to_string(lado2) + " Lado 3: " + to_string(lado3)
        + "\nÁrea: " + to_string(calcularÁrea()) + " Perímetro: " + to_string(calcularPerímetro());
    return lista;
}
