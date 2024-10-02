#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H
#include "CuentaBancaria.h"

class CuentaCorriente: public CuentaBancaria
{
    private:
        double sobregiro;
    
    public:
        CuentaCorriente();
        CuentaCorriente(double, double);
        ~CuentaCorriente();
        void retirar(double);
        void consignar(double);
        void extractoMen(double);
        void imprimir();

};

#else
class CuentaCorriente;
#endif

