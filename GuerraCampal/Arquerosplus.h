#ifndef ARQUEROSPLUS_H
#define ARQUEROSPLUS_H
#include "Personaje.h"

class Arquerosplus: public Personaje
{
    private:
        bool debilitado;
    public:
        Arquerosplus();
        Arquerosplus(int, int);
        ~Arquerosplus();
        void setVida(int);
        string getEstado();

};

#else
class Arquerosplus;
#endif
