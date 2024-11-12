#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <iostream>
using namespace std;


class Persona
{
    protected:
        string nombre;
        int edad;

    public:
        Persona();
        Persona(string, int);
        virtual ~Persona();
        string getNombre();
        int getEdad();
        virtual string getInfo();

};

#else
class Persona;
#endif