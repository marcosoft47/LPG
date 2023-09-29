#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void iniciarMat(int n, int m, int *matriz){
    for (int i = 0; i < n * m; i++){
        matriz[i] = rand() % 50;
    }
}
void zero(int n, int m, int *matriz){
    for (int i = 0; i < n * m; i++){
            matriz[i] = 0;
    }
}
void multMat(int na, int ma,int A[na][ma], int nb, int mb,  int B[nb][mb], int mult[na][mb]){
    for (int la = 0; la < na; la++){
        for (int cb = 0; cb < mb; cb++){
            for (int ca = 0; ca < nb; ca++){
                mult[la][cb] += A[la][ca] * B[ca][cb];
            }
        }
    }
}
void sumMat(int n, int m, int *A, int *B, int *sum){
    for (int i = 0; i < n*m; i++){
        sum[i] = A[i] + B[i];
    }
}
void imprimirMat(int n, int m, int *matriz){
    for (int i = 0; i < n * m; i++){
        printf("%i ", matriz[i]);
    }
    printf("\n");
}
int main(){
    srand(time(NULL));
    int na, ma, nb, mb;
    printf("Informe o tamanho da matriz A (n m): ");
    scanf("%i%i",&na,&ma);
    printf("Informe o tamanho da matriz B (n m): "); 
    scanf("%i%i",&nb,&mb);

    int *A = malloc(na * ma * sizeof(int));
    int *B = malloc(nb * mb * sizeof(int));
    int *sum = malloc(na * ma * sizeof(int));
    for (int i = 0; i < na * ma; i++){
        *A[i]= rand() % 50;
    }
    for (int i = 0; i < nb * mb; i++){
        *B[i] = rand() % 50;
    }
    //int *mult = malloc(na * mb * sizeof(int));
    //iniciarMat(na,ma,&A);
    //iniciarMat(nb,mb,&B);
    //zero(na, ma, &mult);

    printf("Matriz A:\n");
    imprimirMat(na,ma,&A);
    printf("Matriz B:\n");
    imprimirMat(nb,mb,&B);
    if (na == nb && ma == mb){
        printf("Soma:\n");
        sumMat(na, ma, &A, &B, &sum);
        imprimirMat(na, ma, &sum);
    } else{
        printf("Impossível fazer soma!\nMatrizes devem ter tamanhos iguais\n");
    }
    /*if (ma == nb){
        printf("Multiplicacao:\n");
        //multMat(na, ma, &A, nb, mb, &B, &mult);
        //imprimirMat(na, mb, &mult);
    } else{
        printf("Impossível fazer multiplicacao!\nNumero de colunas de A deve ser equivalente ao número de linhas de B");
    }*/

    free(A);
    free(B);
    free(sum);
}