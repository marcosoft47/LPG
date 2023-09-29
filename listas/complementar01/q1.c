#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, parar = 0, divs=0, count=0;
    printf("Informe o valor de n: ");
    scanf("%i", &n);
    printf("Informe o valor de m: ");
    scanf("%i", &m);

    printf("Valores perfeitos entre 1 e %i:\n", m);
    for (int i = 1; i <= m && parar != 1; i++){
        for (int j = i-1; j >= 1; j--){
            if (i % j == 0)
                divs += j;
        }
        if (divs == i){
            printf("%i eh perfeito\n", i);
            count++;
            if (count == n)
                parar = 1;
        }
        divs = 0;
    }
}