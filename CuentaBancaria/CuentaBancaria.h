#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H
#include <string>
#include <iostream>
using namespace std;


class CuentaBancaria
{
    protected:
        double saldo;
        int numConsignaciones;
        int numRetiros;
        double tasaAnual;
        double comMensual;
    
    public:
        CuentaBancaria();
        CuentaBancaria(double, double);
        ~CuentaBancaria();
        void consignar(double);
        void retirar(double);
        void calcIntMen(double);
        void extractoMen(double);
        string imprimir();

};
#else
class CuentaBancaria;

#endif