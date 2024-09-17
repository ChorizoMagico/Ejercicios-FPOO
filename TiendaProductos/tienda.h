#ifndef TIENDA_H
#define TIENDA_H
#include "productos.h"
class Tienda
{
    private:
        Productos listaProductos[10];
    
    public:
        Tienda();
        ~Tienda();
        void ingresarProducto();
        void mostrarProducto();
        void buscarporPrecio();
        void actualizarPrecio();
        Productos& getProducto(int);
};

#else
class Tienda;
#endif