void mostrarMatriz(int row, int col, int mat[row][col]){
    for(int i = 0; i < row; i++){
        printf("|");
        for(int j = 0; j < col; j++){
            printf("%*s%2d%*s", 2, "", mat[i][j], 2, "");
        }
        printf("|");
        printf("\n");
    }
}

int compararMatriz(int row, int col, int mat1[row][col], int mat2[row][col]){
    // las matrices deben tener las mismas dimensiones
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat1[i][j] != mat2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int sumarDiagonal(int row, int col, int mat[row][col]){
    int result = 0;
    for(int i = 0; i < row; i++){
        result += mat[i][i];
    }
    return result;
}

int sumarDiagonalSecundaria(int row, int col, int mat[row][col]){
    int result = 0;
    for(int i = 0; i < row; i++){
        result += mat[i][col - 1 - i];
    }
    return result;
}

int esIdentidad(int row, int col, int mat[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == j && mat[i][j] != 1){
                return 0;
            } else if (i != j && mat[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int sumarTrianguloInferior(int row, int col, int mat[row][col]){
    int result = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < i; j++){
            result += mat[i][j];
        }
    }
    return result;
}

void mostrarTrianguloInferior(int row, int col, int mat[row][col]){
    int result = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < i; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    return result;
}

void mostrarTrianguloSuperior(int row, int col, int mat[row][col]){
    int result = 0;
    for(int i = 0; i < row; i++){
        for(int j = i + 1; j < col; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    return result;
}

void mostrarTrianguloInferiorDiagSec(int row, int col, int mat[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = col - i; j < col; j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void mostrarTrianguloSuperiorDiagSec(int row, int col, int mat[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col - i - 1; j++){
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void mostrarTriangulosEntreDiagonales(int row, int col, int mat[row][col]) {
  // iterar las primeras filas
  for (int i = 0; i < row / 2; i++) {
    // mostar los elementos antes de la diagonal principal
    for (int j = 0; j < i; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("    ");
    // mostrar los elementos despues de la diagonal principal y
    // antes de la diagonal secundaria
    for (int j = i + 1; j < col - i - 1; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("    ");
    // mostrar los elementos despues de la diagonal secundaria
    for (int j = col - i; j < col; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("\n");
  }
  // iterar sobre las ultimas filas y la central
  for (int i = row / 2; i < row; i++) {
    // mostar los elementos antes de la diagonal secundaria
    for (int j = 0; j < col - i - 1; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("    ");
    // mostrar los elementos despues de la diagonal secundaria y
    // antes de la diagonal principal
    for (int j = col - i; j < i; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("    ");
    // mostrar los elementos despues de la diagonal principal
    for (int j = i + 1; j < col; j++) {
      printf("%4d", mat[i][j]);
    }
    printf("\n");
  }
}

void transponerMatriz(int row, int col, int mat[row][col]){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < i; j++){
            int aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

void mostrarMatrizEspiral(int row, int col, int mat[row][col]){
    int colIzq = 0;
    int colDer = col - 1;
    int rowTop = 0;
    int rowBottom = row - 1;

    while(colIzq < colDer && rowTop < rowBottom){
        // recorrer fila de arriba
        for(int j = colIzq; j <= colDer; j++){
            printf("%4d", mat[rowTop][j]);
        }
        rowTop++;
        // recorrer columna derecha
        for(int i = rowTop; i <= rowBottom; i++){
            printf("%4d", mat[i][colDer]);
        }
        colDer--;
        // recorrer fila de abajo
        for(int j = colDer; j >= colIzq; j--){
            printf("%4d", mat[rowBottom][j]);
        }
        rowBottom--;
        // recorrer columna izquierda
        for(int i = rowBottom; i >= rowTop; i--){
            printf("%4d", mat[i][colIzq]);
        }
        colIzq++;
    }
    if(colIzq == colDer){
        for(int i = rowTop; i <= rowBottom; i++){
            printf("%4d", mat[i][colIzq]);
        }
    } else if(rowBottom == rowTop){
        for(int j = colIzq; j <= colDer; j++){
            printf("%4d", mat[rowBottom][j]);
        }
    }
}

int multiplicarMatrices(int row1, int col1, int mat1[row1][col1], int row2, int col2, int mat2[row2][col2], int res[row1][col2]){
    for(int i = 0; i < row1; i++){
        for(int k = 0; k < col2; k++){
            res[i][k] = 0;
            for(int j = 0; j < row2; j++){
                res[i][k] += mat1[i][j] * mat2[j][k];
            }
        }
    }
}
