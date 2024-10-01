#ifndef EMPRESA_H
#define EMPRESA_H
#include <string>
#include "Validaciones.h"
using namespace std;
#include "Abogado.h"

class Empresa
{
    private:
        string nombre;
        string NIT;
        Abogado totalAbogados[10];
    public:
        Empresa();
        ~Empresa();
        string buscarAbogado(Validaciones& val);
        void editarAbogados(Validaciones& val);
        string generarInforme();
};



#else
class Empresa;
#endif
