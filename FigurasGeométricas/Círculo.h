#ifndef CÍRCULO_H
#define CÍRCULO_H
#include "Figura.h"

class Círculo: public Figura
{
    private:
        double radio;

    public:
        Círculo();
        Círculo(string, double);
        ~Círculo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();
};

#else
class Círculo;
#endif
