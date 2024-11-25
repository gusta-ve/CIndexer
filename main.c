#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void exibeMenu() {
    printf("\n=========================================\n");
    printf("     Projeto C - Indexador de Texto");
    printf("\n=========================================\n");
    printf("         Indexador de Texto\n");
    printf("             Utilizando\n");
    printf("     Árvores Binárias de Pesquisa\n");
    printf("=========================================\n\n");
    printf("1️⃣  Inserir uma palavra\n");
    printf("2️⃣  Buscar uma palavra\n");
    printf("3️⃣  Exibir palavras\n");
    printf("4️⃣  Remover uma palavra\n");
    printf("5️⃣  Busca especializada\n");
    printf("6️⃣  Calcular tempo de busca\n");
    printf("7️⃣  Carregar palavras de um arquivo\n");
    printf("8️⃣  Sair\n");
    printf("\n");
    printf("=========================================\n");
    printf("👉 Escolha uma opção: ");
}

int main() {
    No* raiz = NULL;
    int opcao;
    char palavra[100];
    do {
        exibeMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("\n📝 Digite a palavra: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                if (strlen(palavra) == 0) {
                    printf("⚠ Palavra inválida! Certifique-se de que ela contém apenas letras ou números.\n");
                } else if (inserirUnico(&raiz, palavra)) {
                    printf("✅ Palavra '%s' adicionada com sucesso.\n", palavra);
                } else {
                    printf("⚠ Palavra '%s' já existe na árvore.\n", palavra);
                }
                break;
            case 2:
                printf("\n🔍 Digite a palavra a ser buscada: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                if (busca(raiz, palavra)) {
                    printf("✅ A palavra '%s' foi encontrada.\n", palavra);
                } else {
                    printf("❌ A palavra '%s' não foi encontrada.\n", palavra);
                }
                break;
            case 3:
                printf("\n📋 Palavras na árvore:\n");
                imprimeResultado(raiz);
                break;
            case 4:
                printf("\n🗑 Digite a palavra a ser removida: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                removeNo(&raiz, palavra);
                printf("✅ Palavra '%s' removida.\n", palavra);
                break;
            case 5:
                printf("\n🔎 Digite o trecho a ser buscado: ");
                scanf("%s", palavra);
                padronizacao(palavra);
                printf("📋 Resultados encontrados:\n");
                buscaEspecializada(raiz, palavra);
                break;
            case 6:
                calcularTempoBusca(raiz);
                break;
            case 7:
                carregarArquivo(&raiz);
                break;
            case 8:
                printf("\n🛑 Finalizando o programa...\n");
                break;
            default:
                printf("\n⚠ Opção inválida. Tente novamente!\n");
        }
    } while (opcao != 8);
    liberaNo(raiz);
    return 0;
}
