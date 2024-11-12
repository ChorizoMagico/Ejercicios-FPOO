#include "Universidad.h"

int main()
{
    Validaciones miValidación= Validaciones();

    Universidad UniValle= Universidad(miValidación);
    UniValle.menú(miValidación); 
}