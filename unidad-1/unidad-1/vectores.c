#include "vectores.h"

void mostrarVector(int * v, int ce){
    printf("[");
    for(int i = 0; i < ce; i++){
        printf("%d,", *v);
        v++;
    }
    printf("]\n");
}

int insertarEnPos(int * v, int pos, int ce, int elem, int tam){
    int * start = v;
    // salir de la funcion si el vector esta lleno
    // o la posicion es invalida
    if(ce == tam || pos > ce){
        return ce;
    }
    v += ce;
    while(v != (start + pos)){
        *v = *(v-1);
        v--;
    }
    *v = elem;
    return ce + 1;
}

int insertarOrdenado(int * v, int ce, int elem, int tam){
    int * start = v;
    // verificar que el vector no este lleno
    if(ce == tam){
        return ce;
    }
    v += ce;
    // correr los elementos una posicion hacia adelante
    // hasta llegar al inicio o llegar a la posicion de insercion
    while(v != start  && *(v-1) > elem){
        *v = *(v-1);
        v--;
    }
    *v = elem;
    return ce + 1;
}

int eliminarPos(int * v, int pos, int ce){
    int * start = v;
    // posicion invalida
    if(pos >= ce){
        return ce;
    }
    v += pos;
    while(v < (start + ce - 1)){
        *v = *(v+1);
        v++;
    }
    return ce-1;
}

int eliminarElem(int * v, int ce, int elem){
    int * start = v;
    // encontrar la posicion del elemento
    while(*v != elem && v != (start + ce)){
        v++;
    }
    // si el elemento no esta, devolver la misma cantidad de elementos
    if(v == (start + ce)){
        return ce;
    }
    while(v < (start + ce - 1)){
        *v = *(v + 1);
        v++;
    }
    return ce - 1;
}

int eliminarTodosElem(int * v, int ce, int elem){
    int * read = v;
    int * write = v;
    int result = ce;
    while(read != (v + ce)){
        if(*read != elem){
            if(read != write){
                *write = *read;
            }
            write++;
        } else {
            result--;
        }
        read++;
    }
    return result;
}
