#include "Validaciones.h"
/*Constructor vacío*/
Validaciones::Validaciones(){}
/*Destructor*/
Validaciones::~Validaciones(){}

/*Método para imprimir un mensaje y asignarle un string a una variable*/
string Validaciones::leer(string mensaje)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty());
    return aux;
}
/*Método para imprimir un mensaje y asignarle un entero validado a una variable*/
string Validaciones::leerI(string mensaje)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarEntero(aux)==false);
    return aux;
}
/*Método para imprimir un mensaje y asignarle un entero validado mayor que un número dado a una variable*/
string Validaciones::leerI(int menor, string mensaje)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarEntero(menor, aux)==false);
    return aux;
}
/*Método para imprimir un mensaje y asignarle un entero validado mayor que un número dado y menor que otro a una variable*/
string Validaciones::leerI(int menor, string mensaje, int mayor)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarEntero(menor, aux, mayor)==false);
    return aux;
}
/*Método para imprimir un mensaje y asignarle un double validado a una variable*/
string Validaciones::leerD(string mensaje)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarDouble(aux)==false);
    return aux;
}
/*Método para imprimir un mensaje y asignarle un double validado mayor que un número dado a una variable*/
string Validaciones::leerD(double menor, string mensaje)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarDouble(menor, aux)==false);
    return aux;
}
/*Método para imprimir un mensaje y asignarle un double validado mayor que un número dado y menor que otro a una variable*/
string Validaciones::leerD(double menor, string mensaje, double mayor)
{
    string aux;
    do{
        cout<<mensaje;
        getline(cin, aux);
    }while(aux.empty() or validarDouble(menor, aux, mayor)==false);
    return aux;
}

/*
Método que devuelve true si la cadena evaluada está compuesta por dígitos*/
bool Validaciones::validarEntero(string númeroS)
{
    int signo=0;
    for(int i=0; i<númeroS.length();i++)
    {
        if(númeroS[i]=='-')
        {
            signo++;
        }
        if(isdigit(númeroS[i])==false and signo!=1)
        {
            cout<<"El dato ingresado "<<númeroS<<" no es un número entero"<<endl;
            return false;
        }
    }
    return true;
}
/*
Método que devuelve true si la primera cadena es menor que la segunda y ambos son enteros*/
bool Validaciones::validarEntero(int menor, string númeroS)
{
    int número;
    if(validarEntero(númeroS)==false)
    {
        return false;
    };

    número=stoi(númeroS);

    if(número>=menor)
    {
        return true;
    }
    cout<<númeroS<<" no es mayor o igual que "<<menor<<endl;
    return false;
}
/*Método que devuelve true si la cadena del medio es mayor que la primera y menor que la tercera, siendo las tres enteros*/
bool Validaciones::validarEntero(int menor, string númeroS, int mayor)
{
    int número;
    if(validarEntero(númeroS)==false)
    {
        return false;
    };

    número=stoi(númeroS);

    if(número>=menor and número<=mayor)
    {
        return true;
    }
    cout<<númeroS<<" no está entre "<<menor<<" y "<<mayor<<endl;
    return false;
    
}
/*Método que devuelve true si la cadena evaluada está compuesta por dígitos y tiene solo un punto, es decir, es un número real*/
bool Validaciones::validarDouble(string númeroS)
{
    int punto=0, signo=0;
    for(int i=0; i<númeroS.length();i++)
    {
        if(númeroS[i]=='.')
        {
            punto++;
        }
        if(númeroS[i]=='-')
        {
            signo++;
        }
        if(isdigit(númeroS[i])==false and punto!=1 and signo!=1)
        {
            cout<<"El dato ingresado "<<númeroS<<" no es un número double"<<endl;
            return false;
        }
    }
    return true;
}
/*Método que devuelve true si la primera cadena es menor que la segunda y ambas son números reales*/
bool Validaciones::validarDouble(double menor, string númeroS)
{
    double número;
    if(validarDouble(númeroS)==false)
    {
        return false;
    };

    número=stod(númeroS);
    
    if(número>=menor)
    {
        return true;
    }
    cout<<númeroS<<" no es mayor o igual que "<<menor<<endl;
}
/*Método que devuelve true si la cadena del medio es mayor que la primera y menor que la tercera, siendo las tres reales*/
bool Validaciones::validarDouble(double menor, string númeroS, double mayor)
{
    double número;
    if(validarDouble(númeroS)==false)
    {
        return false;
    }
    número=stod(númeroS);
    if(número>=menor and número<=mayor)
    {
        return true;
    }
    cout<<"El número "<<númeroS<<" no está entre "<<menor<<" y "<<mayor<<endl;
    return false;
}

