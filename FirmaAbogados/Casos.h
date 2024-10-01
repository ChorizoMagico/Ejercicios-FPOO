#ifndef CASOS_H
#define CASOS_H
#include <string>
using namespace std;

class Casos
{
    private:
        int número;
        string id;
        string cliente;
    public:
        Casos();
        ~Casos();
        int getNúmero();
        string getID();
        string getCliente();
        void setNúmero(int);
        void setID(string);
        void setCliente(string);
};


#else
class Casos;
#endif