#ifndef TAD_PONTO_H
#define TAD_PONTO_H

typedef struct pto ponto;

float calcular_distancia_pto(ponto *p, ponto *q);
ponto* criar_pto(float x, float y);
void exibir_pto(ponto *p);
void liberar_pto(ponto **p);
void mover_pto(ponto *p, float dx, float dy);

#endif //TAD_PONTO_H
