#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

void mostrarMatriz(int row, int col, int mat[row][col]);

int compararMatriz(int row, int col, int mat1[row][col], int mat2[row][col]);

int sumarDiagonal(int row, int col, int mat[row][col]);

int sumarDiagonalSecundaria(int row, int col, int mat[row][col]);

int esIdentidad(int row, int col, int mat[row][col]);

int sumarTrianguloInferior(int row, int col, int mat[row][col]);

void mostrarTrianguloInferior(int row, int col, int mat[row][col]);

void mostrarTrianguloInferiorDiagSec(int row, int col, int mat[row][col]);

void mostrarTrianguloSuperior(int row, int col, int mat[row][col]);

void mostrarTrianguloSuperiorDiagSec(int row, int col, int mat[row][col]);

void mostrarTriangulosEntreDiagonales(int row, int col, int mat[row][col]);

void transponerMatriz(int row, int col, int mat[row][col]);

void mostrarMatrizEspiral(int row, int col, int mat[row][col]);

int multiplicarMatrices(int row1, int col1, int mat1[row1][col1], int row2, int col2, int mat2[row2][col2], int res[row1][col2]);

#endif // MATRICES_H_INCLUDED
