#include "Cine.h"
#include <iostream>

/*
Constructor
*/
Cine::Cine(){}

/*
Destructor
*/
Cine::~Cine(){}

/*
Función para imprimir un mensaje y asignar un valor a una variable al mismo tiempo*/
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
/*
Método para ingresar UNA película de las 20 posibles del objeto Cine, asignándole sus atributos incluida la programación*/
void Cine::ingresarPelículas(double precioBase)
{
    int horaInicio, minInicio, horaFin, minFin, númeroPelícula;
    string nombrePelícula, géneroPelícula;
    númeroPelícula=stoi(leer("Digite el número de la película, siendo 20 el máximo: "));
    nombrePelícula=leer("Digite el nombre de esta película: ");
    do
    {
        géneroPelícula=leer("Digite el género de esta película, siendo los géneros:\n comedia, drama, romance, acción, suspenso, ciencia ficción, terror, fantasía: ");
    }while(géneroPelícula!="comedia" and géneroPelícula!="drama" and géneroPelícula!="romance" and géneroPelícula!="acción" and géneroPelícula!="suspenso" and géneroPelícula!="ciencia ficción" and géneroPelícula!="terror" and géneroPelícula!="fantasía");
    totalPelículas[númeroPelícula-1].setNombre(nombrePelícula);
    totalPelículas[númeroPelícula-1].setGénero(géneroPelícula);
    totalPelículas[númeroPelícula-1].setPrecio(precioBase);
    do
    {
        horaInicio=stoi(leer("Digite la hora de inicio de la película "+totalPelículas[númeroPelícula-1].getNombre()+": "));
        minInicio=stoi(leer("Digite el minuto de inicio de la película "+totalPelículas[númeroPelícula-1].getNombre()+": "));
    }while(horaInicio<7 or (horaInicio==7 and minInicio<30));
    do
    {
        horaFin=stoi(leer("Digite la hora de finalización de la película "+totalPelículas[númeroPelícula-1].getNombre()+": "));
        minFin=stoi(leer("Digite el minuto de finalización de la película "+totalPelículas[númeroPelícula-1].getNombre()+": "));
    } while (horaFin>23 or (horaFin==22 and minFin>30));
    totalPelículas[númeroPelícula-1].setProgramación(horaInicio, minInicio, horaFin, minFin);
    totalPelículas[númeroPelícula-1].getProgramación().setNombre(nombrePelícula);
    cout<<totalPelículas[númeroPelícula-1].getProgramación().getNombre();
    cout<<"Película ingresada!!"<<endl;
}

/*
Método para ingresar una sala de las cinco posibles del objeto cine, asignándole todos sus atributos incluida la programación,
la cual se compara con la programación de cada uno de los 20 objetos Película del objeto Cine para verificar si la programación
es igual*/
void Cine::ingresarSala()
{
    int númeroSala, horaInicio, minInicio, horaFin, minFin;
    string nombreSala, nombreProgramación;
    bool igual=false;

    númeroSala=stoi(leer("Digite el número de la sala, siendo 5 el máximo: "));
    nombreSala=leer("Digite el nombre de la sala: ");
    totalSalas[númeroSala-1].setNombre(nombreSala);
    for(int j=0; j<4; j++)
    {
        cout<<"Programación no. "<<j+1<<endl;
        do
        {
            igual=false;
            horaInicio=stoi(leer("Digite la hora de inicio de la programación: "));
            minInicio=stoi(leer("Digite el minuto de inicio de la programación: "));

            for(int i=0; i<20; i++)
            {
                if(horaInicio==totalPelículas[i].getProgramación().getHoraInicio() and minInicio==totalPelículas[i].getProgramación().getMinInicio())
                {
                    igual=true;
                    break;
                }
            }
            if(igual==false)
                cout<<"La programación ingresada para la sala no coincide con la programación de ninguna de las películas"<<endl;

        }while(horaInicio<7 or (horaInicio==7 and minInicio<30) or igual==false);
        do
        {
            igual=false;
            horaFin=stoi(leer("Digite la hora de finalización de la programación: "));
            minFin=stoi(leer("Digite el minuto de finalización de la programación: "));

            for(int i=0; i<20; i++)
            {
                if(horaFin==totalPelículas[i].getProgramación().getHoraFin() and minFin==totalPelículas[i].getProgramación().getMinFin())
                {
                    igual=true;
                    nombreProgramación=totalPelículas[i].getNombre();
                    break;
                }
            }
            if(igual==false)
                cout<<"La programación ingresada para la sala no coincide con la programación de ninguna de las películas"<<endl;
        } while (horaFin>23 or (horaFin==22 and minFin>30) or igual==false);
        totalSalas[númeroSala-1].getProgramación(j).setNombre(nombreProgramación);
        totalSalas[númeroSala-1].setProgramación(j,horaInicio,minInicio,horaFin,minFin);
    }

    cout<<"Sala ingresada con éxito!!!"<<endl;;   
}
/*
Compara el género ingresado con la variable género de los 20 objetos Película del cine. Si son iguales, busca dentro de las 4
programaciones de las 5 salas alguna programación con un nombre idéntico al de la película; luego, devuelve el número y nombre
de la sala en la que estaba la programación */
void Cine::consultarGénero()
{
    string género, lista="";
    do
    {
        género=leer("Digite el género a consultar, recuerde que los géneros disponibles son:\n comedia, drama, romance, acción, suspenso, ciencia ficción, terror, fantasía: ");
    }while(género!="comedia" and género!="romance" and género!="acción" and género!="suspenso" and género!="ciencia ficción" and género!="terror" and género!="fantasía" and género!="drama");
    for(int i=0; i<20; i++)
    {
        if(género==totalPelículas[i].getGénero())
        {
            lista+=" "+ totalPelículas[i].getNombre();
            for(int j=0; j<5 ;j++)
            {
                for(int k=0; k<4; k++)
                {
                    if(totalPelículas[i].getNombre()==totalSalas[j].getProgramación(k).getNombre())
                    {
                        lista+=" Sala No. " +to_string(j+1)+" de nombre: "+totalSalas[j].getNombre();
                    }
                }
            }
            lista+=" . Empieza a la hora "+to_string(totalPelículas[i].getProgramación().getHoraInicio()) + " minuto: "+ to_string(totalPelículas[i].getProgramación().getMinInicio())+" y termina a la hora: " + to_string(totalPelículas[i].getProgramación().getHoraFin())+ " minuto: "+ to_string(totalPelículas[i].getProgramación().getMinFin())+"\n";
        }
    }
    cout<<lista<<endl;
}
/*
A partir de un string ingresado, lo compara con el nombre de la programación de cada sala, que deberá ser igual a la película.
Luego, devuelve el nombre de la película, el número y nombre de la sala, y su horario*/
void Cine::consultarHorario()
{
    string nombrePelícula, lista;
    nombrePelícula=leer("Digite el nombre de la película a buscar: ");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(nombrePelícula==totalSalas[i].getProgramación(j).getNombre())
            {
                lista+=" La película "+nombrePelícula+" se presenta en la sala No. "+to_string(i+1)+" de nombre: "+totalSalas[i].getNombre()+" a partir de la hora "+to_string(totalSalas[i].getProgramación(j).getHoraInicio())+" y el minuto "+to_string(totalSalas[i].getProgramación(j).getMinInicio())+" hasta la hora "+to_string(totalSalas[i].getProgramación(j).getHoraFin())+" y el minuto "+to_string(totalSalas[i].getProgramación(j).getMinFin())+"\n";
            }
        }
    }
    cout<<lista<<endl;
}