#include <stdlib.h>
#include <stdio.h>
void max_vetor(float v[], int tam, float *pMax, int *pIndice){
    for (int i = 0; i < tam; i++){
        if (*pMax <= v[i]){
            *pMax = v[i];
            *pIndice = i;
        }
    }
}
int main(){
    int tam = 5, pIndice;
    printf("Informe o tamanho do vetor: ");
    scanf("%i", &tam);
    float v[tam];
    for (int i = 0; i < tam; i++)
        scanf("%f", &v[i]);
    float pMax = v[0];
    max_vetor(v, tam, &pMax, &pIndice);
    printf("Maior número: %.2f\nPosição: %i\n", pMax, pIndice);
}