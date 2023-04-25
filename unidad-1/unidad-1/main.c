#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vectores.h"
#include "cadenas.h"
#include "matrices.h"
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

void test_esPalindromo(){
    char * s1 = "A man, a plan, a canal: Panama";
    char * s2 = "Madam, I'm Adam";
    char * s3 = "Hello, world";

    printf("%s is %sa palindrome\n", s1, esPalindromo(s1) ? "" : "not ");
    printf("%s is %sa palindrome\n", s2, esPalindromo(s2) ? "" : "not ");
    printf("%s is %sa palindrome\n", s3, esPalindromo(s3) ? "" : "not ");
}

void test_contarSubcadenas(){
    char * s1 = "banana";
    char * s2 = "an";
    char * s3 = "abracadabra";
    char * s4 = "bra";

    printf("The number of occurrences of %s in %s is %d\n", s2, s1, contarSubcadenas(s1, s2));
    printf("The number of occurrences of %s in %s is %d\n", s4, s3, contarSubcadenas(s3, s4));
    printf("The number of occurrences of %s in %s is %d\n", s3, s4, contarSubcadenas(s4, s3));
    printf("The number of occurrences of %s in %s is %d\n", s1, s1, contarSubcadenas(s1, s1));
}

void test_proximaPalabra() {
  char * s1 = "Hello, world!";
  char * s2 = "This is a test.";
  char * s3 = "1234567890";
  char * s4 = "";
  char * s5 = "What about this one?";
  char * s6 = "No punctuation here";
  char * s7 = "!@#$%^&*()";
  char * s8 = "A single word";

  const char * start;
  const char * end;

  printf("The next word in %s is %s\n", s1, proximaPalabra(s1, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s2, proximaPalabra(s2, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s3, proximaPalabra(s3, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s4, proximaPalabra(s4, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s5, proximaPalabra(s5, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s6, proximaPalabra(s6, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s7, proximaPalabra(s7, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
  printf("The next word in %s is %s\n", s8, proximaPalabra(s8, &start, &end));
  printf("The start pointer is %p and the end pointer is %p\n", start, end);
}

void test_mostrarMatriz() {
  // Declare and initialize some matrices
  int mat1[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int mat2[3][2] = {{7, 8}, {9, 10}, {11, 12}};
  int mat3[1][4] = {{13, 14, 15, 16}};

  // Print the matrices using the mostrarMatriz function
  printf("The matrix mat1 is:\n");
  mostrarMatriz(2, 3, mat1); // Cast the matrix to a pointer to int
  printf("\n");

  printf("The matrix mat2 is:\n");
  mostrarMatriz(3, 2, mat2); // Cast the matrix to a pointer to int
  printf("\n");

  printf("The matrix mat3 is:\n");
  mostrarMatriz(1, 4, mat3); // Cast the matrix to a pointer to int
}

int main()
{
//    int v[100] = {1,2,3,4,5};
//    int ce = 5;
//    printf("%p=>\n", v);
//    ce = testInsertarEnPos(v, ce, TAM);
//    printf("%p\n", v);
//    ce = testInsertarOrdenado(v, ce, TAM);
//    printf("%p\n", v);
    int mat1[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}};
    int mat2[5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}};
    int mat3[5][2] = {
    {1,2},
    {3,4},
    {5,6},
    {7,8},
    {9,10}
    };
    int res[5][2];
    multiplicarMatrices(5,5,mat2,5,2,mat3,res);
    mostrarMatriz(5,2,res);

    return 0;
}
