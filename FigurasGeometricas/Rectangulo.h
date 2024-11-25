#ifndef RECTANGULO_H
#define RECTANGULO_H
#include "Figura.h"

class Rectangulo: public Figura
{
    private:
        double base;
        double altura;
    
    public:
        Rectangulo();
        Rectangulo(string, double, double);
        ~Rectangulo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();

};

#else
class Rectangulo;
#endif