#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    // Perimetro = 2pi*raio
    *pPerimetro = 6.28 * raio;
    // Área = pi * raio*raio
    *pArea = 3.14*raio*raio;
}
int main(){
    float raio, pPerimetro, pArea;
    scanf("%f", &raio);
    calcula_circulo(raio, &pPerimetro, &pArea);
    printf("Perimetro: %.2f\nÁrea: %.2f\n", pPerimetro, pArea);
}