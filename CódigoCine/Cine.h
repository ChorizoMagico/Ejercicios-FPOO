#ifndef CINE_H
#define CINE_H
#include "Sala.h"
#include "Película.h"
#include "Validaciones.h"

class Cine
{
    private:
        Sala totalSalas[5];
        Película totalPelículas[20];
    
    public:
        Cine();
        ~Cine();
        void ingresarPelículas(double, Validaciones&);
        void ingresarSala(Validaciones&);
        void consultarGénero(Validaciones&);
        void consultarHorario(Validaciones&);

};

#else
class Cine;
#endif