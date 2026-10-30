#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void somarVetorFloat(const float *const p, const unsigned n, float *const pres) {
    *pres = 0;
    for (int k = 0; k < n; k++) {
        *pres += *(p+k);
    }
}

int main() {
    unsigned n = 5;
    float *pv = (float *) malloc(n * sizeof(float));
    float somatorio = 0;
    
    srand(time(NULL));
    
    for (int k = 0; k < n; k++) {
        *(pv+k) = ((float) rand() / RAND_MAX) * 100.0;
        printf("[%p] %.2f\n", pv+k, *(pv+k));
    }

    somarVetorFloat(pv, n, &somatorio);

    printf("\nSomatorio: %.2f\n", somatorio);
    
    free(pv);
    return 0;
}