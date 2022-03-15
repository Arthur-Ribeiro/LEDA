#ifndef TAD_CIRCUNFERENCIA_TAD_CIRCUNFERENCIA_H
#define TAD_CIRCUNFERENCIA_TAD_CIRCUNFERENCIA_H

typedef struct circ circunferencia;

circunferencia* criar_circunferencia(float x, float y, float r);
void exibir_circunferencia(circunferencia *circ);
void liberar_circunferencia(circunferencia **circ);
void calcular_area(circunferencia *circ);
void calcular_perimetro(circunferencia *circ);

#endif //TAD_CIRCUNFERENCIA_TAD_CIRCUNFERENCIA_H
