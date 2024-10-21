#ifndef LETRAS_H
#define LETRAS_H
#include <string>
#include <iostream>
#include "Validaciones.h"
using namespace std;

class Letras
{
    private:
        int tam;
        string* arregloLetras;
    
    public:
        Letras();
        Letras(int);
        ~Letras();
        void llenarAleatorio();
        void reemplazarLetra(int, string);
        string mostrarDatos();
        int mostrarLetra(string);
        int* retornarArreglo(string);
        string retornarLetra(int);
        void juego();
        bool mecánicaPrincipal(string);
        void borrar();


};
#else
class Letras;

#endif