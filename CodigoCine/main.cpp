#include "Cine.h"
#include "Sala.h"
#include "Película.h"
#include "Programación.h"
#include <iostream>
#include <string>
#include "Validaciones.h"
using namespace std;

int main()
{
    Cine miCine=Cine();
    Validaciones val=Validaciones();
    double precioBase;
    int opc=0;
    precioBase=stod(val.leerD(0,"Inserte el precio base de las boletas: "));
    do
    {
        opc=stoi(val.leerI("***MENÚ*****\n1- Ingresar película\n2-Ingresar sala\n3-Consultar películas por género\n4-Consultar horario película\n5-Salir: "));
        switch(opc)
        {
        case 1: miCine.ingresarPelículas(precioBase, val); break;
        case 2: miCine.ingresarSala(val); break;
        case 3: miCine.consultarGénero(val); break;
        case 4: miCine.consultarHorario(val); break;
        case 5: cout<<"Hasta luego!!!!!!"<<endl; break;
        default: cout<<"Opción no válida. Intente de nuevo"<<endl; break;
        }
    }while (opc!=5);
    
    return 0;
}
