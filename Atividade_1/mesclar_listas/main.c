#include <stdlib.h>
#include <stdio.h>
#include "lista_int.c"

int main(){
    int i;

    lista *lst1 = criar_lista();
    lista *lst2 = criar_lista();

    for (i = 1; i <= TAM/2; i++)
        inserir_fim(lst1, i);
    
    for (i = 1; i <= TAM/2; i++)
        inserir_fim(lst2, i*2);

    printf("\nLista 1 -> ");
    exibir_lista(lst1);
    printf("\n\n");

    printf("\nLista 2 -> ");
    exibir_lista(lst2);
    printf("\n\n");

    printf("\n\t\tMESCLANDO AS LISTAS: \n");
    mesclar_listas(lst1,lst2);
    printf("\nLista 3 (resultado da mesclagem) -> ");
    exibir_lista(mesclar_listas(lst1,lst2));

    printf("\n\n");

    return 0;
}