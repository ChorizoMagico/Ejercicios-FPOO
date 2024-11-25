#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Figura.h"

class Triangulo: public Figura
{
    private:
        double base, altura, lado1, lado2, lado3;
        string tipo;
    
    public:
        Triangulo();
        Triangulo(string, string, double, double, double, double, double);
        ~Triangulo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();

};

#else
class Triangulo;
#endif