#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcularMSE(const int *const a, const int *const b, const unsigned n, float *const erro) {
    *erro = 0;
    for (int k = 0; k < n; k++) {
        float diff = *(a+k) - *(b+k);
        *erro += (diff * diff);
    }
    *erro /= n;
}

int main() {
    unsigned n = 5;
    int *a = (int *) malloc(n * sizeof(int));
    int *b = (int *) malloc(n * sizeof(int));
    float erro_quadratico;
    
    srand(time(NULL));
    
    for (int k = 0; k < n; k++) {
        *(a+k) = rand() % 10;
        *(b+k) = rand() % 10;
        printf("A[%d]: %d \t B[%d]: %d\n", k, *(a+k), k, *(b+k));
    }

    calcularMSE(a, b, n, &erro_quadratico);
    printf("\nErro Medio Quadratico (MSE): %.4f\n", erro_quadratico);
    
    free(a);
    free(b);
    return 0;
}