#include "Círculo.h"
Círculo::Círculo(): Figura()
{
    radio=0;
}

Círculo::Círculo(string color, double radio): Figura(color)
{
    this->radio=radio;
}

Círculo::~Círculo(){}

double Círculo::calcularÁrea()
{
    double área=0;
    área=M_PI*pow(radio,2);
    return área;
}

double Círculo::calcularPerímetro()
{
    double per=0;
    per=2*M_PI*radio;
    return per;
}

string Círculo::mostrarAtributos()
{
    string atributos="";
    atributos+=color+" "+to_string(radio)+" \nÁrea: "+to_string(calcularÁrea())+ " Perímetro: "+to_string(calcularPerímetro())+"\n";
    return atributos;
}