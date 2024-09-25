#ifndef TIENDA_H
#define TIENDA_H
#include "Producto.h"
#include <string>

class Tienda
{
    private:
        Producto totalProductos[10];

    public:
        Tienda();
        ~Tienda();
        Producto& getProducto(int);
        void ingresarProducto();
        string mostrarProductos();
        string buscarPorNombre();
        string calcularStock();
        string buscarPorRangoPrecios();
        void modificarPrecio();
};

#endif // TIENDA_H
