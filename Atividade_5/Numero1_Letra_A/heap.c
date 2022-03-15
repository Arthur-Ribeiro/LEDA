#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

#define FLAG_ERRO -1
#define VERDADEIRO 1
#define FALSO 0

static int filho_esq(heap *h, int id_p);
static int filho_dir(heap *h, int id_p);
static int inserir_fim_heap(heap* h, unsigned int v);
static void min_heapify_heap(heap *h, int id_p);
static int pai_heap(heap *h, int id_f);
static void trocar_heap(heap *h, int p1, int p2);

struct heap {
    unsigned int *dados;
    unsigned int capacidade;
    unsigned int qtde;
};

heap *criar_heap(int n) {
    heap* h = (heap*) malloc(sizeof(heap));
    if (h == NULL)
        return NULL;
    
    h->dados = (int*) malloc(n * sizeof(int));
    if(h->dados == NULL)
        return NULL;

    int i;
    for(i = 0; i < n; i++)
        h->dados[i] = -1;

    h->qtde = 0;
    h->capacidade = n;
    
    return h;
}

int esta_cheia_heap(heap* h) {
    if(h == NULL)
        return FALSO;

    return h->qtde == h->capacidade;
}

int esta_vazia_heap(heap* h) {
    if(h == NULL)
        return FALSO;

    return h->qtde == 0;
}

int esvaziar_heap(heap* h) {
    if(h == NULL)
        return FALSO;
    
    h->qtde = 0;
    return VERDADEIRO;
}

void exibir_heap(heap *h) {
    int i, nivel = 1;
    for (i = 1; i <= h->qtde; i++) {
        if(i == nivel) {
            printf("\n");
            nivel = 2*i;
        }
        printf("%d ", h->dados[i-1]);
    }
}

int indice_filho_esq(heap *h, int id_p) { // índice de um pai
    int esq = 2*id_p + 1;
    if(esq >= h->qtde)
        return FLAG_ERRO;
    
    return esq;
}

int indice_filho_dir(heap *h, int id_p) { // índice de um pai
    int dir = 2*id_p + 2;
    if (dir >= h->qtde)
        return FLAG_ERRO;
    
    return dir;
}

int indice_pai(heap *h, int id_f) {     // id_f: índice de um filho
    if (id_f <= 0)
        return FLAG_ERRO;

    return (id_f-1)/2;                  // truncado: divisão inteira
}

void liberar_heap(heap** h) {
    free((*h)->dados);
    free(*h);
    *h = NULL;
}

int inserir_heap(heap *h, unsigned int v) {
    if(!inserir_fim_heap(h, v))
        return FALSO;

    int id_v = h->qtde - 1;                 // índice atual de v
    int id_p = indice_pai(h, id_v);         // índice do pai atual de v
    while(id_p >= 0 && h->dados[id_v] < h->dados[id_p]) {
        trocar_heap(h, id_v, id_p);
        id_v = id_p;
        id_p = indice_pai(h, id_v);
    }

    return VERDADEIRO;
}

int inserir_fim_heap(heap* h, unsigned int v) {
    if (h == NULL || esta_cheia_heap(h))
        return FALSO;

    h->dados[h->qtde] = v;
    h->qtde++;

    return VERDADEIRO;
}

void inserir_vetor_heap(heap *h, int* vetor, unsigned int n) {
    int i;
    for (i = 0; i < n; i++)
        inserir_heap(h, vetor[i]);
}

void min_heapify(heap *h, int p) {          // p: índice do elemento pai
    if(h == NULL || p < 0 || p >= h->qtde)
        return;

    int id_fe = indice_filho_esq(h, p), id_fd = indice_filho_dir(h, p);
    while((id_fe > 0 && h->dados[p] > h->dados[id_fe]) ||
          (id_fd > 0 && h->dados[p] > h->dados[id_fd])) {
        
        if(id_fd >= h->qtde) {
            trocar_heap(h, p, id_fe);
            return;
        } else if(h->dados[id_fe] <= h->dados[id_fd]) {
            trocar_heap(h, p, id_fe);
            p = id_fe;
        } else {
            trocar_heap(h, p, id_fd);
            p = id_fd;
        }
        id_fe = indice_filho_esq(h, p);
        id_fd = indice_filho_dir(h, p);
    }
}

int remover_heap(heap *h) {
    if(h == NULL || esta_vazia_heap(h))
        return FLAG_ERRO;

    int retorno = h->dados[0];
    h->dados[0] = h->dados[h->qtde - 1];
    h->qtde--;

    min_heapify(h, 0);
    
    return retorno;
}

int tamanho_heap(heap* h) {
    if(h == NULL)
        return FLAG_ERRO;

    return h->qtde;
}

void trocar_heap(heap *h, int id1, int id2) {
    int aux = h->dados[id1];
    h->dados[id1] = h->dados[id2];
    h->dados[id2] = aux;
}
