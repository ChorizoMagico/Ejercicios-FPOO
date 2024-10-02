#ifndef CUENTAAHORROS_H
#define CUENTAAHORROS_H
#include "CuentaBancaria.h"

class CuentaAhorros: public CuentaBancaria
{
    private:
        bool activa;
        bool comisión;
    
    public:
        CuentaAhorros();
        CuentaAhorros(double, double);
        ~CuentaAhorros();
        void consignar(double);
        void retirar(double);
        void exMen();
        void imprimir();
};


#else
class CuentaAhorros;

#endif