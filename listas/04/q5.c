#include <stdlib.h>
#include <stdio.h>
void min_max(int v[], int tam, int *pMin, int *pMax){
    for (int i = 0; i < tam; i++){
        if (*pMin > v[i])
            *pMin = v[i];
        if (*pMax < v[i])
            *pMax = v[i];
    }
}
int main(){
    int tam, pMin, pMax;
    printf("Insira o tamanho do vetor: ");
    scanf("%i", &tam);
    int v[tam];
    for (int i = 0; i < tam; i++)
        scanf("%i", &v[i]);
    // Inicializar pMin e pMax
    pMin = v[0], pMax = v[0];
    min_max(v, tam, &pMin, &pMax);
    printf("%i %i\n", pMin, pMax);
}