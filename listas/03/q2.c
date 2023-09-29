#include <stdlib.h>
#include <stdio.h>

int main(){
    int n, m;
    printf("Informe n: ");
    scanf("%i", &n);
    printf("Informe m: ");
    scanf("%i", &m);
    int matriz[n][m];

    //Essa matriz começa com coordenada 0
    //O mais matematicamente correto seria começar em 1
    //E na boa, vou fazer outro for para imprimir a matriz não
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            matriz[i][j] = i + j; //Se começasse em 1, seria ((i+1) + (j+1)), ou (i + j + 2)
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
}