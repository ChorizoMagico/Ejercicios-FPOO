#ifndef PELICULA_H
#define PELICULA_H
#include <string>
#include "Programacion.h"
using namespace std;
class Pelicula
{
    private:
        string nombre;
        string género;
        double precio;
        int duraciónH;
        int duraciónM;
    
    public:
        Pelicula();
        ~Pelicula();
        void setNombre(string);
        void setGénero(string);
        void setPrecio(double);
        void setDuraciónH(int);
        void setDuraciónM(int);
        string getNombre();
        string getGénero();
        int getDuraciónH();
        int getDuraciónM();
};

#else
class Pelicula;
#endif