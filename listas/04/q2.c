#include <stdlib.h>
#include <stdio.h>
void troca_valor(float *x, float *y){
    float aux = *x;
    *x = *y;
    *y = aux;
}
int main(){
    float x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    troca_valor(&x, &y);
    printf("%i %i\n", x, y);
}