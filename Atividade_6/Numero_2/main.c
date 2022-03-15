#include <stdio.h>
#include <stdlib.h>
#include "digrafo_lst_adj.h"

#define N 8

int main(void) {
    digrafo *g = criar_digrafo(N);

    inserir_aresta(g, 0, 1);
    inserir_aresta(g, 0, 2);
    inserir_aresta(g, 1, 3);
    inserir_aresta(g, 2, 4);
    inserir_aresta(g, 3, 0);
    inserir_aresta(g, 4, 1);
    inserir_aresta(g, 4, 5);
    inserir_aresta(g, 5, 3);
    inserir_aresta(g, 6, 1);
    inserir_aresta(g, 6, 3);
    imprimir(g, N);

    //remover_aresta(g, 0, 1);
    remover_aresta(g, 2, 4);
    imprimir(g, N);

    liberar(&g, N);
    return 0;
}