#ifndef EJÉRCITO_H
#define EJÉRCITO_H
#include "Personaje.h"
#include "Arqueros.h"
#include "Arquerosplus.h"
#include "Draconaurius.h"
#include "Draconauriusplus.h"

class Ejército
{
    private:
        Personaje* soldados[7];
        int finados;
    
    public:
        Ejército();
        ~Ejército();
        void setFinados();
        int getFinados();
        Personaje*& getSold(int);

};

#else
class Ejército;
#endif