#include "Programa.h"
Programa::Programa()
{
    índice=0;
}

Programa::~Programa(){}

void Programa::ingresarFiguras(Validaciones val)
{
    int opc=0;
    string color, tipo;
    double radio, base, altura, lado1, lado2, lado3;
    do
    {
        opc=stoi(val.leerI("\n¿Cuál figura desea ingresar?\n1. Figura genérica\n2. Círculo\n3. Rectángulo\n4. Triángulo\n5. Salir\n"));
        switch(opc)
        {
            case 1:
                color=val.leer("\nDigite un color: ");
                totalFiguras[índice]= new Figura(color);
                cout<<"\nFigura genérica ingresada con éxito en la posición"<<to_string(índice+1)<<" de 50"<<endl;
                índice++;
                break;
            case 2:
                color=val.leer("\nDigite un color: ");
                radio=stod(val.leerD(0,"\nDigite el radio: "));
                totalFiguras[índice]= new Círculo(color, radio);
                cout<<"\nCírculo creado con éxito en la posición "<<to_string(índice+1)<<" de 50"<<endl;
                índice++;
                break;
            case 3:
                color=val.leer("\nDigite un color: ");
                base=stod(val.leerD(0,"\nDigite la base: "));
                altura=stod(val.leerD(0,"\nDigite la altura: "));
                totalFiguras[índice]= new Rectángulo(color, base, altura);
                cout<<"\nRectángulo creado con éxito en la posición "<<to_string(índice+1)<<" de 50"<<endl;
                índice++;
                break;
            case 4: 
                color=val.leer("\nDigite un color: ");
                do
                {
                    opc=stoi(val.leerI("\nDigite un tipo de triángulo: \n1. Escaleno\n2. Isósceles\n3. Equilátero\n"));
                    switch(opc)
                    {
                        case 1: tipo="Escaleno"; break;
                        case 2: tipo="Isósceles"; break;
                        case 3: tipo="Equilátero"; break;
                        default: cout<<"\nTipo de triángulo no válido. Intente de nuevo.";break;
                    }
                }while(opc!=1 and opc!=2 and opc!=3);
                base=stod(val.leerD(0,"\nDigite la base del triángulo: "));
                altura=stod(val.leerD(0,"\nDigite la altura del triángulo: "));
                if(tipo=="Escaleno")
                {
                    lado1=base;
                    lado2=base;
                    lado3=base;
                }
                else
                {
                    if(tipo=="Isósceles")
                    {
                        lado1=base;
                        do
                        {
                            lado2=stod(val.leerD(0,"\nDigite un lado de su triángulo diferente a la base: "));
                            if(lado1==lado2)
                            {
                                cout<<"\nIngresó el mismo lado dos veces (como base y como lado). Ingrese un lado diferente a la base. "<<endl;
                            }
                        }while(lado2==lado1);
                        lado3=lado2;
                    }
                    else
                    {
                        if(tipo=="Escaleno")
                        {
                            lado1=stod(val.leerD(0,"\nDigite el lado 1 de su triángulo: "));
                            do
                            {
                                lado2=stod(val.leerD(0,"\nDigite el segundo lado: "));
                                if(lado1==lado2)
                                {
                                    cout<<"\nEl triángulo que está intentando ingresar no es escaleno. Por favor, digite un triángulo escaleno."<<endl;
                                }
                            } while (lado1==lado2);
                            do
                            {
                                lado3=stod(val.leerD(0,"\nDigite el tercer lado: "));
                                if(lado3==lado2 or lado3==lado1)
                                {
                                    cout<<"\nEl triángulo que está intentando ingresar no es escaleno. Por favor, digite un triángulo escaleno."<<endl;
                                }
                            } while (lado3==lado2 or lado3==lado1);
                        }
                    }
                }
                totalFiguras[índice]= new Triángulo(color, tipo, altura, base, lado1, lado2, lado3);
                cout<<"\nTriángulo ingresado con éxito en la posición "<<to_string(índice+1)<<" de 50"<<endl;
                índice++;
                break;
            case 5: cout<<"\nAdiós!!"<<endl; break;
            default: cout<<"\nOpción no válida. Intente de nuevo."<<endl; break;
        }
    } while (opc!=5 and opc!=4 and opc!=3 and opc!=2 and opc!=1);
    
}

void Programa::mostrarFiguras()
{
    for(int i=0; i<índice; i++)
    {
        cout<<totalFiguras[i]->mostrarAtributos()<<endl;;
    }
    cout<<to_string(índice)<<" figuras mostradas con éxito"<<endl;
}
void Programa::borrarFiguras()
{
    for(int i=0; i<índice; i++)
    {
        delete totalFiguras[i];
        totalFiguras[i]=nullptr;
    }
    cout<<to_string(índice)<<" figuras borradas con éxito"<<endl;
    índice=0;
}

void Programa::menú(Validaciones val)
{
    int opc=0;
    do
    {
        cout<<"Total de figuras ingresadas: "<<to_string(índice)<<" de 50"<<endl;
        opc=stoi(val.leerI("Digite una opción.\n1. Ingresar figura\n2. Borrar figuras\n3. Mostrar figuras\n4. Salir\n "));
        switch(opc)
        {
            case 1: 
                if(índice<50)
                    ingresarFiguras(val);
                else
                    cout<<"Espacios llenos. Borre figuras antes de añadir nuevas."<<endl;
                break;
            case 2:
                borrarFiguras();
                break;
            case 3: 
                mostrarFiguras();
                break;
            case 4:
                cout<<"Adiós!!!"<<endl;
                break;
            default:
                cout<<"Opción no válida..."<<endl;
                break;
        }
    } while (opc!=4);
    
}
