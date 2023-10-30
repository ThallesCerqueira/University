#include <stdio.h>

void leituraMapa(Escolha vet[5][5]);
int back(Escolha vet[5][5], int i, int j);

typedef struct Escolhas
{
    int d;
    int e;
    int c;
    int b;

    int value;

} Escolha;

typedef struct fila {

    Escolha *inicio;
    Escolha *fim;

} Fila;

int main() {

    int map[5][5];
    int result;
    Escolha vet[5][5];
    int t;

    scanf("%d", t);

    if(t < 1 || t > 400) {
        return 0;
    }

    leituraMapa(vet);

   result = back(vet, 0, 0);

    return 0;

}

void leituraMapa(Escolha vet[5][5]) {

    for(int i = 0; i < 5; i++) {
        scanf("%d %d %d %d %d", &vet[i][0], &vet[i][1], &vet[i][2], &vet[i][3], &vet[i][4]);
    }

}

int back(Escolha vet[5][5], int i, int j) {

 if(vet[1][1].value == 1) {
    return 0;
 } 

    

}

