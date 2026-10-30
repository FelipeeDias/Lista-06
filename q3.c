#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void normalizarVetor(const int *const p, float *const p_norm, const unsigned n) {
    int min = *p, max = *p;
    
    for (int k = 1; k < n; k++) {
        if (*(p+k) < min) min = *(p+k);
        if (*(p+k) > max) max = *(p+k);
    }
    
    for (int k = 0; k < n; k++) {
        *(p_norm+k) = (float)(*(p+k) - min) / (max - min);
    }
}

int main() {
    unsigned n = 5;
    int *x = (int *) malloc(n * sizeof(int));
    float *xl = (float *) malloc(n * sizeof(float));
    
    srand(time(NULL));
    puts("Vetor Original:");
    for (int k = 0; k < n; k++) {
        *(x+k) = rand() % 50;
        printf("[%p] %d\n", x+k, *(x+k));
    }

    normalizarVetor(x, xl, n);

    puts("\nVetor Normalizado (Min-Max):");
    for (int k = 0; k < n; k++) {
        printf("[%p] %.4f\n", xl+k, *(xl+k));
    }
    
    free(x);
    free(xl);
    return 0;
}