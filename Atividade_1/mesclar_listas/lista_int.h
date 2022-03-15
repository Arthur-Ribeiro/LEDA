#ifndef LISTA_INT_H
#define LISTA_INT_H

#define TAM 10

typedef struct lista lista;

lista *criar_lista();

int esta_vazia(lista *l);
int esta_cheia(lista *l);
int tamanho_lista(lista *l);
void exibir_lista(lista *l);
int inserir_fim(lista *l, int e);
int remover_inicio(lista *l);
int mesclar_listas(lista *l1,lista *l2);

#endif