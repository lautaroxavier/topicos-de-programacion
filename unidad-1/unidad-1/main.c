#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"
#include "cadenas.h"
#define TAM 10

int testInsertarEnPos(int * vec, int ce, int tam){
    char response = 'y';
    int pos = -1;
    int elem = 0;
    mostrarVector(vec, ce);
    while(response == 'y'){
        printf("Ingrese la posicion de insercion: ");
        scanf("%d",&pos);
        fflush(stdin);
        printf("Ingrese el elemento a insertar: ");
        scanf("%d", &elem);
        fflush(stdin);
        ce = insertarEnPos(vec, pos, ce, elem, tam);
        mostrarVector(vec, ce);
        printf("desea continuar ingresando elementos? (y/n): ");
        scanf("%s", &response);
        fflush(stdin);
    }
    return ce;
}

int testInsertarOrdenado(int * vec, int ce, int tam){
    char response = 'y';
    int elem = 0;
    mostrarVector(vec, ce);
    while(response == 'y'){
        printf("Ingrese el elemento a insertar: ");
        scanf("%d", &elem);
        fflush(stdin);
        ce = insertarOrdenado(vec, ce, elem, tam);
        mostrarVector(vec, ce);
        printf("desea continuar ingresando elementos? (y/n): ");
        scanf("%s", &response);
        fflush(stdin);
    }
    return ce;
}

int main()
{
//    int vec[20] = {1,2,3,4,5};
//    int ce = 5;
//    printf("%p=>\n", vec);
//    ce = testInsertarEnPos(vec, ce, TAM);
//    printf("%p\n", vec);
//    ce = testInsertarOrdenado(vec, ce, TAM);
//    printf("%p\n", vec);
    char s1[100] = "hola";
    printf("%s\n",s1);
    char s2[] = "HOLA";
    int cmp = myStrcmpi(s1, s2);
    printf("%d",cmp);
    return 0;
}
