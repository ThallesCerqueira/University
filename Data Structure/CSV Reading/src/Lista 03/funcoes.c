#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#define TRUE 1
#define FALSE 0

Jogos *criaAcervo( int capacidade ) {

    Jogos *acervo;

    acervo = (Jogos*) malloc((capacidade + 1) * sizeof(Jogos));

    return acervo;
}

Jogos *carregaDados(char *fileName, int *tam) {

    int i = 0;
    char sep[1], str[2000], *ok;
    sep[0] = ',';
    Jogos *acervo;
    FILE *fp;
    fp = fopen(fileName, "r");
    acervo = criaAcervo(*tam);

    if(fp == NULL) {
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    ok = fgets(str, 2000, fp); //Pega cabeçalho

    if (!ok) {
        printf("Erro ao o cabeçalho do CSV!!!");
        exit(1);
    }

    while(!feof(fp) && i < *tam) {
        ok = fgets(str, 2000, fp); // pega a linha do CSV

        if(ok) {
            char *campo;

            // APP ID
            campo = strtok(str, sep); // pega a string até a primeira ','
            acervo[i].appId = atoi(campo);

            // TITLE
            campo = strtok(NULL, sep);
            int pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].title = (char *) malloc( strlen(campo));
            strcpy(acervo[i].title, campo);

            // Data release
            campo = strtok(NULL, sep);
            pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].dataRelease = (char *)malloc(strlen(campo));
            strcpy(acervo[i].dataRelease, campo);

            // WINDOWS
            campo = strtok(NULL, sep);
            acervo[i].win = (char *)malloc(strlen(campo));
            strcpy(acervo[i].win, campo);

            // MAC
            campo = strtok(NULL, sep);
            acervo[i].mac = (char *)malloc(strlen(campo));
            strcpy(acervo[i].mac, campo);

            // LINUX
            campo = strtok(NULL, sep);
            acervo[i].linux = (char *)malloc(strlen(campo));
            strcpy(acervo[i].linux, campo);

            // RATING
            campo = strtok(NULL, sep);
            pos = 0;
            while (campo[pos] != 15 && pos < strlen(campo))
                pos++;
            campo[pos] = '\0';
            acervo[i].rating = (char *)malloc(strlen(campo));
            strcpy(acervo[i].rating, campo);

            // POSITIVE RATIO
            campo = strtok(NULL, sep);
            acervo[i].positiveRatio = atoi(campo);

            // USER REVIEWS
            campo = strtok(NULL, sep);
            acervo[i].userReviews = atoi(campo);

            // PRICE FINAL
            campo = strtok(NULL, sep);
            acervo[i].priceFinal = atof(campo);

            // PRICE ORIGINAL
            campo = strtok(NULL, sep);
            acervo[i].priceOriginal = atof(campo);

            // DISCOUNT
            campo = strtok(NULL, sep);
            acervo[i].discount = atof(campo);

            i++;
        }
    }

    return acervo;
}

int buscaPorId(int idDoApp, Jogos *lista, int tam) {

    lista[tam].appId = idDoApp;

    int cont = 0;

    while (cont < tam) {

        if (lista[cont].appId == idDoApp) return cont;

        cont++;
    }

    return tam;
    
}

void limpaAcervo(Jogos *acervo, int tamanhoAcervo) {

    for (int i = 0; i < tamanhoAcervo; i++) {
        free(acervo[i].title);
        free(acervo[i].dataRelease);
        free(acervo[i].win);
        free(acervo[i].mac);
        free(acervo[i].linux);
        free(acervo[i].rating);
    }
    
    free(acervo);
}

int incRegistro(Jogos origem, Jogos* destino, int* tam) {

    if( buscaPorId(origem.appId, destino, *tam) == *tam ) { 
        
        destino[*tam].title  = (char*)malloc((strlen(origem.title)));
        strcpy(destino[*tam].title, origem.title); 
        
        destino[*tam].dataRelease  = (char*)malloc(strlen(origem.dataRelease));
        strcpy(destino[*tam].dataRelease, origem.dataRelease);
        
        destino[*tam].win  = (char*)malloc(strlen(origem.win));
        strcpy(destino[*tam].win, origem.win);

        destino[*tam].mac  = (char*)malloc(strlen(origem.mac));
        strcpy(destino[*tam].mac, origem.mac);

        destino[*tam].linux  = (char*)malloc(strlen(origem.linux));
        strcpy(destino[*tam].linux, origem.linux);

        destino[*tam].rating  = (char*)malloc(strlen(origem.rating));
        strcpy(destino[*tam].rating, origem.rating);

        destino[*tam].positiveRatio = origem.positiveRatio;
        destino[*tam].userReviews = origem.userReviews;
        destino[*tam].priceFinal = origem.priceFinal;
        destino[*tam].priceOriginal = origem.priceOriginal;
        destino[*tam].discount = origem.discount;

        *tam = *tam + 1;
    
        return 1;

    }

   return 0;

}

int remRegistro( int idDoApp, Jogos* lista, int* tam ) {

    int posicao = buscaPorId(idDoApp, lista, *tam);

    if( posicao < *tam ) {
        
        lista[posicao] = lista[*tam - 1];
        
        *tam = *tam - 1;

        return 1;
    }

    return 0;
}

int buscaBinPorId(int idProcurado, Jogos* lista, int tam) {
    int inicio = 0;
    int fim = tam - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (lista[meio].appId == idProcurado) {
            return meio;
        } else if (lista[meio].appId < idProcurado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int incOrdRegistro(Jogos origem, Jogos* destino, int* tam) {

    int i, j;
    int posicao;
    int retorno = buscaBinPorId(origem.appId, destino, *tam);

    if(retorno < 0 && *tam > 0) {
        for (i = 0; i < *tam; i++){
            if (origem.appId > destino[i].appId){
                posicao = i;
                break;
            }
        }
    }else if(*tam == 0) posicao = 0;

    if (retorno < 0) {
       
       //A capacidade já está sendo tratada na main, ou seja, tamanho < capacidade.
        if(*tam > 0) 
            for (j = *tam - 1; j >= posicao; j--)
                destino[j+1] = destino[j]; //Movendo os maiores para a direita

        destino[posicao].appId = origem.appId;

        destino[posicao].title  = (char*)malloc((strlen(origem.title) + 1));
        strcpy(destino[posicao].title, origem.title); 
        
        destino[posicao].dataRelease  = (char*)malloc(strlen(origem.dataRelease));
        strcpy(destino[posicao].dataRelease, origem.dataRelease);
        
        destino[posicao].win  = (char*)malloc(strlen(origem.win));
        strcpy(destino[posicao].win, origem.win);

        destino[posicao].mac  = (char*)malloc(strlen(origem.mac));
        strcpy(destino[posicao].mac, origem.mac);

        destino[posicao].linux  = (char*)malloc(strlen(origem.linux));
        strcpy(destino[posicao].linux, origem.linux);

        destino[posicao].rating  = (char*)malloc(strlen(origem.rating));
        strcpy(destino[posicao].rating, origem.rating);

        destino[posicao].positiveRatio = origem.positiveRatio;
        destino[posicao].userReviews = origem.userReviews;
        destino[posicao].priceFinal = origem.priceFinal;
        destino[posicao].priceOriginal = origem.priceOriginal;
        destino[posicao].discount = origem.discount;
        
        *tam = *tam + 1;

        return TRUE;
    }

    return FALSE;
}

int remOrdRegistro(int idARemover, Jogos* lista, int* tam){

    int pos = buscaBinPorId(idARemover, lista, *tam);

    if(pos != -1) {

        for( int i = pos; i < *tam; i++) lista[pos] = lista[pos+1];
        
        *tam = *tam - 1;

        return TRUE;
    }
    return FALSE;
}

void inicializaListaLinear(TListaLinear* linear, int capacidade, int isOrdenada) {
    
    if(isOrdenada == 1){
        linear->lista = (Jogos*) malloc(capacidade * sizeof(Jogos));
    }else{
        linear->lista = (Jogos*) malloc((capacidade + 1) * sizeof(Jogos));
    }

    linear->capacidade = capacidade;
    linear->tamanho = 0;
    linear->isOrdenada = isOrdenada;

}

TListaLinear* criaListaLinear(int capacidade, int isOrdenada){
    TListaLinear* ListaLinear;

    ListaLinear = (TListaLinear*) malloc(sizeof(TListaLinear));
    inicializaListaLinear(ListaLinear, capacidade, isOrdenada);

    return ListaLinear;
}

int buscaNaLista(int idProcurado, TListaLinear* linear){

    if(linear->isOrdenada == 1) return buscaBinPorId(idProcurado, linear->lista, linear->tamanho);
    
    return buscaPorId(idProcurado, linear->lista, linear->tamanho);

}

int insereNaLista(Jogos jogo, TListaLinear* linear){

    if(linear->isOrdenada == 1) return incOrdRegistro(jogo, linear->lista, &linear->tamanho);

    return incRegistro( jogo, linear->lista, &linear->tamanho);

}

int isEmpty(TListaLinear* linear){
    
    if(linear->tamanho == 0) return 1;
    
    return 0;
}

int removeDaLista(int idARemover, TListaLinear* linear){

    if( isEmpty(linear) ) return 0;

    if(linear->isOrdenada == 1){

        return remOrdRegistro( idARemover,linear->lista, &linear->tamanho );

    }

    return remRegistro( idARemover, linear->lista, &linear->tamanho );
    
}