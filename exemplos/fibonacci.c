#include <stdio.h>
#include <stdlib.h>

int main(){
    int atual=1, a=1, b=1, i=3, quantTermos;

    printf("Quantidade de termos: ");
    scanf("%i", &quantTermos);

    if(quantTermos>=1)
        printf("1°: 1\n");
    if (quantTermos>=2)
        printf("2°: 1\n");
    if (quantTermos>=3){
        while (i<=quantTermos)
        {
            atual = a + b;
            printf("%i°: %i\n", i, atual);
            a = b;
            b = atual;
            i++;
        }
    }
    
    
    
}