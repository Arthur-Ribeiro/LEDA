#include <stdlib.h>
#include <stdio.h>

#include "tad_ponto/tad_ponto.c"
#include "lista_linear_encadeada_pontos.c"

int main(){
    printf("\n----- TESTE BASICO -----\n");
    int i;
    Lista *l = criar_lista();
    if (l == NULL)
        exit(EXIT_FAILURE);
    exibir_lista(l);

    // ================================= INSERCAO ================================= //

    printf("\n ----- INSERCAO -----\n");
    printf("\n> Inicio\n");
    for (i = 1; i <= 4; i++)
        inserir_inicio(l, criar_pto(i * 1, i * 1));
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    printf("\n\n> Fim\n");
    for (i = 1; i <= 4; i++)
        inserir_fim(l, criar_pto(i * 1, i * 1));
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    printf("\n\n> Meio\n");
    inserir_meio(l,criar_pto(1000,1000), 3);
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    // ================================= REMOCAO ================================= //

    printf("\n ----- REMOCAO -----\n");
    printf("\n> Inicio\n");
    remover_inicio(l);
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    printf("\n> Fim\n");
    remover_fim(l);
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    printf("\n> Meio\n");
    remover_meio(l,4);
    exibir_lista(l);
    printf("\nTamanho: %d", tamanho(l));
    printf("\n");

    // ================================= BUSCAR ELEMENTO ================================= //

    printf("\n----- BUSCAR PONTO -----");
    printf("\n\nPonto (1000, 1000) existe? Resposta: ");
    buscar_ponto(l, criar_pto(1000,1000));

    printf("\n\nPonto (1, 1) existe? Resposta: ");
    buscar_ponto(l, criar_pto(1,1));

    printf("\n\nPonto (500, 500) existe? Resposta: %s\n", buscar_ponto(l, criar_pto(500,500)) ? "Sim" : "Nao");
    printf("\n");

    // ================================= ESVAZIANDO ================================= //

    printf("\n----- ESVAZIANDO LISTA -----\n");
    esvaziar_lista(l);
    exibir_lista(l);

    return 0;
}