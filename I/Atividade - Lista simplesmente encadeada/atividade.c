/*
Faça um sistema para gerenciar os produtos (código, nome e preço) de um supermercado utilizando uma lista simplesmente encadeada, apresentando ao usuário as seguintes opções:

  1- Cadastrar produto

  2- Exibir a lista de produtos

  3- Buscar um produto

  4- Remover um produto

  5- Sair

Você deve implementar procedimentos e/ou funções para as funcionalidades de uma lista encadeada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Produto {
  int cod;
  char nome[50];
  float preco;
  struct Produto * prox;
  struct Produto * inicio;
}
Produto;

Produto * inicio;

void cadastrar(int codigo, char name[50], float precos) {
  Produto * novo;
  novo = (Produto * ) malloc(sizeof(Produto));
  if (novo != NULL) {
    novo -> cod = codigo;
    strcpy(novo -> nome, name);
    novo -> preco = precos;
    novo -> prox = inicio;
    inicio = novo;
  }
}

void exibir() {
  if (inicio != NULL) {
    Produto * aux;
    aux = inicio;
    while (aux != NULL) {
      printf("\nCódigo: %d", aux -> cod);
      printf("\nNome: %s", aux -> nome);
      printf("\nPreço: %.2f\n\n", aux -> preco);
      inicio = inicio -> prox;
      aux = inicio;
    }
  }
}

void busca(int codigo) {
  if (inicio != NULL) {
    Produto * aux;
    aux = inicio;
    while (aux != NULL) {
      if (aux -> cod == codigo) {
        printf("\nCódigo: %d", aux -> cod);
        printf("\nNome: %s", aux -> nome);
        printf("\nPreço: %.2f\n\n", aux -> preco);
      }
      aux = aux -> prox;
    }
  } else {
    printf("\nLista vazia!");
  }
}

void remover(int codigo) {
  Produto * ant = NULL;
  Produto * aux = inicio;
  if (inicio != NULL) {
    while (aux != NULL && aux -> cod != codigo) {
      ant = aux;
      aux = aux -> prox;
    }
    if (aux == NULL) {
      printf("Elemento não encontrado!");
    } else {
      if (ant == NULL) {
        inicio = aux -> prox;
      } else {
        ant -> prox = aux -> prox;
        free(aux);
      }
    }
  }
}

int main() {

  setlocale(LC_ALL,"Portuguese");

  Produto * p = malloc(sizeof(Produto));

  int o, codigo;
  float preco;
  char nome[50];

  printf("1 - Cadastrar produto\n2 - Exibir a lista de produtos (esta ação esvaziará a lista)\n3 - Buscar um produto\n4 - Remover um produto\n5 - Sair\n");
  scanf("%d", & o);

  while (o != 5) {

    switch (o) {
    case 1:
      printf("\nDigite o código: ");
      scanf("%d", & codigo);
      printf("Digite o nome: ");
      scanf("%s", & nome);
      printf("Digite o preço: ");
      scanf("%f", & preco);
      cadastrar(codigo, nome, preco);
      break;
    case 2:
      exibir();
      break;
    case 3:
      printf("\nDigite o código: ");
      scanf("%d", & codigo);
      busca(codigo);
      break;
    case 4:
      printf("\nDigite o código: ");
      scanf("%d", & codigo);
      remover(codigo);
      break;
    case 5:
      break;
    default:
      printf("\nDigite um número válido.\n\n");
    }
    printf("\n1 - Cadastrar produto\n2 - Exibir a lista de produtos (esta ação esvaziará a lista)\n3 - Buscar um produto\n4 - Remover um produto\n5 - Sair\n");
    scanf("%d", & o);
  }
  printf("\nEncerrando...");
  
  getch();
  return 0;
}
