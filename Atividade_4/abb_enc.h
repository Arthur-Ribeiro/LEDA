#ifndef ABB_ENC_H    // INCLUDE GUARD
#define ABB_ENC_H

// INTERFACE DA ARVORE BINÁRIA DE BUSCA (ABB) ENCADEADA

typedef struct fila Fila;
typedef struct pilha Pilha;
typedef struct no no;
typedef struct arv arvore;



arvore* criar_arv(int valor_raiz);
no* criar_no(int valor);
no* get_raiz_arv(arvore* a);
no* elemento_topo(Pilha *p);
int adicionar_no_arv(arvore* a, int valor);
void liberar_arv(arvore** a);
void liberar_no_arv(no** no);
void em_ordem_arv(no *n);
void pre_ordem_arv(no *n);
void pos_ordem_arv(no *n);



Pilha* criar_Pilha();
int empilhar(Pilha* p, no *n);
int desempilhar(Pilha* p);
int esta_cheia(Pilha* p);
int esta_vazia(Pilha* p);



Fila* criar_fila();
int esta_cheia_fila(Fila* f);
int esta_vazia_fila(Fila* f);
int enfileirar(Fila* f, no *n);
int desenfileirar(Fila* f);



void pre_ordem_iterativo(arvore *a, no *raiz);
void em_ordem_iterativo(arvore *a, no *n);
void pos_ordem_iterativo(arvore *a, no *n);
void busca_largura_iterativo(arvore *a, no *n);


#endif // ARVORE_ENC_H