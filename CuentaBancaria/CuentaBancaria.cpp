#include "CuentaBancaria.h"
CuentaBancaria::CuentaBancaria()
{
    saldo=0;
    numConsignaciones=0;
    numRetiros=0;
    tasaAnual=0;
    comMensual=0;
}
CuentaBancaria::CuentaBancaria(double saldo, double tasaAnual)
{
    this->saldo=saldo;
    numConsignaciones=0;
    numRetiros=0;
    this->tasaAnual=tasaAnual;
    comMensual=0;
}
CuentaBancaria::~CuentaBancaria(){}

void CuentaBancaria::consignar(double nuevoSaldo)
{
    saldo+=nuevoSaldo;
    cout<<"Saldo asignado. Nuevo saldo: "<<saldo<<endl;
    numConsignaciones++;
}
void CuentaBancaria::retirar(double saldoaRetirar)
{
    if(saldoaRetirar<=saldo)
    {
        saldo+=-saldoaRetirar;
        cout<<"Transacción realizada. Nuevo saldo: "<<saldo<<endl;
        numRetiros++;
    }
    else
    {
        cout<<"El valor a retirar supera el saldo. Transacción no realizada."<<endl;
    }
}

void CuentaBancaria::calcIntMen(double cambio)
{
    comMensual=cambio*100;
    cout<<"Nuevo interés mensual: "<<cambio<<" %";
}

void CuentaBancaria::extractoMen(double comisiónMensual)
{
    double cambio;
    cambio=comisiónMensual/saldo; 
    saldo+=-comisiónMensual;
    calcIntMen(cambio);
}

string CuentaBancaria::imprimir()
{
    cout<<"Saldo: "<<to_string(saldo)<<" "<<"Número de consignaciones: "<<to_string(numConsignaciones)
        <<" Número de retiros: "<<to_string(numRetiros)<<"\nTasa anual: "<<to_string(tasaAnual)<<" Comisión mensual: "<<to_string(comMensual)<<endl;
}