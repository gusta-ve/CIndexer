#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void exibirMenuPrincipal() {
    printf("\n========================================\n");
    printf("\n     Projeto C - Software Indexador     \n");
    printf("\n========================================\n");
    printf("         Indexador de Texto                 \n");
    printf("            Utilizando                      \n");
    printf("     Árvores Binárias de Pesquisa           \n");
    printf("========================================\n");
    printf("  ➤ [1] Inserir uma palavra\n");
    printf("  ➤ [2] Buscar uma palavra\n");
    printf("  ➤ [3] Exibir palavras\n");
    printf("  ➤ [4] Remover uma palavra\n");
    printf("  ➤ [5] Busca especializada\n");
    printf("  ➤ [6] Carregar palavras de um arquivo\n");
    printf("  ➤ [7] Exibir quantidade de palavras\n");
    printf("  ➤ [8] Sair");
    
    printf("\n========================================\n");
    printf("Digite a opção desejada:");
}

void processarEscolha(int escolha, No** raiz) {
    char palavra[100];
    switch (escolha) {
        case 1:
            printf("\nDigite a palavra para adicionar: ");
            scanf("%s", palavra);
            padronizarPalavra(palavra);
            if (strlen(palavra) == 0) {
                printf("A palavra está vazia ou contém caracteres inválidos!\n");
            } else if (inserirPalavraUnica(raiz, palavra)) {
                printf("Palavra '%s' foi adicionada com sucesso.\n", palavra);
            } else {
                printf("A palavra '%s' já está no índice.\n", palavra);
            }
            break;
        case 2:
            printf("\nDigite a palavra que deseja procurar: ");
            scanf("%s", palavra);
            padronizarPalavra(palavra);
            if (buscarPalavra(*raiz, palavra)) {
                printf("A palavra '%s' foi encontrada no índice.\n", palavra);
            } else {
                printf("A palavra '%s' não foi encontrada.\n", palavra);
            }
            break;
        case 3:
            printf("\nListando todas as palavras no índice:\n");
            listarPalavras(*raiz);
            break;
        case 4:
            printf("\nDigite a palavra que deseja remover: ");
            scanf("%s", palavra);
            padronizarPalavra(palavra);
            removerPalavra(raiz, palavra);
            printf("Palavra '%s' removida com sucesso.\n", palavra);
            break;
        case 5:
            printf("\nDigite o trecho de palavra para buscar: ");
            scanf("%s", palavra);
            padronizarPalavra(palavra);
            printf("Resultados encontrados para '%s':\n", palavra);
            buscarPorTrecho(*raiz, palavra);
            break;
        case 6:
            printf("\nDigite o nome do arquivo para carregar as palavras(com a extensão de arquivo):");
            char nomeArquivo[100];
            scanf("%s", nomeArquivo);
            carregarPalavrasDeArquivo(raiz, nomeArquivo);
            break;
        case 7:
            printf("\nQuantidade de palavras no índice: %d\n", contarQuantidadeNos(*raiz));
            break;
        case 8:
            printf("\nSaindo do sistema... Até logo!\n");
            break;
        default:
            printf("\nOpção inválida. Por favor, tente novamente.\n");
    }
}

int main() {
    No* raiz = NULL;
    int escolha;

    do {
        exibirMenuPrincipal();
        scanf("%d", &escolha);
        processarEscolha(escolha, &raiz);
    } while (escolha != 8);

    liberarMemoria(raiz);
    return 0;
}
