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
        int duraciónH;
        int duraciónM;
    
    public:
        Película();
        ~Película();
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
class Película;
#endif