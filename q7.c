#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarizarMatriz(const int *const m, int *const s, const unsigned lin, const unsigned col, int t) {
    for (int k = 0; k < lin * col; k++) {
        *(s+k) = (*(m+k) > t) ? 1 : 0;
    }
}

int main() {
    unsigned lin = 3, col = 3;
    int limiar = 5;
    
    int *m = (int *) malloc(lin * col * sizeof(int));
    int *s = (int *) malloc(lin * col * sizeof(int));
    
    srand(time(NULL));
    
    puts("Matriz M:");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            *(m + i * col + j) = rand() % 10;
            printf("%d\t", *(m + i * col + j));
        }
        printf("\n");
    }

    binarizarMatriz(m, s, lin, col, limiar);

    printf("\nMatriz S (Limiar t = %d):\n", limiar);
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", *(s + i * col + j));
        }
        printf("\n");
    }
    
    free(m);
    free(s);
    return 0;
}