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
    int n;
    int contador = 0;
    int totalLinhas = 0;

    printf("Insira um número:\nN = ");
    scanf("%i", &n);

    if(ehPrimo(n)==1){
        printf("%i eh primo!\n\n", n);
    } else{
        printf("%i nao eh primo!\n\n", n);
    }

    printf("Numeros primos ate %i:\n", n);
    for (int i = 2; i < n; i++){
        if (ehPrimo(i))
        {
            if (totalLinhas >= 9){
                printf("\n");
                totalLinhas = 0;
            }
            printf("%4i ", i);
            totalLinhas++;
            contador++;
        }
    }
    printf("\nTotal de primos: %i\n\n", contador);
    //Reutilizar variáveis é poggers
    totalLinhas = 0;
    contador = 0;

    printf("Relacao dos %i primeiros numeros primos: \n", n);
    for (int i = 2; contador < n; i++){
        if (ehPrimo(i))
        {
            if (totalLinhas >= 9){
                printf("\n");
                totalLinhas = 0;
            }
            printf("%4i ", i);
            totalLinhas++;
            contador++;
        }
    }
    printf("\n");
}