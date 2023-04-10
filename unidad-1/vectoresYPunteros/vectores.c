#include "vectores.h"

void mostrarVector(int * v, int ce){
    printf("[");
    for(int i = 0; i < ce; i++){
        printf("%d,", *v);
        v++;
    }
    printf("]\n");
}

int insertarOrdenado(int * v, int ce, int elem){
    int * start = v;
    if(ce != TAM){
        v += ce;
    } else {
        v += ce-1;
    }
    while(v != start  && *(v-1) > elem){
        *v = *(v-1);
        v--;
    }
    *v = elem;
    return ce;
}
