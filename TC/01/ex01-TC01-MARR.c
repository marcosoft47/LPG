#include <stdlib.h>
#include <stdio.h>

int main(){
    float imc, peso, altura;

    printf("Informe o peso (em quilos): ");
    scanf("%f", &peso);
    printf("Informe a altura (em metros): ");
    scanf("%f", &altura);

    imc = peso/(altura*altura);

    printf("Valor do IMC: %.1f\n", imc);
    if (imc < 18.5){
        printf("Abaixo do peso ideal.");
    } else if (imc >= 18.5 && imc < 25)
    {
        printf("Peso normal");
    } else if (imc >= 25 && imc < 30)
    {
        printf("Acima do peso ideal");
    } else{
        printf("Obesidade");
    }
    printf("\n");
}