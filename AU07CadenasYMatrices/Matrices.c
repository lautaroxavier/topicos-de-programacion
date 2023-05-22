#include "Matrices.h"
int* __cargarMatrizEspiralCentroAIAD(int mat[][MAX_COL], int filas, int columnas, int* vec){
    int filaSup = (filas / 2);
    int filaInf = (filas / 2);
    int colDer = (columnas / 2);
    int colIzq = (columnas / 2);
    int i = filas / 2;
    int j = i;
//    printf("fila sup: %d\n",filaSup);
//    printf("fila inf: %d\n",filaInf);
//    printf("col izq: %d\n",colIzq);
//    printf("col der: %d\n",colDer);
//    printf("primer i: %d\n",i);
//    printf("primer j: %d\n",j);
    while(filaSup >= 0 &&
          filaInf <= (filas - 1) &&
          colDer <= (columnas - 1) &&
          colIzq >= 0){
        // arriba
        while(i >= filaSup && j >= 0 && j <= (columnas - 1) && i >= 0 && i <= (filas - 1)){
//            printf("i:%d j:%d = %d\n",i,j, mat[i][j]);
            *vec = mat[i][j];
            vec++;
            i--;
        }
        filaSup--;
        // izquierda
        while(j >= colIzq && i >= 0 && i <= (filas - 1) && j >= 0 && j <= (columnas - 1)){
//            printf("i:%d j:%d = %d\n",i,j, mat[i][j]);
            *vec = mat[i][j];
            vec++;
            j--;
        }
        colIzq--;
        // abajo
        while(i <= filaInf && j >= 0 && j <= (columnas - 1) && i >= 0 && i <= (filas - 1)){
//            printf("i:%d j:%d = %d\n",i,j, mat[i][j]);
            *vec = mat[i][j];
            vec++;
            i++;
        }
        filaInf++;
        // derecha
        while(j <= colDer && i >= 0 && i <= (filas - 1) && j >= 0 && j <= (columnas - 1)){
//            printf("i:%d j:%d = %d\n",i,j, mat[i][j]);
            *vec = mat[i][j];
            vec++;
            j++;
        }
        colDer++;
    }
    return vec;
}
