#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *const p, const unsigned tamanho, int limite) {
    for (int k = 0; k < tamanho; k++) {
        *(p+k) = rand() % limite;
    }
}

int main() {
    unsigned n;
    int limite = 100;
    
    puts("Qual o tamanho do vetor?");
    scanf("%u", &n);

    int *pv = (int *) malloc(n * sizeof(int));
    
    srand(time(NULL));
    popularVetor(pv, n, limite);

    for (int k = 0; k < n; k++) {
        printf("[%p] %d\n", pv+k, *(pv+k));
    }

    for (int k = 0; k < n; k++) {
        if (*(pv+k) % 2 == 0) {
            printf("\nPrimeiro elemento PAR: [%p] -> %d\n", pv+k, *(pv+k));
            break;
        }
    }
    
    free(pv);
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *const p, const unsigned tamanho, int limite) {
    for (int k = 0; k < tamanho; k++) {
        *(p+k) = rand() % limite;
    }
}

int main() {
    unsigned n;
    int limite = 100;
    
    puts("Qual o tamanho do vetor?");
    scanf("%u", &n);

    int *pv = (int *) malloc(n * sizeof(int));
    
    srand(time(NULL));
    popularVetor(pv, n, limite);

    for (int k = 0; k < n; k++) {
        printf("[%p] %d\n", pv+k, *(pv+k));
    }

    for (int k = 0; k < n; k++) {
        if (*(pv+k) % 2 == 0) {
            printf("\nPrimeiro elemento PAR: [%p] -> %d\n", pv+k, *(pv+k));
            break;
        }
    }
    
    free(pv);
    return 0;
}