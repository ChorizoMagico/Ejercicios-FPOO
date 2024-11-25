#ifndef APLICACIONUSO_H
#define APLICACIONUSO_H
#include "Persona.h"
#include "Validaciones.h"

class AplicacionUso
{
    private:
        Libro* libros;
        int cantidadL;
        Persona* personas;
        int cantidadP;

    public:
        AplicacionUso();
        ~AplicacionUso();
        void crearArregloL(Validaciones&);
        void crearArregloP(Validaciones&);
        void mostrarPersonas(int);
        void mostrarLibros(int);
        void menú();

};

#else
class AplicacionUso;
#endif