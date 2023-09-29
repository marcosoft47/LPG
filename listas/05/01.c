#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void iniciarMat(int n, int m, int *matriz[n]){
    for (int i = 0; i < n; i++){
        matriz[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            matriz[i][j] = rand() % 10;
    }
}
void zero(int n, int m, int *matriz[n]){
    for (int i = 0; i < n; i++){
        matriz[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            matriz[i][j] = 0;
    }
}
void multMat(int na, int ma, int *A[na], int nb, int mb,  int *B[nb], int *mult[na]){
    for (int la = 0; la < na; la++){
        for (int cb = 0; cb < mb; cb++){
            for (int ca = 0; ca < nb; ca++){
                mult[la][cb] += A[la][ca] * B[ca][cb];
            }
        }
    }
}
void sumMat(int n, int m, int *A[n], int *B[n], int *sum[n]){
    for (int i = 0; i < n; i++){
        sum[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            sum[i][j] = A[i][j] + B[i][j];
    }
}
void imprimirMat(int n, int m, int *matriz[n]){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                printf("%i ", matriz[i][j]);
            }
        printf("\n");
        }
}

int main(){
    srand(time(NULL));
    int na, ma, nb, mb;
    printf("Informe o tamanho da matriz A (n m): ");
    scanf("%i%i",&na,&ma);
    printf("Informe o tamanho da matriz B (n m): "); 
    scanf("%i%i",&nb,&mb);

    int *A[na], *B[nb], *sum[na], *mult[na];
    iniciarMat(na,ma,A);
    iniciarMat(nb,mb,B);
    zero(na, mb, &mult);

    printf("Matriz A:\n");
    imprimirMat(na,ma,&A);
    printf("Matriz B:\n");
    imprimirMat(nb,mb,&B);
    printf("\n");
    if (na == nb && ma == mb){
        printf("Soma:\n");
        sumMat(na, ma, A, B, sum);
        imprimirMat(na, ma, sum);
    } else{
        printf("Impossível fazer soma!\nMatrizes devem ter tamanhos iguais\n");
    }
    if (ma == nb){
        printf("Multiplicacao:\n");
        multMat(na, ma, &A, nb, mb, &B, &mult);
        imprimirMat(na, mb, &mult);
    } else{
        printf("Impossível fazer multiplicacao!\nNumero de colunas de A deve ser equivalente ao número de linhas de B");
    }
    for (int i = 0; i < na; i++)
        free(A[i]);
    for (int i = 0; i < nb; i++)
        free(B[i]);
    for (int i = 0; i < na; i++)
        free(sum[i]);
    printf("Pronto!");
}