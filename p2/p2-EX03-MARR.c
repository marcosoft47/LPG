#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define VALORES_MAXIMOS 10
// Aqui iremos começar as matrizes dando valores aleatorios baseado em VALORES_MAXIMOS
// A prova pediu para fazer no programa principal, mas acho muito mais organizado fazer uma função dedicada para isso
// Além de que foi assim que fiz no dia 24/06, porque inventar outro jeito de resolver se esse funciona?
void iniciarMatriz(int n, int m, int *matriz[n]){
    for (int i = 0; i < n; i++){
        matriz[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++)
            matriz[i][j] = 1 + (rand() % VALORES_MAXIMOS);
    }
}
// Imprime as matrizes numa grade
void imprimirMatriz(int n, int m, int *matriz[n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%i ", matriz[i][j]);
        printf("\n");
    }
}
// Soma as matrizes
// Como a prova pede que as duas sejam de tamanho n x m, não preciso verificar se ambas tem um tamanho igual
void somarMatrizes(int n, int m, int *A[n], int *B[n], int *sum[n]){
    for (int i = 0; i < n; i++){
        sum[i] = malloc(sizeof(int) * m);
        for (int j = 0; j < m; j++){
            sum[i][j] = A[i][j] + B[i][j];
        }
    }
}
int main(){
    srand(time(NULL));
    int n, m;
    printf("Informe as dimensões das matrizes (n m): ");
    scanf("%i%i", &n, &m);
    int *A[n], *B[n], *sum[n];

    //Inicia e imprime A
    printf("\nMatriz A:\n");
    iniciarMatriz(n, m, &A);
    imprimirMatriz(n, m, &A);

    //Inicia e imprime B
    printf("\nMatriz B:\n");
    iniciarMatriz(n, m, &B);
    imprimirMatriz(n, m, &B);

    //Faz a soma e mostra o resultado;
    somarMatrizes(n, m, &A, &B, &sum);
    printf("\nSoma das matrizes:\n");
    imprimirMatriz(n, m, &sum);

    //Liberar a memória UwU XD :3
    //Todos tem o mesmo tamanho, vamos usar o mesmo for
    for (int i = 0; i < n; i++){
        free(A[i]);
        free(B[i]);
        free(sum[i]);
    }
    printf("FIM\nMEMÓRIA LIBERADA!\n");
}