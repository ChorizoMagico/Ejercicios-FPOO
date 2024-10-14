#ifndef PROGRAMA_H
#define PROGRAMA_H
#include "Figura.h"
#include "Círculo.h"
#include "Rectángulo.h"
#include "Triángulo.h"
#include "Validaciones.h"
class Programa
{
    private:
        Figura *totalFiguras[50];
        int índice;
    public:
        Programa();
        ~Programa();
        void mostrarFiguras();
        void ingresarFiguras(Validaciones);
        void borrarFiguras();
        void menú(Validaciones);
};

#else
class Programa;

#endif