#include <stdlib.h>
#include <stdio.h>

int main(){
    int n, m, soma = 0, count = 0;
    float media;
    printf("Informe n: ");
    scanf("%i", &n);
    printf("Informe m: ");
    scanf("%i", &m);
    int matriz[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%i", &matriz[i][j]);
            if (matriz[i][j] > 0){
                soma += matriz[i][j];
                count++;
            }
        }
    }
    media = soma / count; 
    printf("Media dos positivos: %.1f\n", media);
}