#include <stdio.h>
#include <stdlib.h>

int main(){
    // Aqui eu crio um ponteiro com tamanho comicamente grande
    // O ponteiro tem um tamanho tão grande que não será possível armazenar na memória que o GCC permite por padrão
    int *p = malloc(sizeof(int) * 999999999999999999 * 999999999999999999);

    // Enquanto fazia o resto da lista do dia 24, percebi esse if
    // Achei bem poggers e percebi que C é uma linguagem muito sinistra
    // Se pá ele volta um False caso não tenha sido possível alocar p 
    // Tanto que se tirar o !, ele vai para o else
    if (!p)
        printf("Memória insuficiente!");
    else
        printf("Memória suficiente!");
}