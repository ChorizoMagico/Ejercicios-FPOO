#include "Abogado.h"
#include "Validaciones.h"
#include "Casos.h"
#include "Empresa.h"

int main()
{
    int opc;
    Empresa miEmpresa=Empresa();
    Validaciones val=Validaciones();
    do
    {
        opc=stoi(val.leerI("***MENÚ****\n1. Buscar abogado\n2. Editar abogados\n3. Generar informe\n4. Salir\nIngrese una opción: "));
        switch(opc)
        {
            case 1:cout<<miEmpresa.buscarAbogado(val)<<endl;break;
            case 2:miEmpresa.editarAbogados(val);break;
            case 3:cout<<miEmpresa.generarInforme()<<endl;break;
            case 4:cout<<"Adiós"<<endl;break;
            default:cout<<"Opción inválida"<<endl;break;
        }
    } while (opc!=4);
    return 0;
}