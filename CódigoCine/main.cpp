/*
Sebastián Calvo Carvajal
Andrés Gerardo González Rosero
Juan Esteban Arias Saldaña
Profesora: Leoviviana Moreno Torres
Grupo 01
Laboratorio 1*/
#include "Cine.h"
#include "Sala.h"
#include "Película.h"
#include "Programación.h"
#include <iostream>
#include <string>
using namespace std;
string leer(string mensaje);

int main()
{
    Cine miCine=Cine();
    double precioBase;
    int opc=0;
    precioBase=stod(leer("Inserte el precio base de las boletas: "));
    do
    {
        opc=stoi(leer("***MENÚ*****\n1- Ingresar película\n2-Ingresar sala\n3-Consultar películas por género\n4-Consultar horario película\n5-Salir: "));
        switch(opc)
        {
        case 1: miCine.ingresarPelículas(precioBase); break;
        case 2: miCine.ingresarSala(); break;
        case 3: miCine.consultarGénero(); break;
        case 4: miCine.consultarHorario(); break;
        case 5: cout<<"Chao pescado!!!!!!"<<endl; break;
        default: cout<<"Opción no válida. Intente de nuevo"<<endl; break;
        }
    }while (opc!=5);
    
    return 0;
}