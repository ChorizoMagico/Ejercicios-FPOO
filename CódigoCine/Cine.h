#ifndef CINE_H
#define CINE_H
#include <string>
using namespace std;
#include "Sala.h"
#include "Película.h"

class Cine
{
    private:
        Sala totalSalas[5];
        Película totalPelículas[20];
    
    public:
        Cine();
        ~Cine();
        void ingresarPelículas(double);
        void ingresarSala();
        void consultarGénero();
        void consultarHorario();

};

#else
class Cine;
#endif