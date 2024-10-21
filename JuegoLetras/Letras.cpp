#include "Letras.h"
#include <ctime>


Letras::Letras()
{
    tam=0;
    arregloLetras=nullptr;
}
        
Letras::Letras(int tam)
{
    this->tam=tam;
    arregloLetras= new string[tam];
}

Letras::~Letras(){}

void Letras::llenarAleatorio()
{
    srand(time(NULL));
    for(int i=0; i<tam; i++)
    {
        arregloLetras[i]=(rand()%26)+97;
    }
    cout<<"Arreglo llenado con éxito"<<endl;
}

void Letras::reemplazarLetra(int pos, string letra)
{
    if(pos>=0 and pos<tam)
    {
        arregloLetras[pos]=letra;
        cout<<"Letra "<<letra<<" fue reemplazada con éxito en la posición "<<pos<<endl;
    }
    else
    {
        cout<<"La posición "<<pos<<" no es válida."<<endl;
    }
}

string Letras::mostrarDatos()
{
    string salida="\n";
    for(int i=0; i<tam; i++)
    {
        salida+=arregloLetras[i]+"\t";
    }
    return salida;
}

int Letras::mostrarLetra(string letra)
{
    int cant=0;
    for (int i=0; i<tam; i++)
    {
        if(arregloLetras[i]==letra)
        {
            cant++;
        }
    }
    return cant;
}



int* Letras::retornarArreglo(string letra)
{
    int cant=mostrarLetra(letra);
    int *arreglo= new int[cant];
    if(cant=0)
    {
        arreglo=new int[1];
        arreglo[0]=-1;
    }
    else
    {
        int contador=0;
        for(int i=0; i<tam; i++)
        {
            if(arregloLetras[i]==letra)
            {
                arreglo[contador]=i;
                contador++;
            }
        }
    }
    return arreglo;
}

string Letras::retornarLetra(int pos)
{
    if(pos>=0 and pos < tam)
    {
        return arregloLetras[pos];
    }
    else
    {
        return "Posición no válida.\n";
    }
}

void Letras::borrar()
{
    delete [] arregloLetras;
    arregloLetras= nullptr;
}

void Letras::juego()
{
    int cantidadPalabras=0, cuántas=0;
    bool forma;
    string* palabras=nullptr;
    Validaciones val;

    cantidadPalabras=stoi(val.leerI(0,"\nDigite la cantidad de palabras: "));
    cout<<endl;
    palabras=new string[cantidadPalabras];
    for(int i=0; i<cantidadPalabras; i++)
    {
        palabras[i]=val.leer("Digite la palabra número "+to_string(i)+" : ");
        cout<<endl;
    }
    for(int i=0; i<cantidadPalabras; i++)
    {
        cout<<"Palabra No. "<<to_string(i)<<": "<<palabras[i]<<endl;
        forma=mecánicaPrincipal(palabras[i]);
        if(forma==true)
        {
            cout<<"La palabra "<<palabras[i]<<" sí se puede formar"<<endl;
            cuántas++;
        }
        else
        {
            cout<<"La palabra "<<palabras[i]<<" no se puede formar"<<endl;
        }
    }
    cout<<"Se pueden formar "<<to_string(cuántas)<<" palabras"<<endl;
    delete [] palabras;
    palabras=nullptr;
}

bool Letras::mecánicaPrincipal(string palabra)
{
    bool forma=true, está=false;
    int contador=0;
    string arregloAleatorio="", palabraBinaria="", posiciones="";
    for(int i=0; i<palabra.length(); i++)
    {
        palabraBinaria+=' ';
    }

    for (int i=0; i<tam; i++)
    {
        arregloAleatorio+=arregloLetras[i];
    }

    for(int i=0; i<palabra.length(); i++)
    {
        está=false;

        for(int j=0; j<tam;j++)
        {
            if(palabra[i]==arregloAleatorio[j])
            {
                palabraBinaria[contador]='1';
                arregloAleatorio[j]=' ';
                está=true;
                posiciones+=to_string(j);
                break;
            }
        }
        if(está==false)
        {
            palabraBinaria[contador]='0';
            forma=false;
        }
        contador++;
    }

    if(forma==false)
    {
        for(int i=0; i<palabra.length(); i++)
        {
            if(palabraBinaria[i]=='0')
            {
                cout<<"La letra "<<palabra[i]<<" no se encuentra en el arreglo"<<endl;
            }
        }
    }
    else
    {
        for(int i=0; i<palabra.length(); i++)
        {
            cout<<"La letra "<<palabra[i]<<" se encuentra en la posición "<<posiciones[i]<<endl;
        }
    }
    return forma;
}