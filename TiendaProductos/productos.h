#ifndef PRODUCTOS_H 
#define PRODUCTOS_H
#include <string>
using namespace std;

class Productos
{
    private:
        string nombre;
        double precio;
        int stock;

    public:
        Productos();
        ~Productos();
        void setNombre(string);
        void setPrecio(double);
        void setStock(int);
        string getNombre();
        double getPrecio();
        int getStock();

};


#else
class Productos;
#endif