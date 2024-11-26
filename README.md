# CIndexer
Este projeto implementa um indexador de texto eficiente utilizando Árvores Binárias de Pesquisa (BST) em C. O sistema permite armazenar
buscar e manipular palavras em um banco de dados, oferecendo funcionalidades como busca por substring e cálculo de tempo de busca.

### Integrantes do Grupo
* Kaue Barbi
* Gustavo Almeida
* Leonardo Culler

## Instalação

**Ambiente Online:**

Recomendamos utilizar o Online GDB (ou outra plataforma similar) para executar o projeto diretamente no seu navegador.

1. **Crie um novo projeto:**
   * Acesse o Online GDB e crie um novo projeto.
2. **Crie os arquivos:**
   * Crie os seguintes arquivos:
     * `main.c`: Contém ra interface de uso.
     * `arvore.h`: Contém header da arvore onde declaramos as funções
     * `arvore.c`: Contém a logicade nossa aplicação.
3. **Cole o código:**
   * Cole o código de cada arquivo nos respectivos arquivos criados no Online GDB.
4. **Compile e execute:**
   * Utilize as opções de compilação e execução fornecidas pelo Online GDB. Normalmente, você encontrará botões ou menus para essas ações.
5. **Forneça um arquivo de entrada:**
   * Carregue o arquivo de texto que você deseja indexar para o ambiente online. O GBDe geralmente possui recursos para fazer upload de arquivos.
   * palavras.txt
  
## Uso

Após compilar o programa, execute-o no terminal. O programa apresentará um menu com as seguintes opções:

1. **Inserir uma palavra:**
   * Permite adicionar uma nova palavra ao índice.
   * O programa solicitará que você digite a palavra a ser inserida.
   
2. **Buscar uma palavra:**
   * Permite buscar uma palavra específica no índice.
   * O programa solicitará que você digite a palavra a ser buscada.
   * Caso a palavra seja encontrada, será exibida uma mensagem de sucesso. Caso contrário, será exibida uma mensagem indicando que a palavra não foi encontrada.

3. **Exibir palavras:**
   * Exibe todas as palavras armazenadas no índice, em ordem alfabética.

4. **Remover uma palavra:**
   * Permite remover uma palavra do índice.
   * O programa solicitará que você digite a palavra a ser removida.

5. **Busca especializada:**
   * Permite realizar buscas mais complexas, como buscar palavras que começam com uma determinada letra ou que contêm uma substring específica. 
   * O programa solicitará que você especifique o tipo de busca desejada.

6. **Calcular tempo de busca:**
   * Calcula o tempo médio de busca para um conjunto de palavras.
   * O programa solicitará que você digite o número de buscas a serem realizadas e as palavras a serem buscadas.

7. **Carregar palavras de um arquivo:**
   * Permite carregar um arquivo de texto contendo uma lista de palavras e inseri-las no índice.
   * O programa solicitará que você digite o nome do arquivo.

8. **Sair:**
   * Encerra o programa.
