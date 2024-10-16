#ifndef EJÉRCITO_H
#define EJÉRCITO_H
#include "Personaje.h"
class Ejército
{
    private:
        Personaje *soldados[7];
        int finados;
    
    public:
        Ejército();
        ~Ejército();
        void setFinados();
        Personaje getSold(int);

};

#else
class Ejército;
#endif