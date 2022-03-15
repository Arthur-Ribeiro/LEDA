#ifndef LISTA_ENCADEADA_PONTOS_H
#define LISTA_ENCADEADA_PONTOS_H


#include "tad_ponto/tad_ponto.h"

typedef struct lista Lista;
typedef struct celula celula;

Lista *criar_lista();
int esta_vazia(Lista *l);
int esvaziar_lista(Lista *l); 
void exibir_lista(Lista *l);
int inserir_inicio(Lista *l, ponto *p);
int inserir_meio(Lista* l, ponto *p, unsigned int k); 
int inserir_fim(Lista* l, ponto* p); 
void liberar_lista(Lista** l); 
int remover_inicio(Lista* l); 
int remover_meio(Lista* l, unsigned int k); 
int remover_fim(Lista* l); 
int tamanho(Lista *l);
int buscar_ponto(Lista *l, ponto *p);

#endif //LISTA_ENCADEADA_PONTOS
