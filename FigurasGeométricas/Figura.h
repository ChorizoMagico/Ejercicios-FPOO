#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Figura
{
    protected:
        string color;

    public:
        Figura();
        Figura(string);
        virtual ~Figura();
        virtual double calcularÁrea();
        virtual double calcularPerímetro();
        virtual string mostrarAtributos();
};

#else
class Figura;
#endif