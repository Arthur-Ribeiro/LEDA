#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <time.h>

int main() {
    srand(time(NULL));

    heap* h1 = criar_heap(15);
    if(h1 == NULL)
        exit(EXIT_FAILURE);

    int i = 0;
    printf("\n\n>>>> Inserir elementos\n");
    for(i = 0; i < 15; i++)
        inserir_heap(h1, 15 + ( rand() % 61 ));
    
    exibir_heap(h1);

    printf("\n\n>>>> REMOVER\n");
    int r = remover_heap(h1);
    if(r != -1)
        printf("\nRemocao efetuada com sucesso. Valor removido: %d.", r);
    else
        printf("\nRemocao nao efetuada.");
    exibir_heap(h1);

    printf("\n");
    r = remover_heap(h1);
    if(r != -1)
        printf("\nRemocao efetuada com sucesso. Valor removido: %d.\n", r);
    else
        printf("\nRemocao nao efetuada.\n");
    exibir_heap(h1);    

    liberar_heap(&h1);
    printf("\n\n");
    return 0;
}
