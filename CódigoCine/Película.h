#ifndef PELÍCULA_H
#define PELÍCULA_H
#include <string>
#include "Programación.h"
using namespace std;
class Película
{
    private:
        string nombre;
        string género;
        double precio;
        Programación programación;
    
    public:
        Película();
        ~Película();
        void setNombre(string);
        void setGénero(string);
        void setPrecio(double);
        void setProgramación(int, int, int, int);
        string getNombre();
        string getGénero();
        Programación getProgramación();
};

#else
class Película;
#endif