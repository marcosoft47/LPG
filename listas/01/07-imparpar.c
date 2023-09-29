#include <stdlib.h>
#include <stdio.h>

int main(){
    int qntPar = 0, qntImpar = 0, qntPos = 0, qntNeg = 0;
    int v[5];
    scanf("%i%i%i%i%i", &v[0], &v[1], &v[2], &v[3], &v[4]);

    for (int i = 0; i < 5; i++){
        if (v[i] % 2 == 0)
            qntPar++;
        else
            qntImpar++;
        if (v[i] > 0)
            qntPos++;
        if (v[i] < 0)
            qntNeg++;
    }
    printf("Pares: %i\nImpares: %i\nPositivos: %i\nNegativos: %i\n", qntPar, qntImpar, qntPos, qntNeg);
}