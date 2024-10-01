#include "Empresa.h"
#include "Validaciones.h"

Empresa::Empresa(){}
Empresa::~Empresa(){}
        
string Empresa::buscarAbogado(Validaciones& val)
{
    int númeroCaso;
    string abogados[10], lista="";
    númeroCaso=stoi(val.leerI(1,"Ingrese el número del caso:"));
    lista+="Abogados asignados al caso "+to_string(númeroCaso)+":\n";
    for(int i=0; i<10; i++)
    {
        abogados[i]="";
        for(int j=0; j<10; j++)
        {
            if(totalAbogados[i].getCasos(j).getNúmero()==númeroCaso)
            {
                abogados[i]=totalAbogados[i].getNombre();
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        if(abogados[i]!="")
        {
            for(int j=0; j<10;j++)
            {
                if(abogados[i]==totalAbogados[j].getNombre())
                {
                    lista+="Nombre: "+totalAbogados[j].getNombre()+" ID: "+totalAbogados[j].getID()+" Teléfono: "+totalAbogados[j].getTeléfono()+" Email: "+totalAbogados[j].getEmail()+" Especialidad: "+totalAbogados[j].getEspecialidad()+"\n";
                }
            }
        }
    }
    return lista;
     
}
void Empresa::editarAbogados(Validaciones& val)
{
    int índice;
    índice=stoi(val.leerI(1,"Ingrese el índice del abogado a editar: ",10))-1;
    cout<<"Abogado "<<índice+1<<":\n";
    totalAbogados[índice].setID(val.leer("Ingrese el ID: "));
    totalAbogados[índice].setNombre(val.leer("\nIngrese el nombre: "));
    totalAbogados[índice].setTeléfono(val.leer("\nIngrese el teléfono: "));
    totalAbogados[índice].setEmail(val.leer("\nIngrese el email: "));
    totalAbogados[índice].setEspecialidad(val.leer("\nIngrese la especialidad: "));
    for(int j=0; j<10; j++)
    {
        cout<<"Caso "<<j+1<<":\n";
        totalAbogados[índice].getCasos(j).setNúmero(stoi(val.leerI(1,"\nIngrese el número del caso: ")));
        totalAbogados[índice].getCasos(j).setID(val.leer("\nIngrese el ID: "));
        totalAbogados[índice].getCasos(j).setCliente(val.leer("\nIngrese el cliente: "));
    }
}

string Empresa::generarInforme()
{
    string lista="";
    for(int i=0; i<10; i++)
    {
        if(totalAbogados[i].getNombre()!="")
        {
            lista+="Abogado "+to_string(i+1)+":\n";
            lista+="Nombre: "+totalAbogados[i].getNombre()+"\n";
            lista+="ID: "+totalAbogados[i].getID()+"\n";
            lista+="Teléfono: "+totalAbogados[i].getTeléfono()+"\n";
            lista+="Email: "+totalAbogados[i].getEmail()+"\n";
            lista+="Especialidad: "+totalAbogados[i].getEspecialidad()+"\n";
            for(int j=0; j<10; j++)
            {
                lista+="Caso "+to_string(j+1)+":\n";
                lista+="Número: "+to_string(totalAbogados[i].getCasos(j).getNúmero())+"\n";                    lista+="ID: "+totalAbogados[i].getCasos(j).getID()+"\n";
                lista+="Cliente: "+totalAbogados[i].getCasos(j).getCliente()+"\n";
            }
        }
    }
    return lista;
}