#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <string>
#include <iostream>
using namespace std;

class Validaciones
{
    public:
        Validaciones();
        ~Validaciones();
        bool validarEntero(string);
        bool validarEntero(int, string);
        bool validarEntero(int, string, int);
        bool validarDouble(string);
        bool validarDouble(double, string);
        bool validarDouble(double, string, double);
        string leer(string);
        string leerI(string);
        string leerI(int, string);
        string leerI(int, string, int);
        string leerD(string);
        string leerD(double, string);
        string leerD(double, string, double);
};

#else
class Validaciones;
#endif