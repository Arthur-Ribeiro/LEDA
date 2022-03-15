#include <stdlib.h>
#include <stdio.h>

//#include "lista_linear_sequencial_inteiros.c"
#include "lista_linear_sequencial_inteiros.h"

int main(){
    lista *l1 = criar_lista();
    int i,res = 0, pos = 0; // a variavel "pos" recebe a primeira posição dos elementos da lista
    for(i = 1; i <= 10; i++)
        inserir_fim(l1,i*2);

    // ------------------------- EXERCICIO NUMERO 5 -------------------------
    printf("\nExibindo lista recursivamente: \n\n");
    printf("------ Inicio da lista ------\n");
    exibir_recursivamente(l1,pos); 
    printf("------ termino da lista ------\n");
    printf("Tamanho: %d\n\n", tamanho_lista(l1));

    printf("\n\n");


    // ------------------------- EXERCICIO NUMERO 4 -------------------------
    printf("soma de todos elementos = [%d]",soma(l1,res));
    printf("\n\n");

    return 0;
}