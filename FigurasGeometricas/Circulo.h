#ifndef CIRCULO_H
#define CIRCULO_H
#include "Figura.h"

class Circulo: public Figura
{
    private:
        double radio;

    public:
        Circulo();
        Circulo(string, double);
        ~Circulo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();
};

#else
class Circulo;
#endif
