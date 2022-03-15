#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad_ponto.h"

struct pto { 
    float x, y;
};

float calcular_distancia_pto(ponto *p, ponto *q) {
    return sqrt(pow(q->y - p->y, 2) + pow(q->x - p->x,2));
}

ponto* criar_pto(float x, float y) {
    ponto *temp = (ponto *) malloc(sizeof(ponto));
    temp->x = x;
    temp->y = y;
    return temp;
}

void exibir_pto(ponto *p) {
    printf("(%.2f, %.2f)", p->x, p->y);
}

void liberar_pto(ponto **p) {
    free(*p);
    *p = NULL;
}

void mover_pto(ponto *p, float dx, float dy) {
    (*p).x += dx;
    p->y += dy; 
}