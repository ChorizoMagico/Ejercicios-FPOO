#include "CuentaCorriente.h"

CuentaCorriente::CuentaCorriente(){}

CuentaCorriente::CuentaCorriente(double saldo, double tasaAnual):CuentaBancaria(saldo, tasaAnual)
{
    sobregiro=0;
}

CuentaCorriente::~CuentaCorriente(){}

void CuentaCorriente::retirar(double nuevoSaldo)
{
    if(nuevoSaldo>saldo)
    {
        sobregiro+=saldo-nuevoSaldo;
    }
    saldo+=-nuevoSaldo;
    cout<<"\nSaldo asignado. Sobregiro de: "<<sobregiro<<endl;
}

void CuentaCorriente::consignar(double nuevoSaldo)
{
    if(sobregiro!=0)
    {
        if(nuevoSaldo>=sobregiro)
        {
            CuentaBancaria::consignar(nuevoSaldo-sobregiro);
            sobregiro=0;
            cout<<"Sobregiro pagado. "<<endl;
        }
        else
        {
            {
                sobregiro+=-nuevoSaldo;
                cout<<"La consignación se redirigió para pagar el sobregiro. Sobregiro actual: "<<to_string(sobregiro)<<endl;
            }
        }
    }
    else
    {
        CuentaBancaria::consignar(nuevoSaldo);
    }
}
    
void CuentaCorriente::extractoMen(double comisiónMensual)
{
    CuentaBancaria::extractoMen(comisiónMensual);
}

void CuentaCorriente::imprimir()
{
    cout<<"Saldo: "<<to_string(saldo)<<" Comisión mensual: "<<to_string(comMensual)
        <<" Número de transacciones realizadas: "<<to_string(numConsignaciones+numRetiros)<<" Sobregiro: "<<to_string(sobregiro)<<endl;
}