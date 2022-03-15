#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad_circunferencia.h"

#define Pi 3.141592654

struct circ{ 
    float r, x, y;
};

circunferencia* criar_circunferencia(float x, float y, float r){
    circunferencia *temp = (circunferencia *) malloc(sizeof(circunferencia));
    temp->r = r;
    temp->x = x;
    temp->y = y;
    return temp;
}

void exibir_circunferencia(circunferencia *circ){
    printf("\nA circunferencia possui raio r = %.2f e centro nas coordenadas x: %.2f, y: %.2f", circ->r, circ->x, circ->y);
}

void liberar_circunferencia(circunferencia **circ){
    free(*circ);
    *circ = NULL;
}

void calcular_area(circunferencia *circ){
    float area = 0, raio = 0;

    raio = circ->r;
    area = raio*Pi*raio;
    printf("\nArea -> %.2f",area);

}

void calcular_perimetro(circunferencia *circ){
    float perimetro = 0, raio = 0;

    raio = circ->r;
    perimetro = 2*Pi*raio;
    printf("\nPerimetro -> %.2f",perimetro);
}