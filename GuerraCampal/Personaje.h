#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>
using namespace std;

class Personaje
{
    protected:
        int vida;
        int daño;
        bool vivo;

    public:
        Personaje();
        Personaje(int, int);
        virtual ~Personaje();
        void atacar(Personaje*&);
        int getVida();
        virtual string getEstado();
        virtual void setVida(int);

};

#else
class Personaje;

#endif