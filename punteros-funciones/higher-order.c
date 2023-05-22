#include "higher-order.h"
#include <stdio.h>
#include <stdlib.h>

void * copiarGen(void * d, void * s, int tam);

void * forEach(void * vec, size_t ce, size_t tam, void (mostrar) (void *)){
    void * start = vec;
    for(int i = 0; i < ce; i++){
        mostrar(vec);
        vec += tam;
    }
    return start;
}

void * reduce(void * vec, void * acum, size_t ce, size_t tam, void (accion)(void * elem, void * acum)){
    for(int i = 0; i < ce; i++){
        accion(vec, acum);
        vec += tam;
    }
    return acum;
}

int filter(void * vec, size_t ce, size_t tam, int (*comp)(void * a)){
    void * read = vec;
    void * write = vec;
    int eliminados = 0;
    for(int i = 0; i < ce; i++){
        if(!comp(read)){
            eliminados++;
        } else {
            write = copiarGen(write,read,tam);
        }
        read += tam;
    }
    return ce - eliminados;
}

void * copiarGen(void * d, void * s, int tam){
    for(int i = 0; i < tam; i++){
        *((char*)d) = *((char*)s);
        d++;
        s++;
    }
    return d;
}
