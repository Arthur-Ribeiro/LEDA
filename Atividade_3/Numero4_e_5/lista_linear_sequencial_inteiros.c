#include <stdlib.h>
#include <stdio.h>

#include "lista_linear_sequencial_inteiros.h"

#define VERDADEIRO 1
#define FALSO 0

struct lista {
    int dados[TAM];
    int qtde;
};

lista* criar_lista() {
    lista *temp = (lista *) calloc (1, sizeof(lista));
    temp->qtde = 0;
}

void exibir_lista(lista *l) {
    int i;
    printf("------ Inicio da lista ------\n");
    for(i = 0; i < tamanho_lista(l); i++){
        printf("elemento [%d] = %d",i+1, l->dados[i]);
        printf("\n");
    }
    printf("------ termino da lista ------\n");

}

int tamanho_lista(lista *l){
    return l->qtde;
}

int esta_vazia(lista *l){
    if(tamanho_lista(l) == 0)
        return VERDADEIRO;
    return FALSO;
}

int esta_cheia(lista *l){
    if(tamanho_lista == TAM)
        return VERDADEIRO;
    return FALSO;
}

int inserir_fim(lista *l, int e){
    if(esta_cheia(l))
        return FALSO;
    l->dados[l->qtde] = e;
    l->qtde++;
    return VERDADEIRO;
}


// ------------------------- EXERCICIO NUMERO 4 -------------------------

int soma(lista *l, int res){
    if(l->qtde != 0){
        res = l->dados[tamanho_lista(l) - 1] + res;
        l->qtde--;
        return soma(l,res);
    }
    else 
        return res;
}


// ------------------------- EXERCICIO NUMERO 5 -------------------------

int exibir_recursivamente(lista *l, int pos){
    if(pos < tamanho_lista(l)){
        printf("elemento [%d] = %d\n",pos + 1, l->dados[pos]);
        return exibir_recursivamente(l,pos + 1);
    }
  
}