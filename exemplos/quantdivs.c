#include <stdio.h>
#include <stdlib.h>

int main(){
    int quant = 0, i=1, n;
    printf("Insira um número: ");
    scanf("%i", &n);

    while (i<=n)
    {
        if(n%i == 0)
            quant++;
        i++;
    }

    printf("%i\n", quant);
}