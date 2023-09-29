#include <stdio.h>
#include <stdlib.h> /* rand() e srand() */
#include <time.h> /* time() */

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define GRAY     "\x1B[30m"
#define RESET    "\x1B[0m"

//Respostas : Linha 57-58 Linha 82 - 87. Sujeito a mudar algumas casa de linha, mas deixei bem marcado onde está a resposta
int main(void) {
    int *p, n, i, a[10], cond=1;
    int resposta=1;

    // Importante! Não é possível realocar um vetor estático!!!
    // a = realloc(a, sizeof(int)*(10+n));
    // A variável "a" não é utilizada neste código...
    
    printf(GREEN "\nQuantas posições devem ser criadas no vetor?\n");
    printf(GRAY "Valores gerados aleatoriamente...\n\n");
    printf(RESET ">> ");
    scanf("%d", &n);
    p = malloc(sizeof(int)*n);
    if (!p) {
        printf (GRAY "\n** Erro: Memoria Insuficiente! **\n          ");
        exit(1);
    }
    
    // Entrada de dados (aleatória)
    // Alteração da "semente"...
    // Para não ocorrer a repetição de valores
    // (em mais de uma execução, ou seja, os mesmos valores).
    // Claro que, valores pontuais podem se repetir, em uma execução.
    
    srand(time(NULL));
    
    for(i=0; i<n; i++) {
        *(p+i) = rand() % 100;
    }
    // Apresentação de dados
    printf(RED "\n| ");
    for(i=0; i<n; i++)
        printf("%d ", *(p+i));
    printf("|\n");
    
    while(cond == 1) {
        printf(GREEN "\nDeseja excluir (1) / incluir (2) uma posição, no final do vetor?\n");
        printf(GRAY "(1 ou 2 --> 3 para finalizar...)\n\n");
        printf(RESET ">> ");
        scanf("%d", &resposta);
        if(resposta == 1) {
            if(n > 0) {
                ////////////
                //RESPOSTA//
                ////////////
                //Antes de realocar, vamos passar todos os elementos uma casa para a esquerda
                for (i = 0; i<n; i++)
                        *(p+i) = *(p+i+1);
                
                p = realloc(p , sizeof(int)*(n - 1));
                n = n - 1;
                // Apresentação de dados
                printf(RED "\n| ");
                for(i = 0; i < n; i++)
                    printf("%d ", p[i]);
                printf("|");
                printf(RESET "\n");
            }
            else
                printf("\nO vetor não possui elementos!!!\n");
        }
        if(resposta == 2) {
            p = realloc(p , sizeof(int)*(n + 1));
            if (!p) {
                printf (GRAY "** Erro: Memória Insuficiente! **");
                exit(1);
            }
            ////////////
            //RESPOSTA//
            ////////////
            //Vamos passar todos os elementos do vetor uma casa para frente
            for (i = n; i>=0; i--){
                if(!(i == 0))
                    *(p+i) = *(p+i-1);
                else
                    *(p) = rand() % 100;
            }
            n = n + 1;
                
            // Apresentação de dados
            printf(RED "\n| ");
            for(i=0; i<n; i++)
                printf("%d ", p[i]);
            printf("|\n");
            
        }
        if(resposta == 3) {
                free(p);
                printf(RED "\nMemória liberada!");
                printf(GRAY "\nFIM\n\n");
                cond= 0;
        }
    }
}