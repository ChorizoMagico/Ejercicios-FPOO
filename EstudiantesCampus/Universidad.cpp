#include "Universidad.h"


Universidad::Universidad(Validaciones val)
{
    int n;
    tamaño=n;
    posición=0;
    n=stoi(val.leerI("¿Cuántas personas se encuentran en la universidad? :  "));
    
    comunidadU= new Persona*[n];
    
    for(int i=0; i<n; i++)
    {
        comunidadU[i]=nullptr;
    }

}


Universidad::~Universidad(){}

void Universidad::ingresarPersona(Validaciones val)
{
    string nombre, cargo, código, carrera;
    double salario;
    int opc, edad;

    if(posición>=tamaño)
    {
        cout<<"Universidad llena. Borre los espacios ya asignados."<<endl;
        return;
    }

    do
    {
        opc=stoi(val.leerI("\n¿Qué tipo de persona desea agregar? \n1. Persona en general\n2. Estudiante\n3.Funcionario\n:  "));
        if(opc!=1 and opc!=2 and opc!=3)
        {
            cout<<"\nOpción inválida"<<endl;
        }
    } while (opc!=1 and opc!=2 and opc!=3);
    
    nombre=val.leer("\n¿Cómo se llama la persona?\n: ");
    edad=stoi(val.leerI(0,"\n¿Cuál es la edad de la persona?\n: "));

    switch(opc)
    {
        case 1: 
                comunidadU[posición]= new Persona(nombre, edad);
                cout<<"\nPersona creada con éxito en la posición "<<to_string(posición+1)<<" de "<<to_string(tamaño)<<endl;
                posición++;
                break;
        case 2:
                código=val.leer("\n¿Cuál es el código del estudiante?\n: ");
                carrera=val.leer("\n¿Cuál es la carrera del estudiante?\n: ");
                comunidadU[posición]= new Estudiante(nombre, edad, código, carrera);
                cout<<"\nEstudiante creado con éxito en la posición "<<to_string(posición+1)<<" de "<<to_string(tamaño)<<endl;
                posición++;
                break;
        case 3:
                salario=stod(val.leerD("\n¿Cuál es el salario del funcionario?\n: "));
                cargo=val.leer("\n¿Cuál es el cargo del funcionario?\n: ");
                comunidadU[posición]= new Funcionario(nombre, edad, salario, cargo);
                cout<<"\nFuncionario creado con éxito en la posición "<<to_string(posición+1)<<" de "<<to_string(tamaño)<<endl;
                posición++;
                break;
        default: cout<<"Esto no debería suceder."<<endl; break;
    }

}
    
string Universidad::mostrarPersonas()
{
    string salida="";
    for(int i=0; i<posición; i++)
    {
        salida+="Persona N. "+to_string(i+1)+"\n"+comunidadU[i]->getInfo();
    }
    return salida;
}

void Universidad::borrarObjetos()
{
    if(comunidadU!=nullptr)
    {
        for(int i=0; i<tamaño; i++)
        {
            delete comunidadU[i];
            comunidadU[i]=nullptr;
        }
        delete [] comunidadU;
        comunidadU=nullptr;
    }
}

void Universidad::menú(Validaciones val)
{
    int opc=0;

    do
    {
        cout<<"***MENÚ***\nPosición actual: "<<to_string(posición+1)<<endl;
        opc=stoi(val.leerI("1. Ingresar persona\n2. Mostrar personas\n3. Borrar objetos\n4. Salir\n: "));
        switch(opc)
        {
            case 1: ingresarPersona(val); break;
            case 2: mostrarPersonas(); break;
            case 3: borrarObjetos(); break;
            case 4: borrarObjetos(); cout<<"Adiós!!!"<<endl; break;
            default: cout<<"Opción inválida. Intente otra vez"<<endl;
        }
    } while (opc!=4);
    
}
