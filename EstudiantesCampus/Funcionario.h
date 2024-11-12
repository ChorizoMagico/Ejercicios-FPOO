#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Persona.h"

class Funcionario: public Persona
{
    private:
        double salario;
        string cargo;

    public:
        Funcionario();
        Funcionario(string, int, double, string);
        ~Funcionario();
        double getSalario();
        string getCargo();
        string getInfo();

};

#else
class Funcionario;
#endif

