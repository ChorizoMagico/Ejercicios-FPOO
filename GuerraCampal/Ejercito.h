#ifndef EJERCITO_H
#define EJERCITO_H
#include "Personaje.h"
#include "Arqueros.h"
#include "Arquerosplus.h"
#include "Draconaurius.h"
#include "Draconauriusplus.h"

class Ejercito
{
    private:
        Personaje* soldados[7];
        int finados;
    
    public:
        Ejercito();
        ~Ejercito();
        void setFinados();
        int getFinados();
        Personaje*& getSold(int);

};

#else
class Ejercito;
#endif