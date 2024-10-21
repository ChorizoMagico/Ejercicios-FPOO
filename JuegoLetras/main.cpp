#include "UsaLetras.h"
#include "Letras.h"
#include <clocale>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    UsaLetras programa=UsaLetras();
    programa.menú();
}