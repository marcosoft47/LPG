#include <stdio.h>
#include <stdlib.h>

int main(){
    char cpf[11] = "03019131294";
    int cpfint[11], soma = 0, valido = 1, verificador, i = 0, j = 10;

    for (int i = 0; i < 11; i++)
        cpfint[i] = cpf[i] - '0';

    //Primeiro digito verificador
    while (i < 9){
        soma += j * cpfint[i];
        i++;
        j--;
    }
    if (soma % 11 >= 2)
        verificador = 11 - (soma % 11);
    else
        verificador = 0;

    if (verificador != cpfint[9]){
        valido = 0;
        }
    
    //Segundo digito verificador
    soma = 0;
    j = 11;
    while (i < 10){
        soma += j * cpfint[i];
        i++;
        j--;
    }

    if (soma % 11 >= 2)
        verificador = 11 - (soma % 11);
    else
        verificador = 0;

    if (valido == 1)
        printf("CPF valido");
    else
        printf("CPF invalido");
}