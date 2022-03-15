#include <stdlib.h>
#include <stdio.h>
#include "digrafo_mat_adj.h"


struct digrafo {
    int V;
    int A;
    int **m_adj;
};


static int **matriz(int n) {
    int **m = (int**) calloc(n, sizeof(int*));
    for (vertice i = 0; i < n; ++i)
        m[i] = (int*) calloc(n, sizeof(int));

    return m;
}


digrafo criar_digrafo(int v) {
    digrafo G = (struct digrafo*) malloc(sizeof(digrafo));
    G->V = v;
    G->A = 0;
    G->m_adj = matriz(v);
    return G;
}


bool inserir_aresta(digrafo G, vertice u, vertice v) {
    if (G->m_adj[u][v] == 0 || G->m_adj[v][u] == 0) {
        G->m_adj[v][u] = 1;
        G->m_adj[u][v] = 1;
        G->A++;
        return VERDADEIRO;
    }

    return FALSO;
}


bool remover_aresta(digrafo G, vertice u, vertice v) {
    if (G->m_adj[u][v] == 1 || G->m_adj[v][u] == 1) {
        G->m_adj[u][v] = 0;
        G->m_adj[v][u] = 0;
        G->A--;
        return VERDADEIRO;
    }

    return FALSO;
}


void imprimir(digrafo G) {
    for(vertice u = 0; u < G->V; ++u) {
        printf("%2d:", u);
        for(vertice v = 0; v < G->V; ++v)
            if(G->m_adj[u][v] == 1)
                printf(" %2d", v);
        printf("\n");
    }
}


void imprimir_mat(digrafo G) {
    for(vertice u = 0; u < G->V; ++u) {
        for(vertice v = 0; v < G->V; ++v)
            printf(" %2d", G->m_adj[u][v]);
        printf("\n");
    }
}