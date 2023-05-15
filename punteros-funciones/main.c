#include <stdio.h>
#include <stdlib.h>

typedef struct sAlum{
    char nya[20];
    float prom;
} tAlum;

void * forEach(void * vec, size_t ce, size_t size, void (f)(void*));

void * reduce(void * vec, void * acum, size_t ce, size_t size, void (accion)(void* elem, void* acum));

void * filter(void * vec, size_t ce, size_t size, int* (comp)(void * a));

void mostrarAlum(void *);

void sumarPromediosAlum(void * elem, void * acum);

int promedioMayorA7(void * a);

int main()
{
    tAlum alumnos[] = {
    {"lui", 5.6},
    {"addi", 7.8},
    {"xori", 9.3}
    };
    void * elem = alumnos;
    forEach(elem, 3, sizeof(tAlum), mostrarAlum);
    float suma = 0.0;
    reduce(elem, &suma, 3, sizeof(tAlum),sumarPromediosAlum);
    printf("suma de promedios: %f", suma);
    filter(elem,3,sizeof(tAlum),promedioMayorA7);
    return 0;
}

void sumarPromediosAlum(void * elem, void * acum){
    *(float*)acum += ((tAlum*)elem)->prom;
}

void * forEach(void * vec, size_t ce, size_t size, void (mostrar) (void *)){
    void * start = vec;
    for(int i = 0; i < ce; i++){
        mostrar(vec);
        vec += size;
    }
    return start;
}

void mostrarAlum(void * elem){
    tAlum * alum = (tAlum *)elem;
    printf("%s %f\n",alum->nya,alum->prom);
}

void * reduce(void * vec, void * acum, size_t ce, size_t size, void (accion)(void * elem, void * acum)){
    for(int i = 0; i < ce; i++){
        accion(vec, acum);
        vec += size;
    }
    return acum;
}

void * filter(void * vec, size_t ce, size_t size, int* (comp)(void * a)){
    void * start = vec;
    for(int i = 0; i < ce; i++){
        if(!comp(vec)){
            printf("el elemento %d no cumple la condicion\n",i);
            // eliminar el elemento
        }
        vec += size;
    }
    return start;
}

int promedioMayorA7(void * a){
    tAlum * alumno = (tAlum*)a;
    int result = (alumno->prom) > 7.0f;
    return result;
}

