#include "Batalla.h"

Batalla::Batalla()
{
    numTurno=0;
    for(int i=0; i<7; i++)
    {
        if(i<5)
        {
            dosEjércitos[0].getSold(i) = new Arqueros(4,3);
            dosEjércitos[1].getSold(i) = new Draconauriusplus(3, 1);
        }
        else
        {
            dosEjércitos[0].getSold(i) = new Arquerosplus(7, 5);
            dosEjércitos[1].getSold(i) = new Draconaurius(2, 1);
        }
    }

}
Batalla::~Batalla(){}

void Batalla::estadoActual()
{
    cout<<"Turno "<<numTurno<<"\nEstado actual de la batalla:\n"
        <<"Ejército 1:\t\tEjército 2\n";
    for(int i=0; i<7; i++)
    {
        if(i<2)
        {
            cout<<"Arquero ++ "<<to_string(i+1)<<": "<<(*dosEjércitos[0].getSold(i)).getEstado()<<", Vida restante: "<<(*dosEjércitos[0].getSold(i)).getVida()<<endl;
        }
        else
        {
            cout<<"Arquero "<<to_string(i-1)<<": "<<(*dosEjércitos[0].getSold(i)).getEstado()<<", Vida restante: "<<(*dosEjércitos[0].getSold(i)).getVida()<<endl;
        }

        if(i<5)
        {
            cout<<"\t\tDraconaurius++ "<<to_string(i+1)<<": "<<(*dosEjércitos[1].getSold(i)).getEstado()<<", Vida restante: "<<(*dosEjércitos[0].getSold(i)).getVida()<<endl;
        }
        else
        {
            cout<<"\t\tDraconaurius "<<to_string(i-4)<<": "<<(*dosEjércitos[1].getSold(i)).getEstado()<<", Vida restante: "<<(*dosEjércitos[0].getSold(i)).getVida()<<endl;
        }
    }
}

void Batalla::cerrar()
{
    for(int i=0; i<7; i++)
         {
            delete dosEjércitos[0].getSold(i);
            dosEjércitos[0].getSold(i) = nullptr;
            delete dosEjércitos[1].getSold(i);
            dosEjércitos[0].getSold(i) = nullptr;
        }
}

void Batalla::turno(Validaciones val)
{
    int opc=0, índice1=0, índice2=0;
    string nombre1, nombre2;
    if(dosEjércitos[0].getFinados()>=7)
    {
        cout<<"El ejército 2 gana, queda con "<<to_string(7-dosEjércitos[1].getFinados())<<" arqueros"<<endl;
        cerrar();
        return;
    }

    if(dosEjércitos[1].getFinados()>=7)
    {
        cout<<"El ejército 1 gana, queda con "<<to_string(7-dosEjércitos[0].getFinados())<<" draconaurius"<<endl;
        cerrar();
        return;
    }

    numTurno++;
    if(numTurno==1)
    {
        cout<<"Ejército 1 empieza con 7 Arqueros\nEjército 2 empieza con 6 Draconaurius"<<endl;
    }
    estadoActual();
    do
    {
        opc=stoi(val.leerI("\n¿Qué desea hacer?\n1. Ataque del ejército de arqueros (1)\n2. Ataque del ejército de draconaurius(2)\n3. Salir\n"));
        switch(opc)
        {
            case 1: do
                    {
                        índice1=stoi(val.leerI(0,"\n¿Quién ataca? : ",8))-1;

                        if(índice1<5)
                        {
                            nombre1="Arquero "+to_string(índice1+1);
                        }

                        else
                        {
                            nombre1="Arquero ++"+to_string(índice1-4);
                        }

                        if(dosEjércitos[0].getSold(índice1)->getEstado()=="Muerto")
                        {
                            cout<<"\nEl "<<nombre1<<" está muerto"<<endl;
                        }
                    } while (dosEjércitos[0].getSold(índice1)->getEstado()=="Muerto");

                    do
                    {
                        índice2=stoi(val.leerI(-1,"\n¿A quién ataca? : ",7));

                        if(índice2<5)
                        {
                            nombre2="Draconaurius ++ "+to_string(índice2+1);
                        }

                        else
                        {
                            nombre2="Draconaurius "+to_string(índice2-4);
                        }

                        if(dosEjércitos[1].getSold(índice2)->getEstado()=="Muerto")
                        {
                            cout<<"\nEl "<<nombre2<<" está muerto"<<endl;
                        }
                    } while (dosEjércitos[1].getSold(índice2)->getEstado()=="Muerto");

                    (*dosEjércitos[0].getSold(índice1)).atacar(dosEjércitos[1].getSold(índice1));

                    cout<<"El "<<nombre1<<" ha atacado al "<<nombre2<<endl;
                    if(dosEjércitos[1].getSold(índice2)->getEstado()=="Muerto")
                    {
                        cout<<"El "<<nombre2<<" ha muerto"<<endl;
                        dosEjércitos[1].setFinados();
                    }
                    turno(val);
                    break;

            case 2: do
                    {
                        índice1=stoi(val.leerI(0,"\n¿Quién ataca? : ",8))-1;

                        if(índice1<5)
                        {
                            nombre1="Draconaurius ++ "+to_string(índice1+1);
                        }

                        else
                        {
                            nombre1="Draconaurius "+to_string(índice1-4);
                        }

                        if(dosEjércitos[1].getSold(índice1)->getEstado()=="Muerto")
                        {
                            cout<<"\nEl "<<nombre1<<" está muerto"<<endl;
                        }
                    } while (dosEjércitos[1].getSold(índice1)->getEstado()=="Muerto");

                    do
                    {
                        índice2=stoi(val.leerI(-1,"\n¿A quién ataca? : ",7));

                        if(índice2<5)
                        {
                            nombre2="Arquero "+to_string(índice2+1);
                        }

                        else
                        {
                            nombre2="Arquero++ "+to_string(índice2-4);
                        }

                        if(dosEjércitos[0].getSold(índice2)->getEstado()=="Muerto")
                        {
                            cout<<"\nEl "<<nombre2<<" está muerto"<<endl;
                        }
                    } while (dosEjércitos[0].getSold(índice2)->getEstado()=="Muerto");

                    (*dosEjércitos[1].getSold(índice1)).atacar(dosEjércitos[0].getSold(índice1));

                    cout<<"El "<<nombre1<<" ha atacado al "<<nombre2<<endl;
                    if(dosEjércitos[0].getSold(índice2)->getEstado()=="Muerto")
                    {
                        cout<<"El "<<nombre2<<" ha muerto"<<endl;
                        dosEjércitos[0].setFinados();
                    }
                    turno(val);
                    break;

            case 3: cout<<"Adiós!!!"<<endl; 
                    cerrar();
                    break;

            default: cout<<"Opción no válida. Intente de nuevo"<<endl; break;
        }
    } while (opc!=3 and opc!=2 and opc!=1);
    
}