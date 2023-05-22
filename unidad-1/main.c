#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vectores.h"
#include "cadenas.h"
#include "matrices.h"
#include "tests.h"
#include "tdavector.h"

#define TAM 10
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) (X) < (Y) ? (X) : (Y)
#define SWAP(X,Y)  {int t = (X); (X) = (Y); (Y) = t}
#define MOSTRAR(x,str) ({\
    printf("%d",x);\
    printf(" es ");\
    printf(#str);\
    printf("\n");\
})
#define CONCAT(x,y) x##y





int main()
{

//    int v[100] = {1,2,3,4,5};
//    int ce = 5;
//    printf("%p=>\n", v);
//    ce = testInsertarOrdenado(v,ce,100);
//    printf("%p\n", v);
//    ce = testInsertarEnPos(v,ce,100);
//    printf("%p\n", v);
//    int mat1[4][4] = {
//        {1,2,3,4},
//        {5,6,7,8},
//        {9,10,11,12},
//        {13,14,15,16}};
//    int mat2[5][5] = {
//        {1,2,3,4,5},
//        {6,7,8,9,10},
//        {11,12,13,14,15},
//        {16,17,18,19,20},
//        {21,22,23,24,25}};
//    int mat3[5][2] = {
//    {1,2},
//    {3,4},
//    {5,6},
//    {7,8},
//    {9,10}
//    };
//    int res[5][2];
//    multiplicarMatrices(5,5,mat2,5,2,mat3,res);
//    mostrarMatriz(5,2,res);

    return 0;
}
