#include "Cine.h"
#include "Validaciones.h"

/*
Constructor
*/
Cine::Cine(){}

/*
Destructor
*/
Cine::~Cine(){}

/*
Método para ingresar UNA película de las 20 posibles del objeto Cine, asignándole sus atributos incluida la duración*/
void Cine::ingresarPelículas(double precioBase, Validaciones& val)
{
    int duraciónH, duraciónM, númeroPelícula, opc;
    string nombrePelícula, géneroPelícula;
    númeroPelícula=stoi(val.leerI(1,"Digite el número de la película, siendo 20 el máximo: ",20));
    nombrePelícula=val.leer("Digite el nombre de esta película: ");
    do
    {
        opc=stoi(val.leerI("Digite el género de esta película, siendo los géneros:\n 1-comedia, 2-drama, 3-romance, 4-acción, 5-suspenso, 6-ciencia ficción, 7-terror, 8-fantasía: "));
        switch(opc)
        {
            case 1: géneroPelícula="Comedia"; break;
            case 2: géneroPelícula="Drama"; break;
            case 3: géneroPelícula="Romance"; break;
            case 4: géneroPelícula="Acción"; break;
            case 5: géneroPelícula="Suspenso"; break;
            case 6: géneroPelícula="Ciencia ficción"; break;
            case 7: géneroPelícula="Terror"; break;
            case 8: géneroPelícula="Fantasía"; break;
            default: cout<<"Género ingresado no válido. Intente de nuevo"<<endl; break;
        }
    }while(opc<1 or opc>8);
    totalPelículas[númeroPelícula-1].setNombre(nombrePelícula);
    totalPelículas[númeroPelícula-1].setGénero(géneroPelícula);
    totalPelículas[númeroPelícula-1].setPrecio(precioBase);
    do
    {
        duraciónH=stoi(val.leerI(0,"Digite la duración en horas de la película "+totalPelículas[númeroPelícula-1].getNombre()+": "));
        duraciónM=stoi(val.leerI(0,"Digite la duración en minutos de la película "+totalPelículas[númeroPelícula-1].getNombre()+": ",59));
    }while(duraciónH==0 and duraciónM==0);
    totalPelículas[númeroPelícula-1].setDuraciónH(duraciónH);
    totalPelículas[númeroPelícula-1].setDuraciónM(duraciónM);
    cout<<"Película ingresada!!"<<endl;
}

/*
Método para ingresar una sala de las cinco posibles del objeto cine, asignándole todos sus atributos incluidas sus 4 programaciones,
las cuales se comparan para verificar que no se crucen */
void Cine::ingresarSala(Validaciones& val)
{
    int númeroSala, horaInicio, minInicio, horaFin, minFin, númeroPelícula;
    double horarioInicioActual, horarioFinalActual, horarioFinal, horarioInicio;
    bool cruza = false;
    string nombreSala, nombreProgramación;
    númeroSala = stoi(val.leerI(1, "Digite el número de la sala, siendo 5 el máximo: ", 5));
    nombreSala = val.leer("Digite el nombre de la sala: ");
    totalSalas[númeroSala-1].setNombre(nombreSala);
    for (int i = 0; i < 4; i++)
    {
        cout << "Programación no. " << i + 1 << endl;
        do
        {
            do
            {
                horaInicio = stoi(val.leerI(7, "Digite la hora de inicio de la programación: ", 22));
                minInicio = stoi(val.leerI(0, "Digite el minuto de inicio de la programación: ", 59));
            } while ((horaInicio == 7 && minInicio <= 30) || (horaInicio == 22 && minInicio >= 30));
            do
            {
                cout << "Las películas disponibles son: " << endl;
                for (int j = 0; j < 20; j++)
                {
                    if (totalPelículas[j].getNombre() != "")
                    {
                        cout << j + 1 << ". " << totalPelículas[j].getNombre() << endl;
                    }
                }
                do
                {
                    númeroPelícula = stoi(val.leerI(1, "Digite el número de la película a programar, siendo 20 el máximo: ", 20));
                } while (totalPelículas[númeroPelícula-1].getNombre() == "");
                nombreProgramación = totalPelículas[númeroPelícula-1].getNombre();
                horarioFinal = horaInicio + minInicio / 60.0 + totalPelículas[númeroPelícula-1].getDuraciónH() + totalPelículas[númeroPelícula-1].getDuraciónM() / 60.0;
            } while (horarioFinal > 22.5);
            horarioInicioActual = horaInicio + minInicio / 60.0;
            horarioFinalActual = horaFin+minFin/60.0;
            cruza = false; 
            for (int k = 0; k < 4; k++)
            {
                if (k != i)
                {
                    horarioFinal = totalSalas[númeroSala-1].getProgramación(k).getHoraFin() + totalSalas[númeroSala-1].getProgramación(k).getMinFin() / 60.0;
                    horarioInicio = totalSalas[númeroSala-1].getProgramación(k).getHoraInicio() + totalSalas[númeroSala-1].getProgramación(k).getMinInicio() / 60.0;
                    if ((horarioFinal > horarioInicioActual and horarioInicio < horarioInicioActual) or (horarioFinalActual<horarioFinal and horarioFinalActual>horarioInicio) )
                    {
                        cruza = true;
                        break;
                    }
                }
            }
        } while (cruza == true);
        horaFin = horaInicio + totalPelículas[númeroPelícula-1].getDuraciónH();
        minFin = minInicio + totalPelículas[númeroPelícula-1].getDuraciónM();
        totalSalas[númeroSala-1].getProgramación(i).setNombre(nombreProgramación);
        totalSalas[númeroSala-1].setProgramación(i, horaInicio, minInicio, horaFin, minFin);
        cout << "Sala ingresada con éxito!!!" << endl;
    }
}
/*
Compara el género ingresado con la variable género de los 20 objetos Película del cine. Devuelve un arreglo[20] con las películas que compren la comparación
Luego, las buscas dentro de las 4 programaciones de las cinco salas. Si las encuentra, las devuelve. */

void Cine::consultarGénero(Validaciones& val)
{
    string género, películas[20], lista="";
    int opc;
    do
    {
        opc=stoi(val.leerI("Digite el género a consultar, siendo los géneros:\n 1-comedia, 2-drama, 3-romance, 4-acción, 5-suspenso, 6-ciencia ficción, 7-terror, 8-fantasía: "));
        switch(opc)
        {
            case 1: género="Comedia"; break;
            case 2: género="Drama"; break;
            case 3: género="Romance"; break;
            case 4: género="Acción"; break;
            case 5: género="Suspenso"; break;
            case 6: género="Ciencia ficción"; break;
            case 7: género="Terror"; break;
            case 8: género="Fantasía"; break;
            default: cout<<"Género ingresado no válido. Intente de nuevo"<<endl; break;
        }
    } while(opc<1 or opc>8);

    for(int i=0; i<20; i++)
    {
        if(género==totalPelículas[i].getGénero())
        {
            películas[i]=totalPelículas[i].getNombre();
        }
    }
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<20; k++)
            {
                if(películas[k]==totalSalas[i].getProgramación(j).getNombre())
                {
                    lista+="La película "+películas[k]+" se presenta en la sala No. "+to_string(i+1)+" de nombre: "+totalSalas[i].getNombre()+"\n"+
                    "desde las "+to_string(totalSalas[i].getProgramación(j).getHoraInicio())+":"+to_string(totalSalas[i].getProgramación(j).getMinInicio())+" hasta las "+to_string(totalSalas[i].getProgramación(j).getHoraFin())+":"+to_string(totalSalas[i].getProgramación(j).getMinFin())+"\n";
                }
            }
        }
    }
    cout<<lista<<endl;
}
/*
A partir de un string ingresado, lo compara con el nombre de la programación de cada sala, que deberá ser igual a la película.
Luego, devuelve el nombre de la película, el número y nombre de la sala, y su horario*/
void Cine::consultarHorario(Validaciones& val)
{
    string nombrePelícula, lista;
    nombrePelícula=val.leer("Digite el nombre de la película a buscar: ");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(nombrePelícula==totalSalas[i].getProgramación(j).getNombre())
            {
                lista+=" La película "+nombrePelícula+" se presenta en la sala No. "+to_string(i+1)+" de nombre: "+totalSalas[i].getNombre()+" a partir de las "+to_string(totalSalas[i].getProgramación(j).getHoraInicio())+":"+to_string(totalSalas[i].getProgramación(j).getMinInicio())+" hasta las "+to_string(totalSalas[i].getProgramación(j).getHoraFin())+":"+to_string(totalSalas[i].getProgramación(j).getMinFin())+"\n";
            }
        }
    }
    cout<<lista<<endl;
}