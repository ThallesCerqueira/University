#include <stdio.h>

int quantasLetras(char *string, int tam);


int main() {

    char string[100];

    scanf("%s", string);

    int qtdLetras = quantasLetras(string, 5);

}

int quantasLetras(char *string, int tam) {

    char letra;
    int flag, contador = 0, newContador = 0;
    char letrasIn[20];

    for(int i = 0; i < tam; i++) {
        letra = string[i];

        for(int j = i + 1; j < tam; j++) {

            if(letra == string[j]) {
                flag = 1;
            }

        }

        if(flag == 1) {
            letrasIn[contador];
            contador++;
        }

    }

    for(int i = 0; i < contador; i++) {

        if(string);

    }

}