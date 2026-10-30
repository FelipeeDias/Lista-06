#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void verificarDiagonal(const int *const m, const unsigned n) {
    int soma = 0;
    for (int k = 0; k < n; k++) {
        soma += *(m + k * n + k); 
    }
    
    printf("\nSomatorio da diagonal principal: %d\n", soma);
    if (soma % 2 == 0) {
        puts("O resultado e PAR.");
    } else {
        puts("O resultado e IMPAR.");
    }
}

int main() {
    unsigned n;
    puts("Dimensao N da matriz (NxN): ");
    scanf("%u", &n);

    int *matriz = (int *) malloc(n * n * sizeof(int));
    
    srand(time(NULL));
    
    puts("\nMatriz gerada:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(matriz + i * n + j) = rand() % 10;
            printf("%d\t", *(matriz + i * n + j));
        }
        printf("\n");
    }

    verificarDiagonal(matriz, n);
    
    free(matriz);
    return 0;
}