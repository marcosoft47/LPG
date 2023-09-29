#include <stdlib.h>
#include <stdio.h>

int main(){
    /*
    //matriz de teste
    int A[2][2] = {{2,3},
                   {4,6}};
    int B[2][3] = {{1, 3, 0},
                   {2, 1, 1}};
        mult[2][3] = {{8, 9, 3},
                     {16, 18, 6}}*/

    int na, ma, nb, mb;
    printf("Matriz A:\n");
    printf("Informe n de A: ");
    scanf("%i", &na);
    printf("Informe m de A: ");
    scanf("%i", &ma);printf("Matriz B:\n");

    //Ao invés de um do while, eu poderia só definir o valor de nb como ma. Contudo, não quero.
    do{
        printf("Informe n de B: ");
        scanf("%i", &nb);
        if (nb != ma)
            printf("Número de linhas de B deve ser igual ao número de colunas de A");
    } while (nb != ma);
    printf("Informe m de B: ");
    scanf("%i", &mb);

    printf("Informe o conteúdo de A:\n");
    int A[na][ma];
    for (int i = 0; i < na; i++){
        for (int j = 0; j < ma; j++){
            scanf("%i", &A[i][j]);
        }
    }
    printf("informe o conteúdo de B:\n");
    int B[nb][mb];
    for (int i = 0; i < nb; i++){
        for (int j = 0; j < mb; j++){
            scanf("%i", &B[i][j]);
        }
    }
    
    //numpy.zero()
    int mult[na][mb];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++)
            mult[i][j] = 0;
    }

    //la/lb -> Linha de A ou B
    //ca/cb -> Coluna de A ou B
    //ca == lb
    for (int la = 0; la < 2; la++){
        for (int cb = 0; cb < 3; cb++){
            for (int ca = 0; ca < 2; ca++){
                mult[la][cb] += A[la][ca] * B[ca][cb];
            }
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++)
            printf("%i ", mult[i][j]);
        printf("\n");
    }
}