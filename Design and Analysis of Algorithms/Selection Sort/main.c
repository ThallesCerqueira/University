#include <stdio.h>

void printVetor(int *vet, int tam);

int main() {

    int vet[5], tam = 6, menor, aux;

    printf("Entre com os valores!\n");


    for(int i = 0; i < tam; i++) {

        printf("Vet[%d]: ", i);
        scanf("%d", &vet[i]);

    }

    printVetor(vet, tam);

    for(int i = 0; i < tam - 1; i++) {
        
        for(int j = i; j < tam; j++) {
            if(vet[j+1] < vet[j]) {
                menor = j + 1;
            }
        }

        aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;

    }

    printVetor(vet, tam);

    return 0;

}

void printVetor( int *vet, int tam ) {

    printf("[");

    for(int i = 0; i < tam; i++) {
        printf("%d, ", vet[i]);
    }
    
    printf("]\n");

}