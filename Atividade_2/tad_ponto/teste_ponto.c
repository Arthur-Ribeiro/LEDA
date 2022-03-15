#include <stdio.h>
#include "tad_ponto.c"

// função main só para fazer os testes das funções criadas.

int main() {
    ponto* p1 = criar_pto(1.0, 5.0), *p2 = criar_pto(2.0, 3.0), *p3 = criar_pto(14.0, 5.0);
    //p1 = p2;
    printf("p1: ");
    exibir_pto(p1); printf("\n"); printf("\n");

    printf("p2: ");
    exibir_pto(p2); printf("\n"); printf("\n");

    printf("\ndistancia de p1 e p2: %.2f\n", calcular_distancia_pto(p1, p2)); printf("\n");

    mover_pto(p1, 10.0, -5.0);
    printf("p1: ");
    exibir_pto(p1); printf("\n"); printf("\n");

    mover_pto(p2, -1.0, 1.0);
    printf("p2: ");
    exibir_pto(p2); printf("\n"); printf("\n");

    printf("p3: ");
    exibir_pto(p3); printf("\n");
    mover_pto(p3, 100.0, 100.0);
    printf("p3 apos move-lo: ");
    exibir_pto(p3); printf("\n"); printf("\n");
    liberar_pto(&p1);
    liberar_pto(&p2);
    liberar_pto(&p3);
    return 0;
}
