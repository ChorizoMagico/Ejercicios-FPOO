#include "Tienda.h"
#include <iostream>
#include "Validaciones.h"


Tienda::Tienda(){}

Tienda::~Tienda(){}

Producto& Tienda::getProducto(int índice)
{
    return totalProductos[índice];
}

void Tienda::ingresarProducto(Validaciones& val)
{
    string nombre, nombreM="";
    double precio;
    int stock, índice, marca;
    bool repetido=false;
    índice=stoi(val.leerI(1,"\nDigite (del 1 al 10) el número del producto a ingresar: ",10))-1;
    nombre=val.leer("\nDigite el nombre del producto: ");
    precio=stod(val.leerD(0,"\nDigite el precio del producto: "));
    stock=stoi(val.leerI(0,"\nDigite el stock del producto: "));
    for(int i=0; i<nombre.length();i++)
    {
        nombreM+=tolower(nombre[i]);
    }
    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getNombre()==nombreM)
        {
            repetido=true;
            marca=i;
        }
    }
    if(repetido==true)
    {
        stock=stoi(val.leerI(0,"\nProducto ya existente. Solo puede actualizar su stock: "));
        getProducto(marca).setStock(stock);
    }
    else
    {
        getProducto(índice).setNombre(nombreM);
        getProducto(índice).setPrecio(precio);
        getProducto(índice).setStock(stock);
        cout<<"\nProducto creado!!!"<<endl;
    }
}
string Tienda::mostrarProductos()
{
    string lista="";
    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getNombre()!="")
        {
            lista+=getProducto(i).getNombre()+" "+to_string(getProducto(i).getPrecio())+" "+to_string(getProducto(i).getStock())+"\n";
        }
    }
    lista+="Productos mostrados con éxito!!!!";
    return lista;
}

string Tienda::buscarPorNombre(Validaciones& val)
{
    string nombre, nombreM="", lista="";
    nombre=val.leer("\nDigite el nombre del producto a buscar: ");
    for(int i=0; i<nombre.length(); i++)
    {
        nombreM+=tolower(nombre[i]);
    }

    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getNombre().find(nombreM)!=string::npos)
        {
            lista+=getProducto(i).getNombre()+" "+to_string(getProducto(i).getPrecio())+" "+to_string(getProducto(i).getStock())+"\n";
        }
    }
    lista+="Productos equivalentes mostrados!!\n";
    return lista;
}
string Tienda::calcularStock()
{
    int totalStock=0;
    string lista="";
    for(int i=0; i<10; i++)
    {
        totalStock+=getProducto(i).getStock();
    }
    lista+="Total de productos en stock: "+to_string(totalStock)+"\n";
    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getNombre()!="")
            lista+=getProducto(i).getNombre()+" "+to_string(getProducto(i).getStock())+" "+to_string((getProducto(i).getStock()/totalStock)*100)+"%"+"\n";
    }
    return lista;
}
string Tienda::buscarPorRangoPrecios(Validaciones& val)
{
    double rangoInicio, rangoFinal;
    rangoInicio=stod(val.leerD(0,"\nDigite el inicio del rango de precios: "));
    rangoFinal=stod(val.leerD(rangoInicio,"\nDigite el final del rango de precios: "));
    string lista="\n";
    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getPrecio()<=rangoFinal and getProducto(i).getPrecio()>=rangoInicio)
        {
            lista+=getProducto(i).getNombre()+"\n";
        }
    }
    return lista;
}
void Tienda::modificarPrecio(Validaciones& val)
{
    string nombre, nombreM="";
    double precio;
    nombre=val.leer("Digite el nombre del producto: ");
    for(int i=0; i<nombre.length();i++)
    {
        nombreM+=tolower(nombre[i]);
    }
    for(int i=0; i<10; i++)
    {
        if(getProducto(i).getNombre()==nombreM)
        {
            cout<<"El precio actual del producto "<<getProducto(i).getNombre()<<" es: "<<getProducto(i).getPrecio()<<endl;
            precio=stod(val.leerD(0,"Digite el nuevo precio: "));
            getProducto(i).setPrecio(precio);
            cout<<"\nPrecio ingresado con éxito!!"<<endl;
            break;
        }

    }
}
