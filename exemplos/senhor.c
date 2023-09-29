#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    char nome[255];
    char sexo[20];
    printf("Informe o nome: ");
    scanf("%s", nome);
    printf("Informe o sexo (masculino ou feminino): ");
    scanf("%s", sexo);

    if (strcmp(sexo, "masculino")==0){
        printf("%s. Sr.", nome);
    } else if(strcmp(sexo, "feminino")==0) {
        printf("%s. Sra.", nome);
    } else {
        //Não foi pedido, coloquei por colocar
        printf("Sexo invalido");
    }
}