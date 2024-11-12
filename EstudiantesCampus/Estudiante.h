#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Persona.h"

class Estudiante: public Persona
{
    private:
        string código;
        string carrera;

    public:
        Estudiante();
        Estudiante(string, int, string, string);
        ~Estudiante();
        string getCódigo();
        string getCarrera();
        string getInfo();
};

#else
class Estudiante;
#endif

