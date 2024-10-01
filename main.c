#include <stdio.h>
#include <stdlib.h>

struct Node {
    int num;
    struct Node *proximo;   //ponteiro proximo
    struct Node *anterior;  //ponteiro para anterior
};

typedef struct Node node;
typedef node *LISTA;

LISTA* criarLista(){
    LISTA *inicio = (LISTA) malloc(sizeof(node)); 
    if(inicio != NULL ){
        inicio = NULL;
    }else{
        printf(" Erro de alocacao ...\n");
        exit(0);
    }
    return inicio;
}

void inserirInicio(LISTA* lista){
    node *novo = (node*) malloc(sizeof(node));
    if(novo == NULL){
        printf("Erro na alocacao ...\n");
        exit(0);
    }
    printf("Informe valor do novo elemento ...\n");
    scanf("%d",&novo->num);
    novo->proximo = (*lista);
    novo->anterior = NULL;
    if((*lista) != NULL){
        (*lista)->anterior = novo;
    }
    *lista = novo;
}

void inserirFinal(LISTA* lista){
    node *novo = (node*) malloc(sizeof(node));
    if (novo == NULL){
            printf("Erro na alocacao ..\n");
            exit(0);
    }
    printf("Informe o valor do novo elemento ...\n");
    scanf("%d",&novo->num);
    novo->proximo = NULL;
    novo->anterior = NULL;
    if((*lista) == NULL){
        *lista = novo;
    }else{
        node *tmp;
        tmp = (*lista);
        while(tmp->proximo != NULL){
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
        novo->anterior = tmp;
    }
}

// Função para exibir os elementos da lista
void exibe(LISTA* lista) { // Modificado para não usar ponteiro para lista
    if (lista == NULL) {
        printf("LISTA VAZIA ...\n");
    } else {
        node *tmp; // Nó temporário para percorrer a lista
        tmp = *lista;
        while (tmp != NULL) {
            printf(" Exibindo num -> %d \n", tmp->num); // Exibe o valor do nó
            tmp = tmp->proximo; // Vai para o próximo nó
        }
        printf("\n");
    }
}

// Função para liberar a memória utilizada pela lista
void liberaMemoria(LISTA* lista) {
    node *tmp;
    while (*lista != NULL) {
        tmp = *lista; // Nó temporário
        *lista = (*lista)->proximo; // Avança para o próximo nó
        free(tmp); // Libera a memória do nó
    }
}

// Função para remover o primeiro elemento da lista
void removeInicio(LISTA* lista) {
    if (*lista != NULL) {
        node *tmp;
        tmp = *lista;// Nó temporário
        *lista = tmp->proximo; // Atualiza o início da lista

        if (*lista != NULL) {
            (*lista)->anterior = NULL; // Atualiza o anterior do novo início
        }

        printf(" Removendo no com num = %d da lista \n",tmp->num);
        free(tmp); // Libera a memória do nó removido
        printf(" Elemento removido com sucesso ...\n");
    } else {
        printf("Lista já está vazia ...\n");
    }
}

// Função para remover o último elemento da lista
void removeFinal(LISTA* lista) {
    if (*lista == NULL) {
        printf("Lista já está vazia ...\n");
        return;
    }

    node *tmp;
    tmp = *lista;
    if (tmp->proximo == NULL) { // Se houver apenas um nó
        *lista = NULL; // Lista fica vazia
        printf(" Removendo no com num = %d da lista \n",tmp->num);
        free(tmp); // Libera a memória
        printf("Elemento removido com sucesso ...\n");
        return;
    }
    // Se houver mais de um nó
    node *antNode;
    while (tmp->proximo != NULL) { // Encontra o penúltimo nó
        antNode = tmp;
        tmp = tmp->proximo;
    }

    antNode->proximo = NULL; // Atualiza o penúltimo nó para não ter próximo
    free(tmp); // Libera a memória do último nó
    printf("Elemento removido com sucesso ...\n");
}

// Função para buscar e exibir o resultado da busca
void buscarEExibir(LISTA* lista) {
    int valor;
    printf("Informe o valor a ser buscado : \n  ");
    scanf("%d", &valor);

    node *resultado = NULL;// NULL se o valor não for encontrado
    node *tmp = *lista;
    while (tmp != NULL) {
        if (tmp->num == valor) {
            resultado = tmp; // Retorna o nó que contém o valor
        }
        tmp = tmp->proximo; // Vai para o próximo nó
    }

    if (resultado != NULL) {
        printf("Valor %d encontrado na lista.\n", valor);
    } else {
        printf("Valor %d nao encontrado na lista.\n", valor);
    }
} 

int main(){
  int esc;
  LISTA *lista = criarLista();

  do {
    printf("Digite a operação desejada: \n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no final\n");
    printf("3. Exibir lista\n");
    printf("4. Liberar memoria\n");
    printf("5. Remover do inicio\n");
    printf("6. Remover do final\n");
    printf("7. Buscar e exibir\n");
    printf("0. Sair\n");

    scanf("%d", &esc);

    switch (esc) {
      case 1:
        inserirInicio(&lista);
        break;
      case 2:
        inserirFinal(&lista);
        break;
      case 3:
        exibe(&lista);
        break;
      case 4:
        liberaMemoria(&lista);
        break;
      case 5:
        removeInicio(&lista);
        break;
      case 6:
        removeFinal(&lista);
        break;
      case 7:
        buscarEExibir(&lista);
        break;
      case 0:
        printf("Saindo do programa ...\n");
        exit(0);
        break;
      default:
        printf("Opção inválida. Tente novamente.\n");
        break;
    }
  } while (esc != 0); 
}