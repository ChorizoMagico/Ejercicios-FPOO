#include <clocale>
#include "Programa.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"es_ES.UTF-8");
    Programa miPrograma=Programa();
    Validaciones miValidación=Validaciones();
    miPrograma.menú(miValidación);
}