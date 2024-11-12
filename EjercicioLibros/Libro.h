#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include <string>
using namespace std;


class Libro
{
    private:
        string nombre;
        int numPáginas;
        int págRotas;
    public:
        Libro();
        Libro(string, int);
        ~Libro();
        string romper(int);
        string getNombre();
        int getPáginas();
        int getPáginasRotas();
        void setNombre(string);
        void setPáginas(int);

};
#else
class Libro;
#endif