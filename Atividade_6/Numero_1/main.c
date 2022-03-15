#include <stdio.h>
#include <stdlib.h>
#include "digrafo_mat_adj.h"

int main() {
    digrafo g = criar_digrafo(7);
    inserir_aresta(g, 0, 1);
    inserir_aresta(g, 0, 2);
    inserir_aresta(g, 1, 3);
    inserir_aresta(g, 1, 4);
    inserir_aresta(g, 2, 4);
    inserir_aresta(g, 3, 0);
    inserir_aresta(g, 4, 5);
    inserir_aresta(g, 5, 3);
    inserir_aresta(g, 6, 0);
    imprimir(g);

    printf("\n");
    remover_aresta(g, 0, 2);
    imprimir(g);
}
