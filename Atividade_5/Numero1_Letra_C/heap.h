#ifndef heap_H
#define heap_H

typedef struct heap heap;

heap* criar_heap(int n);
void inserir_vetor_heap(heap *h, int* vetor, int n);

int esta_cheia_heap(heap* h);
int esta_vazia_heap(heap* h);
int esvaziar_heap(heap* l);
void exibir_heap(heap *h);

int inserir_heap(heap *h, int v);

void liberar_heap(heap** l);

int remover_heap(heap *h);

#endif //heap_H