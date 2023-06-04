#include "higher-order.h"
#include <stdio.h>
#include <stdlib.h>

void * copiarGen(void * d, void * s, int tam);

void * intercambiar(void * d1, void * d2, int tam);

void * buscarMenor(void * vec, int tam, int ce, int (*cmp)(const void * a1, const void * a2));

void * forEach(void * vec, size_t ce, size_t tam, void (*mostrar) (void *)){
    void * start = vec;
    for(int i = 0; i < ce; i++){
        mostrar(vec);
        vec += tam;
    }
    return start;
}

void * reduce(void * vec, void * acum, size_t ce, size_t tam, void (*accion)(void * elem, void * acum)){
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

void * intercambiar(void * d1, void * d2, int tam){
    char * aux = 0;
    *aux = *((char*)d1);
    *((char*)d1) = *((char*)d2);
    *((char*)d2) = *aux;
    for(int i = 1; i < tam; i++){
        *aux = *((char*)d1);
        *((char*)d1) = *((char*)d2);
        *((char*)d2) = *aux;
    }
    return d1;
}

void * buscarMenor(void * vec, int ce, int tam, int (*cmp)(const void * a1, const void * a2)){
    void * menor = vec;
    vec += tam;
    for(int i = 1; i < ce - 1; i++){
        if(cmp(vec, menor) < 0){
            intercambiar(vec, menor, tam);
        }
        vec += tam;
    }
    return menor;
}

int ordSeleccion(void * vec, size_t ce, size_t tam, int (*cmp)(const void * a1, const void * a2)){
    return 0;
}
