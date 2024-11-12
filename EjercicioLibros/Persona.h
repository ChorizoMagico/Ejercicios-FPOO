#ifndef PERSONA_H
#define PERSONA_H
#include "Libro.h"

class Persona
{
    private:
        string nombre;
        Libro* unLibro;

    public:
        Persona();
        Persona(string);
        ~Persona();
        Libro* prestar(Libro*);
        string recibe(Libro*);
        string rompePáginas(int);
        string getNombre();
        Libro* getLibro();
        void setNombre(string);
        void setLibro(Libro*);
};


#else
class Persona;
#endif