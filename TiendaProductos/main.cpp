#include "tienda.h"
#include "productos.h"
#include <iostream>
string leer(string mensaje);
int main()
{
    Tienda miTienda=Tienda();
    int opc;
    do
    {
        opc=stoi(leer("***MENU***\n1- Ingresar producto a la tienda\n 2- Mostrar los productos de la tienda\n 3- Buscar los productos de un precio específico\n 4- Actualizar precio de un producto \n5- Salir:\n"));
        switch(opc)
        {
            case 1: miTienda.ingresarProducto(); break;
            case 2: miTienda.mostrarProducto(); break;
            case 3: miTienda.buscarporPrecio(); break;
            case 4: miTienda.actualizarPrecio(); break;
            case 5: cout<<"Adiós!!"<<endl; break;
            default: cout<<"Entrada no válida :("<<endl; break;
        }

    } while (opc!=5);
    
}