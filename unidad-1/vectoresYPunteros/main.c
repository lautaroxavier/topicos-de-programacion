#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

int main()
{
    int vec[TAM] = {6,7,10,12,17,21};
    mostrarVector(vec, 6);
    insertarOrdenado(vec, 6, 30);
    mostrarVector(vec, 6);
    return 0;
}
