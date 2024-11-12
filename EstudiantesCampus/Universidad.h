#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H
#include "Persona.h"
#include "Estudiante.h"
#include "Funcionario.h"
#include "Validaciones.h"

class Universidad
{
    private:
        Persona **comunidadU;
        int posición;
        int tamaño;
    
    public:
        Universidad(Validaciones);
        ~Universidad();
        void ingresarPersona(Validaciones);
        string mostrarPersonas();
        void borrarObjetos();
        void menú(Validaciones);

};

#else
class Universidad;
#endif