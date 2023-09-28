#include <stdio.h>

void printVet(int *vet, int tam);

int main() {

    int i, j, tam, key, vet[5];

    vet[0] = 5;
    vet[1] = 4;
    vet[2] = 3;
    vet[3] = 2;
    vet[4] = 1;

    tam = 5;

    printVet(vet, tam);

    for( j = 2; j < tam; j++) {

        key = vet[j]; // 3

        i = j - 1; // 1

        while( i > 0 && vet[i] > key ) {
            vet[i+1] = vet[i];
            i--;
        }

        vet[i+1] = key;


    }

    printf("\n");
    printVet(vet, tam);


    return 0;
}

void printVet(int *vet, int tam) {
    printf("[");
    for(int i = 0; i < tam; i++) {
        
        printf("%d, ", vet[i]);
        
    }

    printf("]");
}