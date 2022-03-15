#ifndef LISTA_LINEAR_SEQUENCIAL_INTEIROS_H
#define LISTA_LINEAR_SEQUENCIAL_INTEIROS_H

#define TAM 100

typedef struct lista lista;
typedef struct celula celula;

lista* criar_lista();

int inserir_fim(lista *l, int e);
int ponto_mais_longe(lista *l);
int tamanho_lista(lista *l);
int esta_vazia(lista *l);
void exibir_lista(lista *l);
int soma(lista *l, int res);
int exibir_recursivamente(lista *l, int pos);

#endif //LISTA_LINEAR_SEQUENCIAL_INTEIROS
