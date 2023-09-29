#include <stdlib.h>
#include <stdio.h>
void frente(int *vet, int n, int i, int v){
    int parar = 0;
    i = i - 1;
    while (i<=n && v>0){
        *(vet + i) = v;
        i++;
        v--;
    }
}
void tras(int *vet, int n, int i, int v){
    int parar = 0;
    i = i - 1;
    while (i>=0 && v>0){
        *(vet + i) = v;
        i--;
        v--;
    }
}
void imprimir(int vet[], int i){
    printf("\n%i\n", vet[i-1]);
}
int main(){
    int n = 0, v = 0, i = 0, comando = 0;
    printf("Diga o tamanho do vetor: ");
    scanf("%i", &n);

    //Posição de v tem que começar em 1
    int vet[n+1];
    //Mesmo não usando, vamos preencher v[0] mesmo assim.
    for (int pos = 0; pos < n+1; pos++)
        vet[pos] = 0;
    
    //Começar comandos
    while (comando != 4){
        (scanf("%i", &comando));
        if (comando != 4){
            scanf("%i", &i);
            if (comando == 3)
                imprimir(vet, i);
            else{
                scanf("%i", &v);
                if (comando == 1)
                    frente(&vet,n,i,v);
                else
                    tras(&vet,n,i,v);
            }
        }
        printf("\n");
    }
}