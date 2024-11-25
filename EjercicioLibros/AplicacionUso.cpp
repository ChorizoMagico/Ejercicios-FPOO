#include "AplicacionUso.h"
#include "Validaciones.h"

AplicacionUso::AplicacionUso()
{
    libros=nullptr;
    personas=nullptr;
    cantidadL=0;
    cantidadP=0;
}

void AplicacionUso::crearArregloL(Validaciones& val)
{
    int tamaño;
    tamaño=stoi(val.leerI(0,"¿Cuántos libros desea crear? "));
    try
    {
        libros=new Libro[tamaño];
        cantidadL=tamaño;
    }
    catch(const bad_alloc& e)
    {
        cout<<"Tamaño demasiado grande. Inténtelo de nuevo"<<endl;
        crearArregloL(val);
    }
    

}

void AplicacionUso::crearArregloP(Validaciones& val)
{
    int tamaño;
    tamaño=stoi(val.leerI(0,"¿Cuántas personas desea crear? "));
    try
    {
        personas=new Persona[tamaño];
        cantidadP=tamaño;
    }
    catch(const bad_alloc& e)
    {
        cout<<"Tamaño demasiado grande. Inténtelo de nuevo"<<endl;
        crearArregloP(val);
    }

}

void AplicacionUso::menú()
{
    int opc=0, contadorP=0, contadorL=0, páginas, índice, índice2, índice3;
    Libro* libro=nullptr;
    string nombre;
    Validaciones val= Validaciones();
    crearArregloL(val);
    crearArregloP(val);
    do
    {
        cout<<"**MENÚ***\n1. Agregar libros\n 2. Agregar personas.\n3. Asignar libro a una persona\n"
            <<"4. Una persona le presta el libro a otra\n 5. Una persona rompe páginas del libro.\n"
            <<"6. Mostrar información de las personas\n7. Mostrar información de los libros\n"
            <<"8. Salir "<<endl;
        opc=stoi(val.leerI("Digite una opción: "));
        switch(opc)
        {
            case 1:
                if(contadorL<cantidadL)
                {
                    nombre=val.leer("\nDigite el nombre del libro: ");
                    páginas=stoi(val.leerI(0,"\nDigite la cantidad de páginas del libro: "));
                    libros[contadorL].setNombre(nombre);
                    libros[contadorL].setPáginas(páginas);
                    contadorL++;
                }
                else
                {
                    cout<<"Libros llenos"<<endl;
                }
                break;

            case 2: 
                if(contadorP<cantidadP)
                {
                    nombre=val.leer("Digite el nombre de la persona: ");
                    if(contadorL==0)
                    {
                        libro=nullptr;
                        cout<<"\nNo hay libros para asignar"<<endl;
                    }
                    else
                    {
                        mostrarLibros(contadorL);
                        índice=stoi(val.leerI(-1,"\nDigite el número del libro que posee la persona: ", contadorL));
                        libro=&libros[índice];
                    }
                    personas[contadorP].setNombre(nombre);
                    personas[contadorP].setLibro(libro);
                    libro=nullptr;
                    contadorP++;
                }
                else
                {
                    cout<<"\nPersonas llenas"<<endl;
                }
                break;

            case 3:
                mostrarPersonas(contadorP);
                mostrarLibros(contadorL);
                índice=stoi(val.leerI(-1,"\nDigite la persona seleccionada: ", contadorP));
                índice2=stoi(val.leerI(-1,"\nDidite el libro a asignar: ", contadorL));
                personas[índice].setLibro(&libros[índice2]);
                break;

            case 4:
                mostrarPersonas(contadorP);
                mostrarLibros(contadorL);
                índice=stoi(val.leerI(-1, "\n¿Quién presta el libro? ", contadorP));
                índice2=stoi(val.leerI(-1,"\n¿A quién le prestan el libro? ",contadorP));
                índice3=stoi(val.leerI(-1, "\n¿Cuál libro presta? ",contadorL));
                personas[índice2].recibe(personas[índice].prestar(&libros[índice3]));
                break;
            
            case 5:
                mostrarPersonas(contadorP);
                índice=stoi(val.leerI(-1, "\n¿Quién rompe las páginas del libro? ", contadorP));
                páginas=stoi(val.leerI(0,"\n¿Cuántas páginas rompe? "));
                personas[índice].rompePáginas(páginas);
                break;

            case 6:
                mostrarPersonas(contadorP);
                break;

            case 7:
                mostrarLibros(contadorL);
                break;
            
            case 8:
                if(personas!=nullptr)
                {
                    delete [] personas;
                }
                if(libros!=nullptr)
                {
                    delete [] libros;
                }
                cout<<"Adiós!"<<endl;
                break;
            
            default:
                cout<<"Opción no válida"<<endl;
                break;
        }
    } while (opc!=8);
    
    
}

void AplicacionUso::mostrarPersonas(int índice)
{
    for(int i=0; i<índice; i++)
    {
        cout<<"\nNo. "<<to_string(i)<<"\nNombre: "<<personas[i].getNombre();
        if(personas[i].getLibro()==nullptr)
        {
            cout<<"\tSin libro en posesión"<<endl;
        }
        else
        {
            cout<<"\tLibro: "<<personas[i].getLibro()->getNombre()<<endl;
        }
    }
}

void AplicacionUso::mostrarLibros(int índice)
{
    for(int i=0; i<índice; i++)
    {
        cout<<"\nNo. "<<to_string(i)+"\nNombre: "<<libros[i].getNombre()<<"\tNúmero de páginas: "<<libros[i].getPáginas();
        cout<<"\tPáginas rotas: "<<libros[i].getPáginasRotas()<<endl;
    }
}

AplicacionUso::~AplicacionUso(){}