#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#define TAM 10

int main()
{
    int vec[TAM] = {6,1,1,12,1,21,34,1};
    int ce = 8;
    mostrarVector(vec, ce);
    ce = eliminarElem(vec, ce, 1);
    mostrarVector(vec, ce);
    return 0;
}
