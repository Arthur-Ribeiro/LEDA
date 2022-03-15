#include <stdio.h>
#include <stdlib.h>
#include "abb_enc.h"

int main() {
    int nos[] = {3, 7, 10, 1, 2, 12, 15, 8, 11, 5};
    int i, qtde_nos = sizeof(nos)/sizeof(int);

    arvore* a = criar_arv(nos[0]);

    for(i = 1; i < qtde_nos; i++)
        adicionar_no_arv(a, nos[i]);

    no* r = get_raiz_arv(a);
     if(r != NULL) {
        printf("\nPercurso em pre-ordem: ");
        pre_ordem_arv(r);
        printf("\n");
    
        printf("Percurso em pre-ordem ITERATIVO: ");
        pre_ordem_iterativo(a, r);
        printf("\n");


        printf("\nPercurso em em-ordem: ");
        em_ordem_arv(r);
        printf("\n");

        printf("Percurso em em-ordem ITERATIVO: ");
        em_ordem_iterativo(a,r);
        printf("\n");

        
        printf("\nPercurso em pos-ordem: ");
        pos_ordem_arv(r);
        printf("\n");

        printf("Percurso em pos-ordem ITERATIVO: ");
        pos_ordem_iterativo(a,r);
        printf("\n");

        printf("\nBusca em largura Iterativo: ");
        busca_largura_iterativo(a,r);
        printf("\n");
    }

    liberar_arv(&a);
    printf("\nArvore liberada: %s\n", (a == NULL ? "Sim" : "Nao"));
    return 0;
}
