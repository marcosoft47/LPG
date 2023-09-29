#include <stdlib.h>
#include <stdio.h>
int ehMultiplo (int maior, int menor){
    if (maior % menor == 0){
        printf("Sao multiplos");
    }
    else{
        printf("Nao sao multiplos");
    }
    return 0;
}
int main(){
    int n, m;
    scanf("%i%i", &n, &m);

    if (n <=  m)
        ehMultiplo(m, n);
    else
        ehMultiplo(n, m);
    printf("\n");
}