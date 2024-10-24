#include <clocale>
#include "Batalla.h"

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    Batalla miBatalla=Batalla();
    Validaciones val=Validaciones();
    miBatalla.turno(val);
}