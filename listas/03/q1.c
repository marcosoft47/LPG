#include <stdlib.h>
#include <stdio.h>
#define S 3

int main(){
    int m[S][S];

    for (int i = 0; i < S; i++){
        for (int j = 0; j < S; j++)
            scanf("%i", &m[i][j]);
    }
    printf("\n");
    for (int i = 0; i < S; i++){
        for (int j = 0; j < S; j++)
            printf("%i ", m[i][j]);
        printf("\n");
    }
}