#include "Matrices.h"
int* __cargarMatrizEspiralCentroAIAD(int mat[][MAX_COL], int filas, int columnas, int* vec){
    int filaSup = (filas / 2) - 1;
    int filaInf = (filas / 2) + 1;
    int colDer = (columnas / 2) + 1;
    int colIzq = (columnas / 2) - 1;
    int i = filas / 2;
    int j = columnas / 2;
//    printf("%d",filaSup);
//    printf("%d",filaInf);
//    printf("%d",colIzq);
//    printf("%d",colDer);
    printf("primer%d",i);
    printf("primer%d",j);
    while(filaSup >= -1 &&
          filaInf <= filas &&
          colIzq >= -1 &&
          colDer <= columnas){
        // mientras i > filaSup
        while(i > filaSup && filaSup >= -1){
            printf("i:%d j:%d\n",i,j);
            *vec = mat[i][j];
            vec++;
            i--;
        }
        filaSup--;
        // mientras j > colIzq
        while(j > colIzq && colIzq >= -1){
            printf("i:%d j:%d\n",i,j);
            *vec = mat[i][j];
            vec++;
            j--;
        }
        colIzq--;
        // mientras i < filaInf
        while(i < filaInf && filaInf <= filas){
            printf("i:%d j:%d\n",i,j);
            *vec = mat[i][j];
            vec++;
            i++;
        }
        filaInf++;
        // mientras j < colDer
        while(j < colDer && colDer <= columnas){
            printf("i:%d j:%d\n",i,j);
            *vec = mat[i][j];
            vec++;
            j++;
        }
        colDer++;
    }
    return vec;
}
