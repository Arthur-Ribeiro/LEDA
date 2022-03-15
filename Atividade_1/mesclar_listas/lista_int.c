#include <stdio.h>
#include <stdlib.h>
#include "lista_int.h"

#define VERDADEIRO 1
#define FALSO 0

struct lista{
    int dados[TAM];
    int qtde;
};

lista *criar_lista(){
    lista *temp = (lista *)malloc(sizeof(lista));
    temp->qtde = 0;
}

int tamanho_lista(lista *l){
    return l->qtde;
}

int esta_cheia(lista *l){
    if (tamanho_lista(l) == TAM)
        return VERDADEIRO;
    return FALSO;
}

int esta_vazia(lista *l){
    if (tamanho_lista(l) == 0)
        return VERDADEIRO;
    return FALSO;
    ;
}

void exibir_lista(lista *l){
    int i;
    printf("[");
    for (i = 0; i < tamanho_lista(l); i++){
        printf("%d", l->dados[i]);
        if(i != (tamanho_lista(l) - 1))
            printf(", ");
    }
    printf("]");
}

int inserir_fim(lista *l, int e){
    if (esta_cheia(l))
        return FALSO;
    l->dados[l->qtde] = e;
    l->qtde++;
    return VERDADEIRO;
}

int mesclar_listas(lista *l1, lista *l2){
    int i = 0, j = 0;
    lista *l3 = criar_lista();
    
    while(i <= tamanho_lista(l1) && j <= tamanho_lista(l2)){
        inserir_fim(l3,l1->dados[i]);
        i++;
        inserir_fim(l3,l2->dados[j]);
        j++;
    }

    while(i <= tamanho_lista(l1)){
        inserir_fim(l3,l1->dados[i]);
        i++;        
    }

    while(i <= tamanho_lista(l2)){
        inserir_fim(l3,l2->dados[j]);
        j++;        
    }

    return l3;
}

