#ifndef APLICACIÓNUSO_H
#define APLICACIÓNUSO_H
#include "Persona.h"
#include "Validaciones.h"

class AplicaciónUso
{
    private:
        Libro* libros;
        int cantidadL;
        Persona* personas;
        int cantidadP;

    public:
        AplicaciónUso();
        ~AplicaciónUso();
        void crearArregloL(Validaciones&);
        void crearArregloP(Validaciones&);
        void mostrarPersonas(int);
        void mostrarLibros(int);
        void menú();

};

#else
class AplicaciónUso;
#endif