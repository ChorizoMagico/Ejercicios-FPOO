#ifndef ARQUEROS_H
#define ARQUEROS_H
#include "Personaje.h"

class Arqueros: public Personaje
{
    public:
        Arqueros();
        Arqueros(int, int);
        ~Arqueros();

};

#else
class Arqueros;
#endif
