#ifndef TIENDA_H
#define TIENDA_H
#include "Producto.h"
#include <string>
#include "Validaciones.h"

class Tienda
{
    private:
        Producto totalProductos[10];

    public:
        Tienda();
        Tienda(Validaciones&);
        ~Tienda();
        Producto& getProducto(int);
        void ingresarProducto(Validaciones&);
        string mostrarProductos();
        string buscarPorNombre(Validaciones&);
        string calcularStock();
        string buscarPorRangoPrecios(Validaciones&);
        void modificarPrecio(Validaciones&);
};

#endif // TIENDA_H
