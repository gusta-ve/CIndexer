#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

No* criarNovoNo(char* palavra) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo) {
        strcpy(novo->palavra, palavra);
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

No* adicionarNo(No* raiz, char* palavra) {
    if (raiz == NULL) {
        return criarNovoNo(palavra);
    }
    if (strcmp(palavra, raiz->palavra) < 0) {
        raiz->esquerda = adicionarNo(raiz->esquerda, palavra);
    } else if (strcmp(palavra, raiz->palavra) > 0) {
        raiz->direita = adicionarNo(raiz->direita, palavra);
    }
    return raiz;
}

int inserirPalavraUnica(No** raiz, char* palavra) {
    if (*raiz == NULL) {
        *raiz = criarNovoNo(palavra);
        return 1;
    }
    int cmp = strcmp(palavra, (*raiz)->palavra);
    if (cmp < 0) {
        return inserirPalavraUnica(&(*raiz)->esquerda, palavra);
    } else if (cmp > 0) {
        return inserirPalavraUnica(&(*raiz)->direita, palavra);
    }
    return 0;
}

bool buscarPalavra(No* raiz, char* palavra) {
    clock_t inicio = clock();

    if (raiz == NULL) {
        return false;
    }
    int cmp = strcmp(palavra, raiz->palavra);
    if (cmp == 0) {
        clock_t fim = clock();
        double tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Tempo de busca: %.6f segundos.\n", tempoGasto);
        return true;
    } else if (cmp < 0) {
        return buscarPalavra(raiz->esquerda, palavra);
    } else {
        return buscarPalavra(raiz->direita, palavra);
    }
}

void buscarPorTrecho(No* raiz, char* trecho) {
    if (raiz != NULL) {
        buscarPorTrecho(raiz->esquerda, trecho);
        if (strstr(raiz->palavra, trecho) != NULL) {
            printf("- %s\n", raiz->palavra);
        }
        buscarPorTrecho(raiz->direita, trecho);
    }
}

void removerPalavra(No** raiz, char* palavra) {
    if (*raiz == NULL) return;
    int cmp = strcmp(palavra, (*raiz)->palavra);
    if (cmp < 0) {
        removerPalavra(&(*raiz)->esquerda, palavra);
    } else if (cmp > 0) {
        removerPalavra(&(*raiz)->direita, palavra);
    } else {
        if ((*raiz)->esquerda == NULL) {
            No* temp = (*raiz)->direita;
            free(*raiz);
            *raiz = temp;
        } else if ((*raiz)->direita == NULL) {
            No* temp = (*raiz)->esquerda;
            free(*raiz);
            *raiz = temp;
        } else {
            No* temp = (*raiz)->direita;
            while (temp->esquerda != NULL) {
                temp = temp->esquerda;
            }
            strcpy((*raiz)->palavra, temp->palavra);
            removerPalavra(&(*raiz)->direita, temp->palavra);
        }
    }
}

void listarPalavras(No* raiz) {
    if (raiz != NULL) {
        listarPalavras(raiz->esquerda);
        printf("- %s\n", raiz->palavra);
        listarPalavras(raiz->direita);
    }
}

void liberarMemoria(No* raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->esquerda);
        liberarMemoria(raiz->direita);
        free(raiz);
    }
}

int contarQuantidadeNos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + contarQuantidadeNos(raiz->esquerda) + contarQuantidadeNos(raiz->direita);
}

void padronizarPalavra(char* palavra) {
    int i, j = 0;
    char temp[strlen(palavra) + 1];
    for (i = 0; palavra[i] != '\0'; i++) {
        char c = palavra[i];
        if (strchr("áàâãä", c)) c = 'a';
        else if (strchr("éèêë", c)) c = 'e';
        else if (strchr("íìîï", c)) c = 'i';
        else if (strchr("óòôõö", c)) c = 'o';
        else if (strchr("úùûü", c)) c = 'u';
        else if (c == '\xE7') c = 'c'; // Unicode para 'ç'
        
        if (isalnum(c)) {  // Permitir apenas alfanuméricos (letras e números)
            temp[j++] = tolower(c); // Converte para minúscula
        }
    }
    temp[j] = '\0';
    strcpy(palavra, temp);
}

void carregarPalavrasDeArquivo(No** raiz, char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    char palavra[100];
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        padronizarPalavra(palavra);
        inserirPalavraUnica(raiz, palavra);
    }
    fclose(arquivo);
}
