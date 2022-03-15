#include <stdlib.h>
#include <stdio.h>
#include "abb_enc.h"

#define N 100
#define FALSO 0
#define VERDADEIRO 1
#define FLAG_ERRO -1

// ==================================================== FUNÇÕES ÁRVORES ==================================================== //

struct no {
    int dado;
    no *esq;    // sae
    no *dir;    // sad
};

struct arv {
    no *raiz;
};

int adicionar_no_arv(arvore* a, int valor) {
    if(a == NULL)
        return FALSO;
    no *temp = a->raiz;
    while(temp != NULL) {
        if(valor <= temp->dado) {
            if(temp->esq == NULL) {
                temp->esq = criar_no(valor);
                break;
            }
            temp = temp->esq;
        } else {
            if(temp->dir == NULL) {
                temp->dir = criar_no(valor);
                break;
            }
            temp = temp->dir;
        }
    }
    return VERDADEIRO;
}

arvore* criar_arv(int valor_raiz) {
    arvore *a = (arvore*) malloc(sizeof(arvore));
    if(a == NULL)
        return NULL;

    no *raiz = (no*) criar_no(valor_raiz);
    if(raiz != NULL)
        a->raiz = raiz;
    else
        return NULL;
    return a;
}

no* criar_no(int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if(novo == NULL)
        return NULL;
    novo->dado = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

no* get_raiz_arv(arvore* a) {
    if(a == NULL)
        return NULL;
    return a->raiz;
}

void liberar_arv(arvore** a) {
    if(*a == NULL)
        return;
    liberar_no_arv(&((*a)->raiz));
    free(*a);
    *a = NULL;
}

void liberar_no_arv(no** no) {
    if(*no != NULL) {
        liberar_no_arv(&((*no)->esq));
        liberar_no_arv(&((*no)->dir));
        free(*no);
        *no = NULL;
    }
}

void pre_ordem_arv(no *n) {
    if(n != NULL) {
        printf("%d ", n->dado);
        pre_ordem_arv(n->esq);
        pre_ordem_arv(n->dir);
    }
}

void em_ordem_arv(no *n) {
    if(n != NULL) {
        em_ordem_arv(n->esq);
        printf("%d ", n->dado);
        em_ordem_arv(n->dir);
    }
}

void pos_ordem_arv(no *n) {
    if(n != NULL) {
        pos_ordem_arv(n->esq);
        pos_ordem_arv(n->dir);
        printf("%d ", n->dado);
    }
}


// ==================================================== FUNÇÕES FILAS ==================================================== //

struct fila {
    unsigned int qtde;
    no *dados[N];
};

Fila* criar_fila() {
    Fila *f = (Fila *)  malloc(sizeof(Fila)); 
    if (f == NULL) 
        return NULL;
    f->qtde = 0;
    return f; 
}

int esta_cheia_fila(Fila* f) { 
    if(f == NULL)
        return FLAG_ERRO;
    return f->qtde == N;
}

int esta_vazia_fila(Fila* f) {
    if(f == NULL)
        return FLAG_ERRO;
    return f->qtde == 0;
}

int enfileirar(Fila* f, no *n) {
    if (f == NULL || esta_cheia_fila(f))
        return FALSO;
    f->dados[f->qtde] = n;
    f->qtde++;
    return  VERDADEIRO;
}

int desenfileirar(Fila* f){
    if (f == NULL || esta_vazia_fila(f))
        return FALSO;
    int i;
    for (i = 1; i < f->qtde; i++)
        f->dados[i-1] = f->dados[i];
    f->qtde --;
    return VERDADEIRO;
}


// ==================================================== FUNÇÕES PILHAS ==================================================== //

struct pilha {
    unsigned int qtde;
    no *dados[N];
};

Pilha* criar_Pilha() {
    Pilha *p = (Pilha *)  malloc(sizeof(Pilha)); 
    if (p == NULL) 
        return NULL;
    p->qtde = 0;
    return p;
}

int empilhar(Pilha* p, no *n){
    if (n == NULL || esta_cheia(p))
        return FALSO;
    p->dados[p->qtde] = n;
    p->qtde++;
    return  VERDADEIRO;
}

int esta_cheia(Pilha* p) { 
    if(p == NULL)
        return FLAG_ERRO;
    return p->qtde == N;
}

int esta_vazia(Pilha* p) {
    if(p == NULL)
        return FLAG_ERRO;
    return p->qtde == 0;
}

no *elemento_topo(Pilha *p){
    return p->dados[p->qtde - 1];
}

int desempilhar (Pilha* p) {
    if (p == NULL || esta_vazia(p))
        return FALSO;
    p->qtde--;
    return VERDADEIRO;
}

no *elemento_inicio_fila(Fila *f){
    return f->dados[0];
}


// ==================================================== EXERCICIOS ==================================================== //

void pre_ordem_iterativo(arvore *a, no *n){
    Pilha *p = criar_Pilha();
    n = get_raiz_arv(a);
    empilhar(p,n);
    no *aux;
    while(!esta_vazia(p)){
        aux = elemento_topo(p);
        printf("%d ",elemento_topo(p)->dado);
        desempilhar(p);
        empilhar(p,aux->dir);
        empilhar(p,aux->esq);
    }
}

void em_ordem_iterativo(arvore *a, no *n){
    Pilha *p = criar_Pilha();
    no *atual = get_raiz_arv(a);
    while(!esta_vazia(p) || atual != NULL){
        if(atual != NULL){
            empilhar(p,atual);
            atual = atual->esq;
        }
        else{
            atual = elemento_topo(p);
            desempilhar(p);
            printf("%d ",atual->dado);
            atual = atual->dir;
        }
    }
}

void pos_ordem_iterativo(arvore *a, no *n){
    Pilha *p1 = criar_Pilha();
    Pilha *p2 = criar_Pilha();
    n = get_raiz_arv(a);
    empilhar(p1, n);
    while(!esta_vazia(p1)){
        no *aux = elemento_topo(p1);
        desempilhar(p1);
        empilhar(p2, aux);
        empilhar(p1, aux->esq);
        empilhar(p1, aux->dir);
    }

    while(!esta_vazia(p2)){
        printf("%d ",elemento_topo(p2)->dado);
        desempilhar(p2);
    }
    
}

void busca_largura_iterativo(arvore *a, no *n){
    Fila *f = criar_fila();
    no *temp;
    n = get_raiz_arv(a);
    enfileirar(f,n);
    while(!esta_vazia_fila(f)){
        temp = elemento_inicio_fila(f);
        desenfileirar(f);
        if(temp->esq != NULL)
            enfileirar(f, temp->esq);
        if(temp->dir != NULL)
            enfileirar(f, temp->dir);
        printf("%d ",temp->dado);
        
    }
    
}
