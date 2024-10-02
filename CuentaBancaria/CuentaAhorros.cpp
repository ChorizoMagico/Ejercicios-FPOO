#include "CuentaAhorros.h"

CuentaAhorros::CuentaAhorros():CuentaBancaria(){}

CuentaAhorros::CuentaAhorros(double saldo, double tasaAnual):CuentaBancaria(saldo, tasaAnual)
{
    activa=false;
    comisión=false;
}
CuentaAhorros::~CuentaAhorros(){}

void CuentaAhorros::consignar(double nuevoSaldo)
{
    if(activa==true)
    {
        CuentaBancaria::consignar(nuevoSaldo);
    }
    else
    {
        cout<<"Cuenta no activada."<<endl;
    }
}
        
void CuentaAhorros::retirar(double nuevoSaldo)
{
    if(activa==true)
    {
        if(comisión==true)
            CuentaBancaria::retirar(nuevoSaldo+1000);
        else
            CuentaBancaria::retirar(nuevoSaldo);
    }
    else
    {
        cout<<"Cuenta no activada."<<endl;
    }
}

void CuentaAhorros::exMen()
{
    if(numRetiros>4)
    {
        comisión=true;
        cout<<"Comisión aplicada. "<<endl;
    }
    if(saldo!=0)
    {
        activa=true;
        cout<<"Cuenta activada. "<<endl;
    }
}

void CuentaAhorros::imprimir()
{
    cout<<"Saldo: "<<to_string(saldo)<<" Comisión mensual: "<<to_string(comMensual)<<" Transacciones realizadas: "<<to_string(numConsignaciones+numRetiros)<<endl;
}