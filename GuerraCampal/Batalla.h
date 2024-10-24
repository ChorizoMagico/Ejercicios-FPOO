#ifndef BATALLA_H
#define BATALLA_H
#include "Ejército.h"
#include "Validaciones.h"
class Batalla
{
    private:
        Ejército dosEjércitos[2];
        int numTurno;
    
    public:
        Batalla();
        ~Batalla();
        void turno(Validaciones);
        void cerrar();
        void estadoActual();
};

#else
class Batalla;
#endif 