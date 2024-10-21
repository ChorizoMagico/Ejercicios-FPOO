#include "UsaLetras.h"
#include "Letras.h"


UsaLetras::UsaLetras(){}
UsaLetras::~UsaLetras(){}

void UsaLetras::menú()
{
    int tam, opc, pos, *arregloPosiciones;
    string letra;
    Validaciones val;
    tam=stoi(val.leerI(0,"Digite el tamaño del arreglo de letras: "));
    Letras letras=Letras(tam);
    do
    {
        cout<<"\n***MENÚ***\n1. Llenar de letras aleatorias\n2. Reemplazar una letra de una posición específica\n3. Mostrar todos los datos del arreglo"
            <<"\n4. Mostrar la cantidad de veces que aparece una letra específica en el arreglo\n5. Encontrar la posición de una letra en el arreglo\n"
            <<"6. Retornar una letra de una posición en específico\n7. Juego: ¿Cuáles palabras se pueden formar con letras aleatorias? \n8.Salir\n";
        opc=stoi(val.leerI("Digite una opción: "));
        switch(opc)
        {
            case 1: letras.llenarAleatorio(); break;

            case 2: pos=stoi(val.leerI("Digite la posición a reemplazar: "));
                    letra=val.leer("Digite la letra que quiere agregar: ");
                    letras.reemplazarLetra(pos, letra); break;

            case 3: cout<<letras.mostrarDatos()<<endl; break;

            case 4: letra=val.leer("Digite la letra que quiere contar: ");
                    cout<<"La letra "<<letra<<" aparece "<<to_string(letras.mostrarLetra(letra))<<" veces en el arreglo"<<endl; break;

            case 5: letra=val.leer("Digite la letra que quiere buscar: ");
                    pos=letras.mostrarLetra(letra);
                    arregloPosiciones=letras.retornarArreglo(letra); 
                    if(pos==0)
                    {
                        cout<<"La letra "<<letra<<" no se encuentra en el arreglo"<<endl;
                        cout<<arregloPosiciones[0]<<endl;
                    }
                    else
                    {
                        for(int i=0; i<pos; i++)
                        {
                            cout<<arregloPosiciones[i]<<"\t"<<endl;
                        }
                        cout<<"Posiciones mostradas "<<endl;
                    }
                    delete[] arregloPosiciones;
                    arregloPosiciones=nullptr;
                    break;

            case 6: pos=stoi(val.leerI("Digite la posición a retornar: "));
                    cout<<letras.retornarLetra(pos)<<endl; break;

            case 7: letras.juego(); break;           

            case 8: letras.borrar(); cout<<"Adiós!"<<endl; break;

            default: cout<<"Posición no válida. Intente de nuevo."<<endl; break;

        }
    } while (opc!=8);
    
}