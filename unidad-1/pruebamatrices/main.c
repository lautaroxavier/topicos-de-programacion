#include <stdio.h>
#define MAX_COL 5
#define MAX_FIL 5

void __cargarMatrizEspiralCentroAIAD(int mat[][MAX_COL], int filas, int columnas, int vec[]);

int main() {
    int mat[][MAX_COL] = {
        {13, 12, 11, 10, 25},
        {14,  3,  2,  9, 24},
        {15,  4,  1,  8, 23},
        {16,  5,  6,  7, 22},
        {17, 18, 19, 20, 21},
    };
    int vec[MAX_FIL * MAX_COL];
    __cargarMatrizEspiralCentroAIAD(mat, MAX_FIL, MAX_COL, vec);
    for (int i = 0; i < MAX_FIL * MAX_COL; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}

void __cargarMatrizEspiralCentroAIAD(int mat[][MAX_COL], int filas, int columnas, int vec[]) {
    // Inicializar las variables de control
    int i = filas / 2; // Fila actual
    int j = columnas / 2; // Columna actual
    int k = 0; // Indice del vector
    int dir = 0; // Direccion actual (0: arriba, 1: izquierda, 2: abajo, 3: derecha)
    int pasos = 1; // Pasos a dar en cada direccion
    int cont = 0; // Contador de pasos dados
    int total = filas * columnas; // Total de elementos a recorrer

    // Recorrer la matriz en espiral desde el centro
    while (k < total) {
        // Cargar el elemento actual en el vector
        vec[k] = mat[i][j];
        k++;

        // Actualizar la posicion segun la direccion
        switch (dir) {
            case 0: // Arriba
                i--;
                break;
            case 1: // Izquierda
                j--;
                break;
            case 2: // Abajo
                i++;
                break;
            case 3: // Derecha
                j++;
                break;
        }

        // Incrementar el contador de pasos dados
        cont++;

        // Si se llego al limite de pasos en la direccion actual
        if (cont == pasos) {
            // Cambiar la direccion en sentido horario
            dir = (dir + 1) % 4;

            // Reiniciar el contador de pasos dados
            cont = 0;

            // Si se cambio a izquierda o derecha
            if (dir == 0 || dir == 2) {
                // Incrementar el numero de pasos a dar en la siguiente direccion
                pasos++;
            }
        }
    }
}

