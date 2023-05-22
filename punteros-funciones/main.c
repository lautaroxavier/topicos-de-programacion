#include <stdio.h>
#include <stdlib.h>
#include "higher-order.h"

typedef struct sAlum{
    char nya[20];
    float prom;
} tAlum;

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

void mostrarAlum(void * elem){
    tAlum * alum = (tAlum *)elem;
    printf("%s %f\n",alum->nya,alum->prom);
}

int promedioMayorA7(void * a){
    tAlum * alumno = (tAlum*)a;
    int result = (alumno->prom) > 7.0f;
    return result;
}

