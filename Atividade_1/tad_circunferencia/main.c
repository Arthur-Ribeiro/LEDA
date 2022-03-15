#include <stdio.h>
#include <stdlib.h>
#include "tad_circunferencia.c"

int main() {

    circunferencia* c1 = criar_circunferencia(2.0, 3.0, 5.0);
    printf("\n\t\tEXIBINDO CIRCUNFERENCIA:\n");
    exibir_circunferencia(c1);
    printf("\n");


    printf("\n\t\tCALCULANDO AREA DA CIRCUNFERENCIA:\n");
    calcular_area(c1);
    printf("\n");

    printf("\n\t\tCALCULANDO PERIMETRO DA CIRCUNFERENCIA:\n");
    calcular_perimetro(c1);
    printf("\n");

    liberar_circunferencia(&c1);
    printf("\n\n");


    return 0;
}