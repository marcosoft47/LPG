#include <stdlib.h>
#include <stdio.h>
int main(){
    int comeco, fim, count = 1;

    scanf("%i%i", &comeco, &fim);
    comeco++;
    while (comeco != fim){
        count++;
        comeco++;
        if (comeco == 24)
            comeco = 0;
    }
    printf("O jogo durou %i horas.\n", count);
}