#include <iostream>
#include "Producto.h"
#include "Tienda.h"
#include "Validaciones.h"

int main()
{
    Validaciones val=Validaciones();
    int opc;
    Tienda miTienda=Tienda();
    do
    {
        opc=stoi(val.leerI("***Menú***\n1. Ingresar producto a la tienda\n"
                      "2. Mostrar los productos de la tienda\n"
                      "3. Buscar producto por nombre\n"
                      "4. Calcular porcentaje de stock\n"
                      "5. Buscar los productos de un rango de precios\n"
                      "6. Modificar el precio de un producto\n"
                      "7. Salir\n"
                      "Digite una opción: "));

        switch(opc)
        {
            case 1: miTienda.ingresarProducto(val); break;
            case 2: cout<<miTienda.mostrarProductos()<<endl; break;
            case 3: cout<<miTienda.buscarPorNombre(val)<<endl; break;
            case 4: cout<<miTienda.calcularStock()<<endl; break;
            case 5: cout<<miTienda.buscarPorRangoPrecios(val)<<endl; break;
            case 6: miTienda.modificarPrecio(val); break;
            case 7: cout<<"Adiós!!!"; break;
            default: cout<<"Opción no válida"<<endl; break;
        }
    }while(opc!=7);
    return 0;
}
