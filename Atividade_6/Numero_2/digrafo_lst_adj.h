#ifndef DIGRAFO_LST_ADJ_H
#define DIGRAFO_LST_ADJ_H


typedef enum {FALSO, VERDADEIRO} bool;
typedef struct no no;
typedef int vertice;
typedef struct digrafo digrafo;

digrafo* criar_digrafo(int n);
void imprimir(digrafo* G, int n);
bool inserir_aresta(digrafo *G, vertice v, vertice w);
void liberar(digrafo** G, int n);
bool remover_aresta(digrafo *G, vertice v, vertice w);

#endif // DIGRAFO_LST_ADJ_H
