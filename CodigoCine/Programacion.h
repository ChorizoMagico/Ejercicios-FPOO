#ifndef PROGRAMACION_H
#define PROGRAMACION_H
#include <string>
using namespace std;
class Programacion
{
    private:
        string nombrePelícula;
        int horaInicio;
        int minInicio;
        int horaFin;
        int minFin;

    public:
        Programacion();
        ~Programacion();
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
class Programacion;

#endif