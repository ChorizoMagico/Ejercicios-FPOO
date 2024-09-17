#ifndef SALA_H
#define SALA_H
#include <string>
using namespace std;
#include "Película.h"
#include "Programación.h"

class Sala
{
    private:
        string nombre;
        Programación programaciónDía[4];
    public:
        Sala();
        ~Sala();
        void setNombre(string);
        void setProgramación(int, int, int, int, int);
        Programación& getProgramación(int);
        string getNombre();

};

#else
class Sala;
#endif