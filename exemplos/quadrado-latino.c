#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int dimensao, parar = 0, num, primeiro;

    printf("Qual o tamanho do vetor? ");
    scanf("%i", &dimensao);
    int vetor[dimensao];

    for (int i = 0; i < dimensao; i++){
        num = (rand() % dimensao) + 1;
        for (int j = 0; j < i && parar == 0; j++){
            if(vetor[j] == num)
                parar = 1;
        }
        if (parar == 0)
            vetor[i] = num;
        else
            i--;
        parar = 0;        
    }
    printf("\n");

    for (int i = 0; i < dimensao; i++){

        primeiro = vetor[0];
        for (int j = 0; j < dimensao; j++){
            if (j + 1 >= dimensao)
                vetor[j] = vetor[j + 1 - dimensao];
            else
                vetor[j] = vetor[j + 1];
            
            if(j + 1 == dimensao)
                vetor[j] = primeiro;
            printf("%i ", vetor[j]);
        }
        printf("\n");
    }
}