#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Función para generar una lista de índices randomizados
void randomizeIndices(int *indices, int n) {
    srand(time(NULL));  // Inicializa la semilla del generador de números aleatorios

    // Inicializa el array de índices
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Intercambia los elementos del array de índices de forma aleatoria
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Genera un índice aleatorio entre 0 e i (inclusive)
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }
}

int random_search(int *arr, int n, int x) {
    int *indices = malloc(n * sizeof(int));
    randomizeIndices(indices, n);

    for (int i = 0; i < n; i++) {
        if (arr[indices[i]] == x) {
            return indices[i];
        }
    }

    return -1;
}