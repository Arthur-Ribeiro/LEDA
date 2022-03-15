#ifndef GRAFO_MAT_ADJ_H
#define GRAFO_MAT_ADJ_H

typedef enum {FALSO, VERDADEIRO} bool;
typedef int vertice;
typedef struct digrafo * digrafo;

digrafo criar_digrafo(int v);
bool inserir_aresta(digrafo G, vertice v, vertice w);
bool remover_aresta(digrafo G, vertice v, vertice w);
void imprimir(digrafo G);
void imprimir_mat(digrafo G);

#endif // GRAFO_MAT_ADJ_H
