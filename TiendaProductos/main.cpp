#include <iostream>
#include "Producto.h"
#include "Tienda.h"


int main()
{
    string leer(string mensaje);
    int opc;
    Tienda miTienda=Tienda();
    do
    {
        opc=stoi(leer("***Menú***\n1. Ingresar producto a la tienda\n"
                      "2. Mostrar los productos de la tienda\n"
                      "3. Buscar producto por nombre\n"
                      "4. Calcular porcentaje de stock\n"
                      "5. Buscar los productos de un rango de precios\n"
                      "6. Modificar el precio de un producto\n"
                      "7. Salir\n"
                      "Digite una opción: "));

        switch(opc)
        {
            case 1: miTienda.ingresarProducto(); break;
            case 2: cout<<miTienda.mostrarProductos()<<endl; break;
            case 3: cout<<miTienda.buscarPorNombre()<<endl; break;
            case 4: cout<<miTienda.calcularStock()<<endl; break;
            case 5: cout<<miTienda.buscarPorRangoPrecios()<<endl; break;
            case 6: miTienda.modificarPrecio(); break;
            case 7: cout<<"Adiós!!!"; break;
            default: cout<<"Opción no válida"<<endl; break;
        }
    }while(opc!=7);
    return 0;
}
