#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int vetor[10] = {10,3,7,9,8,6,1,2,4,5};
    int parar=1, parar2=1;
    clock_t start = clock();

    while (parar == 1)
    {
        parar2=1;
        //Shuffle
        for (int i = 0; i < 10; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (10 - i) + 1);
            int t = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = t;
        }
        //Ver se está na ordem certa
        int i = 0;
        while (parar2==1 && i < 10){
            if (!(vetor[i] < vetor[i+1])){
                parar2 = 0;
            }
            i++;
        }
        if (parar2 == 1){
            parar = 0;
        }
    }
    clock_t end = clock();

    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Vetor organizado!\n");
    printf("Tempo: %f segundos\n", seconds);
}