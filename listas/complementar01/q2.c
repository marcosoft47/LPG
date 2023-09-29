#include <stdio.h>
#include <stdlib.h>

int main(){
    int rsize, ssize, count = 0, parar = 0;
    printf("Digite o tamanho do vetor R: ");
    scanf("%i", &rsize);
    printf("Digite o tamanho do vetor S: ");
    scanf("%i", &ssize);
    int r[rsize], s[ssize];

    printf("Digite o vetor R: ");
    for (int i = 0; i < rsize; i++)
        scanf("%i", &r[i]);
    printf("Digite o vetor S: ");
    for (int i = 0; i < ssize; i++)
        scanf("%i", &s[i]);

    //Usar qualquer tamanho para o vetor
    //x nunca ocupará mais do que o tamanho do menor vetor
    //Se o tamanho dele for do maior vetor, ele ocupará um espaço desnecessário
    int x[ssize];
    
    for (int i = 0; i < rsize; i++){
        for (int j = 0; j < ssize && parar != 1; j++){
            if (r[i] == s[j]){
                x[count] = s[j];
                parar = 1;
                count++;
            }
        }
        parar = 0;
    }
    for (int i = 0; i < count; i++)
        printf("%i ", x[i]);
}