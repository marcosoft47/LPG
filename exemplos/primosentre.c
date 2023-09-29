#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, i=2, primo, naoehprimo=0, count=0, parar = 0;
    printf("Insira N e K (Sendo N menor que K): ");
    scanf("%i %i", &n, &k);

    primo = n;
    while (primo<k)
    {
        while (parar == 0){
            if (primo % i == 0){
                naoehprimo = 1;
                parar = 1;
            }
            i++;
            if(primo <= i){
                parar = 1;
            }
        }
        if(naoehprimo == 0){
            count++;
        }
        naoehprimo = 0;
        parar = 0;
        i = 2;
        primo++;
    }
    printf("%i\n", count);
    
}