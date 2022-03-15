#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include <time.h>

int main() {
    srand(time(NULL));

    heap* h1 = criar_heap(20);
    if(h1 == NULL)
        exit(EXIT_FAILURE);

    int i = 0, vetor[20];

    for(i = 0; i < 20; i++)
        vetor[i] = ((rand() % 65) + (-19));
    
    printf("\n\n>>>> INSERIR os elementos de um vetor \n");
    inserir_vetor_heap(h1, vetor, sizeof(vetor)/sizeof(int));
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