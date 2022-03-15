#include <stdio.h>
#include <stdlib.h>

float produto(float a, float b, float res);
int enesima_potencia(int a, int b, int res);
int produto_vetor(int v[], int n);

int main(){

    // ------------------------- EXERCICIO NUMERO 1 ------------------------- //
    float num1 = 10, num2 = -5, res = 0;
    float num3 = 25, num4 = 10;

    printf("\n\n[%.2f] * [%.2f] = %.2f", num1, num2, produto(num1,num2, res));
    printf("\n\n[%.2f] * [%.2f] = %.2f\n\n", num3, num4, produto(num3,num4, res));


    // ------------------------- EXERCICIO NUMERO 3 ------------------------- //
    int n1 = 2, n2 = 10, anw = 1;
    int n3 = 3, n4 = 3;

    printf("\n\n[%d] ^ [%d] = %d", n1, n2, enesima_potencia(n1,n2, anw));
    printf("\n\n[%d] ^ [%d] = %d\n\n", n3, n4, enesima_potencia(n3,n4, anw));

    
    // ------------------------- EXERCICIO NUMERO 2 ------------------------- //
    int v[5] = {2,4,6,8,10};
    int i;
    printf("\nLista: \n\n");
    for(i = 0; i < 5; i++)
        printf("Elemento[%d] = %d\n", i + 1, v[i]);
    printf("\nO produto de todos os elementos presentes no vetor eh: %d\n\n", produto_vetor(v, 5));    

    return 0;
}


// ------------------------- FUNÇÃO - EXERCICIO NUMERO 1 ------------------------- //

float produto(float a, float b, float res){
    if(b < 0){
        a = -a;
        b = -b;
        return(produto(a, b, res));
    }

    if(b!= 0){
        res = res + a;
        return produto(a, b - 1, res);
    }
    else 
        return res;
}

// ------------------------- FUNÇÃO - EXERCICIO NUMERO 3 ------------------------- //

int enesima_potencia(int a, int b, int res){
    if(b != 0){
        res = res * a;
        return enesima_potencia(a, b - 1, res);
    }
    else 
        return res;  
}
 

// ------------------------- FUNÇÃO - EXERCICIO NUMERO 2 ------------------------- //

int produto_vetor(int v[], int n){
    if(n == 1)
        return v[0];

    else
        return v[n-1] * produto_vetor(v, n-1);

    return 1;
}

