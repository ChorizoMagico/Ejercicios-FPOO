#include "Circulo.h"
Circulo::Circulo(): Figura()
{
    radio=0;
}

Circulo::Circulo(string color, double radio): Figura(color)
{
    this->radio=radio;
}

Circulo::~Circulo(){}

double Circulo::calcularÁrea()
{
    double área=0;
    área=M_PI*pow(radio,2);
    return área;
}

double Circulo::calcularPerímetro()
{
    double per=0;
    per=2*M_PI*radio;
    return per;
}

string Circulo::mostrarAtributos()
{
    string atributos="";
    atributos+=color+" "+to_string(radio)+" \nÁrea: "+to_string(calcularÁrea())+ " Perímetro: "+to_string(calcularPerímetro())+"\n";
    return atributos;
}