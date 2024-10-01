#ifndef ABOGADO_H
#define ABOGADO_H
#include <string>
#include "Casos.h"
using namespace std;

class Abogado
{
    private:
        string id;
        string nombre;
        string teléfono;
        string email;
        string especialidad;
        Casos totalCasos[10];
    public:
        Abogado();
        ~Abogado();
        void setID(string);
        void setNombre(string);
        void setTeléfono(string);
        void setEmail(string);
        void setEspecialidad(string);
        string getNombre();
        string getID();
        string getTeléfono();
        string getEmail();
        string getEspecialidad();
        Casos& getCasos(int);

};


#else
class Abogado;
#endif 