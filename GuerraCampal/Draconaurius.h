#ifndef DRACONAURIUS_H
#define DRACONAURIUS_H
#include "Personaje.h"
class Draconaurius: public Personaje
{
    public:
        Draconaurius();
        Draconaurius(int, int);
        ~Draconaurius();
};

#else
class Draconaurius;

#endif