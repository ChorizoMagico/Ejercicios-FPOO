#ifndef TRIÁNGULO_H
#define TRIÁNGULO_H
#include "Figura.h"

class Triángulo: public Figura
{
    private:
        double base, altura, lado1, lado2, lado3;
        string tipo;
    
    public:
        Triángulo();
        Triángulo(string, string, double, double, double, double, double);
        ~Triángulo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();

};

#else
class Triángulo;
#endif