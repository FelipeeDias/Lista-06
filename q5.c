#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void calcularEstatisticas(int *const p, const unsigned n, int limite) {
    float soma = 0;
    for (int k = 0; k < n; k++) {
        soma += *(p+k);
    }
    printf("Media: %.2f\n", soma / n);

    int aux;
    for (int k = 0; k < n-1; k++) {
        for (int j = k+1; j < n; j++) {
            if (*(p+k) > *(p+j)) {
                aux = *(p+k);
                *(p+k) = *(p+j);
                *(p+j) = aux;
            }
        }
    }

    if (n % 2 != 0) {
        printf("Mediana: %d\n", *(p + n/2));
    } else {
        printf("Mediana: %.1f\n", (*(p + n/2 - 1) + *(p + n/2)) / 2.0);
    }

    int *f = (int *) calloc(limite, sizeof(int));
    for (int k = 0; k < n; k++) {
        *(f + *(p+k)) += 1;
    }
    
    int moda = 0, max_f = 0;
    for (int k = 0; k < limite; k++) {
        if (*(f+k) > max_f) {
            max_f = *(f+k);
            moda = k;
        }
    }
    printf("Moda: %d (aparece %d vezes)\n", moda, max_f);
    
    free(f);
}

int main() {
    unsigned n = 10;
    int limite = 20;
    int *pv = (int *) malloc(n * sizeof(int));
    
    srand(time(NULL));
    puts("Vetor gerado:");
    for (int k = 0; k < n; k++) {
        *(pv+k) = rand() % limite;
        printf("%d ", *(pv+k));
    }
    puts("\n");

    calcularEstatisticas(pv, n, limite);

    free(pv);
    return 0;
}