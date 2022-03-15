#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    printf("------ TESTE BASICO ------\n");

    heap* h1 = criar_heap(20);
    if(h1 == NULL)
        exit(EXIT_FAILURE);

    printf("> Inserir elementos\n");
    int i;
    for(i = 1; i <= 20; i++) {
        if(inserir_heap(h1, i))
            printf("\nInsercao de %d com sucesso", i);
        else
            printf("Valor %d nao inserido", i);
        
        exibir_heap(h1);
        printf("\n");
    }
    
    printf("\n\n> REMOVER\n");

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

    printf("\n\n>>>> INSERIR os elementos de um vetor \n");
    int vetor[] = {50, 29, 33, 21, 11, 78, 66, 99};

    heap* h2 = criar_heap(20);
    if(h2 == NULL)
        exit(EXIT_FAILURE);
    
    inserir_vetor_heap(h2, vetor, sizeof(vetor)/sizeof(int));
    printf("\n\n> REMOVER\n");
    while(!esta_vazia_heap(h2)) {
        r = remover_heap(h2);
        if(r != -1)
            printf("\nRemocao efetuada com sucesso. Valor removido: %d.", r);
        else
            printf("\nRemocao nao efetuada.");
        exibir_heap(h2);
        printf("\n");
    }

    liberar_heap(&h1);
    liberar_heap(&h2);

    return 0;
}
