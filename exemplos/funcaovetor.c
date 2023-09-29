#include <stdlib.h>
#include <stdio.h>
#define MAX 10
float media(int vet[], int n){
    int soma = 0;
    for(int i = 0; i < n; i++)
        soma += vet[i];
    return soma/n;
}
int main(){
    int v[] = {9, 3, 4, 5, 1, 2, 6, 7, 8, 10};
    printf("Media: %.1f", media(v, MAX));
}