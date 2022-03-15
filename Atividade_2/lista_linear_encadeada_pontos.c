#include <stdlib.h>
#include <stdio.h>

#include "lista_linear_encadeada_pontos.h"


#define VERDADEIRO 1
#define FALSO 0
#define FLAG_ERRO -1

typedef struct celula{
    ponto *pto;
    struct celula *prox;
};

struct lista{
    unsigned int qtde;
    celula *primeiro;
};

Lista *criar_lista(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l == NULL)
        return NULL;
    l->qtde = 0;
    l->primeiro = NULL;
    return l;
}

int esta_vazia(Lista *l){
    if (l == NULL)
        return FLAG_ERRO;
    return l->qtde == 0;
}

int esvaziar_lista(Lista *l){
    if (l == NULL || esta_vazia(l))
        return FALSO;

    while (!esta_vazia(l))
        remover_inicio(l);

    return VERDADEIRO;
}

void exibir_lista(Lista *l){
    if (l == NULL)
        return;
    celula *temp = l->primeiro;
    while (temp != NULL){
        exibir_pto(temp->pto);
        if (temp->prox != NULL)
            printf(" -> ");
        temp = temp->prox;
    }
}

int inserir_inicio(Lista *l, ponto *p){
    if (l == NULL || p == NULL)
        return FALSO;

    celula *novo = (celula *)malloc(sizeof(celula));
    novo->pto = p;
    novo->prox = l->primeiro;
    l->primeiro = novo;
    l->qtde++;

    return VERDADEIRO;
}

int inserir_meio(Lista *l, ponto *p, unsigned int k){
    if (l == NULL || k > l->qtde + 1 || k < 1)
        return FALSO;
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->pto = p;
    nova->prox = NULL;

    if (k == 1){
        nova->prox = l->primeiro;
        l->primeiro = nova;
    }
    else{
        celula *temp = l->primeiro;
        int i;
        for (i = 2; i < k; i++)
            temp = temp->prox;

        nova->prox = temp->prox;
        temp->prox = nova;
    }

    l->qtde++;
    return VERDADEIRO;
}

int inserir_fim(Lista *l, ponto *p){
    if (l == NULL)
        return FALSO;

    celula *nova = (celula *)malloc(sizeof(celula));
    nova->pto = p;
    nova->prox = NULL;
    if (esta_vazia(l)){
        l->primeiro = nova;
    }
    else{
        celula *temp = l->primeiro->prox;
        while (temp->prox != NULL)
            temp = temp->prox;

        temp->prox = nova;
    }
    l->qtde++;

    return VERDADEIRO;
}

void liberar_lista(Lista **l){
    if (l == NULL)
        return;

    esvaziar_lista(*l);
    free(*l);
    *l = NULL;
}

int remover_inicio(Lista *l){
    if (l == NULL || esta_vazia(l))
        return FALSO;

    celula *temp = l->primeiro;
    l->primeiro = l->primeiro->prox;

    free(temp);

    l->qtde--;
    return VERDADEIRO;
}

int remover_meio(Lista *l, unsigned int k){
    if (l == NULL || esta_vazia(l) || k > tamanho(l))
        return FALSO;

    celula *temp = l->primeiro;
    if (k == 1){
        if (temp->prox == NULL)
            l->primeiro = NULL;
        else
            l->primeiro = temp->prox;
        free(temp);
    }
    else{
        int i;
        for (i = 2; i < k; i++)
            temp = temp->prox;

        celula *a_ser_removida = temp->prox;
        temp->prox = a_ser_removida->prox;
        free(a_ser_removida);
    }

    l->qtde--;
    return VERDADEIRO;
}

int remover_fim(Lista *l){
    if (l == NULL || esta_vazia(l))
        return FALSO;

    if (l->primeiro->prox == NULL){
        free(l->primeiro);
        l->primeiro = NULL;
    }
    else{
        celula *anterior = l->primeiro;
        celula *posterior = l->primeiro->prox;
        while (posterior->prox != NULL){
            anterior = posterior;
            posterior = posterior->prox;
        }
        free(posterior);
        anterior->prox = NULL;
    }

    l->qtde--;
}

int tamanho(Lista *l){
    if (l == NULL)
        return FLAG_ERRO;
    return l->qtde;
}

int buscar_ponto(Lista *l, ponto *p){
    int contador = 0;
    if (esta_vazia(l))
        return FALSO;

    celula *temp = l->primeiro;
    while (temp != NULL){
        contador++;
        if (temp->pto->x == p->x && temp->pto->y == p->y){
            printf("SIM e esta na posicao %d",contador);
            return VERDADEIRO;
        }
        temp = temp->prox;
    }

    return 0;
}