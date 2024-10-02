#include "CuentaBancaria.h"
#include "CuentaAhorros.h"
#include "CuentaCorriente.h"
#include "Validaciones.h"

int main()
{
    int opc, cuenta;
    double saldo1,saldo2, saldo3, tasaAnual, comMen;
    Validaciones val=Validaciones();
    saldo1=stod(val.leerD(0,"Digite el saldo de la cuenta de ahorros: "));
    saldo2=stod(val.leerD(0, "Digite el saldo de la cuenta corriente: "));
    saldo3=stod(val.leerD(0,"Digite el saldo de la cuenta bancaria básica: "));
    comMen=stod(val.leerD(0,"Digite la comisión mensual: "));
    tasaAnual=stod(val.leerD(0, "Digite la tasa anual: "));
    CuentaAhorros cuentaAhorros=CuentaAhorros(saldo1, tasaAnual);
    CuentaCorriente cuentaCorriente=CuentaCorriente(saldo1, tasaAnual);
    CuentaBancaria cuentaBancaria=CuentaBancaria(saldo3, tasaAnual);
    do
    {
        cuenta=stoi(val.leerI("Digite la cuenta a manejar\n1. De ahorros\n2. Corriente\n3. Bancaria normal\n4. Salir: "));
        switch(cuenta)
        {
            case 1:
                do
                {
                    opc=stoi(val.leerI("\nMENÚ\n1. Consignar\n2. Retirar\n3. Generar extract mensual\n4. Imprimir\n5. Salir:  "));
                    switch(opc)
                    {
                        case 1:
                            saldo1=stod(val.leerD(0, "Digite el saldo a consignar: "));
                            cuentaAhorros.consignar(saldo1);
                            break;
                        case 2:
                            saldo1=stod(val.leerD(0, "Digite el saldo a retirar: "));
                            cuentaAhorros.retirar(saldo1);
                            break;
                        case 3:
                            cuentaAhorros.exMen(); break;
                        case 4:
                            cuentaAhorros.imprimir(); break;
                        case 5:
                            cout<<"Adiós!! . Regresando al menú principal..."<<endl;
                            break;
                        default:
                            cout<<"Opción no válida.."<<endl; break;
                    }
                } while (opc!=5);
                break;
            case 2:
                do
                {
                    opc=stoi(val.leerI("\nMENÚ\n1. Retirar\n2. Consignar\n3. Generar extract mensual\n4. Imprimir\n5. Salir:  "));
                    switch(opc)
                    {
                        case 1:
                            saldo1=stod(val.leerD(0, "Digite el saldo a consignar: "));
                            cuentaCorriente.consignar(saldo1); 
                            break;
                        case 2:
                            saldo1=stod(val.leerD(0, "Digite el saldo a retirar: "));
                            cuentaCorriente.retirar(saldo1);
                            break;
                        case 3:
                            cuentaCorriente.extractoMen(comMen);
                            break;
                        case 4:
                            cuentaCorriente.imprimir(); break;
                        case 5:
                            cout<<"Adiós!! . Regresando al menú principal..."<<endl;
                            break;
                        default:
                            cout<<"Opción no válida.."<<endl; break;
                    }
                } while (opc!=5);
                break;
            case 3:
                do
                {
                    opc=stoi(val.leerI("\nMENÚ\n1. Consignar\n2. Retirar\n3. Generar extract mensual\n4. Imprimir\n5. Salir:  "));
                    switch(opc)
                    {
                        case 1:
                            saldo1=stod(val.leerD(0, "Digite el saldo a consignar: "));
                            cuentaBancaria.consignar(saldo1);
                            break;
                        case 2:
                            saldo1=stod(val.leerD(0, "Digite el saldo a retirar: "));
                            cuentaBancaria.retirar(saldo1);
                            break;
                        case 3:
                            cuentaBancaria.extractoMen(comMen);
                            break;
                        case 4:
                            cuentaBancaria.imprimir();
                            break;
                        case 5:
                            cout<<"Adiós!! . Regresando al menú principal..."<<endl;
                            break;
                        default:
                            cout<<"Opción no válida.."<<endl;
                            break;
                    }
                } while (opc!=5);
                break;
            case 4: cout<<"Adiós!!"<<endl; break;
            default: cout<<"Cuenta inexistente"<<endl; break;
        }
    }while(cuenta!=4);
    return 0;
}