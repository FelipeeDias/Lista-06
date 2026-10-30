#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *const p, const unsigned tamanho, int limite) {
    for (int k = 0; k < tamanho; k++) {
        *(p+k) = rand() % limite;
    }
}

void buscarExtremosPares(const int *const p, const unsigned n, int **resp) {
    resp[0] = NULL;
    resp[1] = NULL;
    
    for (int k = 0; k < n; k++) {
        if (*(p+k) % 2 == 0) {
            if (resp[0] == NULL) {
                resp[0] = (int *)(p+k); 
            }
            resp[1] = (int *)(p+k); 
        }
    }
}

int main() {
    unsigned n = 10;
    int *pv = (int *) malloc(n * sizeof(int));
    
    srand(time(NULL));
    popularVetor(pv, n, 100);

    for (int k = 0; k < n; k++) {
        printf("[%p] %d\n", pv+k, *(pv+k));
    }

    int *enderecos[2];
    buscarExtremosPares(pv, n, enderecos);

    if (enderecos[0] != NULL) {
        printf("\nPrimeiro PAR: [%p] -> %d\n", enderecos[0], *enderecos[0]);
        printf("Ultimo PAR: [%p] -> %d\n", enderecos[1], *enderecos[1]);
    } else {
        puts("Nenhum numero par encontrado.");
    }
    
    free(pv);
    return 0;
}