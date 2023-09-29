#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int n){
    //Negativo ou 1 não é primo
    if (n <= 1) {return 0;}
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, k, loop = 1, parar = 0;

    printf("Informe N: ");
    scanf("%i", &n);
    printf("Informe K: ");
    scanf("%i", &k);

    while (loop <= n){
        while (parar == 0){
            if(ehPrimo(k)){
                printf("%i) %i\n", loop, k);
                parar = 1;
            }
            //Poderia somar +2 para números ímpares, contudo, não quero.
            k++;
        }
        parar = 0;
        loop++;
    }
}