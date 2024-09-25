#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;

class Producto
{
    private:
        string nombre;
        double precio;
        int stock;


    public:
        Producto();
        ~Producto();
        void setNombre(string);
        void setPrecio(double);
        void setStock(int);
        string getNombre();
        double getPrecio();
        int getStock();
};
#else
class Ṕroducto;

#endif // PRODUCTO_H
