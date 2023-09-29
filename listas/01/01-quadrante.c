#include <stdlib.h>
#include <stdio.h>

int main(){
    float x, y;
    printf("Informe X e Y: ");
    scanf("%f%f", &x ,&y);

    if (x != 0 && y != 0){
        if (y > 0){
            if (x > 0)
                printf("Primeiro quadrante");
            else
                printf("Segundo quadrante");
        } else{
            if (x < 0)
                printf("Terceiro quadrante");
            else
                printf("Quarto quadrante");
        }
    } else if ( x == 0 && y != 0)
        printf("Eixo X");
    else if (x != 0 && y == 0)
        printf("Eixo Y");
    else
        printf("Origem");
    printf("\n");
}
