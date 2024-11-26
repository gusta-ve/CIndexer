#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>

typedef struct No {
    char palavra[100];
    struct No* esquerda;
    struct No* direita;
} No;

// declaração das funções
No* criarNovoNo(char* palavra);
No* adicionarNo(No* raiz, char* palavra);
int inserirPalavraUnica(No** raiz, char* palavra);
bool buscarPalavra(No* raiz, char* palavra);
void buscarPorTrecho(No* raiz, char* trecho);
void removerPalavra(No** raiz, char* palavra);
void listarPalavras(No* raiz);
void liberarMemoria(No* raiz);
int contarQuantidadeNos(No* raiz);
void padronizarPalavra(char* palavra);
void carregarPalavrasDeArquivo(No** raiz, char* nomeArquivo);

#endif
