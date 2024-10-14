#ifndef RECTÁNGULO_H
#define RECTÁNGULO_H
#include "Figura.h"

class Rectángulo: public Figura
{
    private:
        double base;
        double altura;
    
    public:
        Rectángulo();
        Rectángulo(string, double, double);
        ~Rectángulo();
        double calcularÁrea();
        double calcularPerímetro();
        string mostrarAtributos();

};

#else
class Rectángulo;
#endif