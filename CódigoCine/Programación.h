#ifndef PROGRAMACIÓN_H
#define PROGRAMACIÓN_H
#include <string>
using namespace std;
class Programación
{
    private:
        string nombrePelícula;
        int horaInicio;
        int minInicio;
        int horaFin;
        int minFin;

    public:
        Programación();
        ~Programación();
        int getHoraInicio();
        int getMinInicio();
        int getHoraFin();
        int getMinFin();
        void setNombre(string);
        void setHoraInicio(int);
        void setMinInicio(int);
        void setHoraFin(int);
        void setMinFin(int);
        string getNombre();
};

#else
class Programación;

#endif