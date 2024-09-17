#include "tienda.h"
#include <iostream>

Tienda::Tienda(){}
Tienda::~Tienda(){}

string leer(string mensaje)
{
    string aux;
    do
    {
        cout<<mensaje;
        getline(cin, aux);
    } while (aux.empty());
    return aux;
}

void Tienda::ingresarProducto()
{
    int índice, stock;
    double precio;
    string nombre;
    índice=stoi(leer("\nDigite el número del producto a ingresar: "))-1;
    nombre=leer("\nDigite el nombre del producto: ");
    if(listaProductos[índice].getNombre()==nombre)
    {
        cout<<"\nProducto ya existente. Solo es posible cambiar el stock."<<endl;
        stock=stoi(leer("\nDigite el nuevo stock (-1 si no desea cambiarlo): \n"));       
        if(stock>=0)
            listaProductos[índice].setStock(stock);
    }
    else
    {
        precio=stod(leer("\nDigite el precio del producto: "));
        stock=stoi(leer("\nDigite el stock del producto: "));
        listaProductos[índice].setNombre(nombre);
        listaProductos[índice].setPrecio(precio);
        listaProductos[índice].setStock(stock);
        cout<<"Producto "<<listaProductos[índice].getNombre()<<" ingresado con éxito!!"<<endl;
    }

}

void Tienda::mostrarProducto()
{
    for(int i=0; i<10; i++)
    {
        if(listaProductos[i].getNombre()!="")
        {
            cout<<"Producto No. "<<to_string(i+1)<<": "<<listaProductos[i].getNombre()<<"; "
                <<listaProductos[i].getPrecio()<<"; "<<listaProductos[i].getStock()<<"."<<endl;
        }
    }
}

void Tienda::buscarporPrecio()
{
    double precio;
    string lista="";
    precio=stod(leer("\nDigite el precio del producto a buscar: \n"));
    for(int i=0; i<10; i++)
    {
        if(listaProductos[i].getPrecio()==precio)
        {
            lista+=listaProductos[i].getNombre()+"\n";
        }
    }
    if(lista!="")
    {
        cout<<"Los siguientes productos tienen el precio de "<<precio<<endl;
        cout<<lista;
    }
    else 
        cout<<"No hay productos con el precio de "<<precio<<endl;
}

void Tienda::actualizarPrecio()
{
    string nombre;
    bool productoExiste=false;
    double precio;
    nombre=leer("\nDigite el nombre del producto: \n");
    for(int i=0; i<10; i++)
    {
        if(listaProductos[i].getNombre()==nombre)
        {
            productoExiste=true;
            cout<<"\nEl producto vale: "<<listaProductos[i].getPrecio()<<endl;
            precio=stod(leer("\nDigite el nuevo precio del producto: \n"));
            listaProductos[i].setPrecio(precio);
            cout<<"\nPrecio asignado con éxito!!"<<endl;
        }
    }
    if(productoExiste=false)
    {
        cout<<"\nEl producto de nombre "<<nombre<<" no ha sido ingresado aún a la aplicación :("<<endl;
    }
}