#include <stdio.h>
#include <stdlib.h>

int main(){
    // Tanto realloc quanto malloc retornam 0 quando não é possível alocar memória
    // Li meio rápido a pergunta e não vi que era para usar num exemplo prático o máximo de memória
    int cond = 0, *p, count = 1;
    p = malloc(sizeof(int));
    while (cond == 0){
        p = realloc(p, (count * sizeof(int)));
        if (!p){
            // Na minha máquina deu 8 milhões e meio, meio que bate com os 8MB que o gcc tem como máximo por padrão
            // Usei li por medo de sair quebrado se for inserir como um int normal
            printf("Memória máxima: %li\n", (count-1)*sizeof(int));
            printf("Count: %li", count);
            cond = 1;
        }
        count++;
    }
    free(p);
}
