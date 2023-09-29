#include <stdlib.h>
#include <stdio.h>
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (*pMin >= mat[i][j]){
                *pMin = mat[i][j];
                *pI = i;
                *pJ = j;
            }
        }
    }
}
int main(){
    int pI, pJ;
    float mat[3][4];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++)
            scanf("%f", &mat[i][j]);
    }
    float pMin = mat[0][0];

    min_matriz(mat, &pMin, &pI, &pJ);
    printf("%.2f %i %i", pMin, pI, pJ);
}