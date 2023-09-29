#include <stdio.h>
#include <stdlib.h>

int main(){
    int v[] = {9, 3, 4, 5, 1, 2, 6, 7, 8, 10};
    int menor = v[0], S = sizeof(v) / sizeof(v[0]), terminou = 0;
    float media = 0;

    for (int i = 1; i < S; i++){
        if (terminou == 0){
            if (menor > v[i]){
                menor = v[i];
            }
            media += v[i];
        } else{
            if (v[i]>media)
                printf("%i ", v[i]);
        }
        if (i+1 >= S && terminou == 0){
            terminou = 1;
            i = -1;
            media += v[0];
            media = media / S;
            printf("Menor: %i\n", menor);
            printf("Media: %f\n", media);
            printf("Valores acima da media: ");
        }
    }
    printf("\n");
}