#include <stdlib.h>
#include <stdio.h>

int main(){
    //Duas linhas para separar o questionário das outras variáveis.
    float totalQuilo, custoLitro, mediaQuiloLitro, precoEsta, gastoPeda;
    float valorTotal;

    printf("Informe:\n");
    printf("Total de quilometros percorridos por dia: ");
    scanf("%f", &totalQuilo);
    printf("O preco do litro do combustivel: ");
    scanf("%f", &custoLitro);
    printf("A media de quilometros percorridos por litro do automovel: ");
    scanf("%f", &mediaQuiloLitro);
    printf("O preco do estacionamento por dia: ");
    scanf("%f", &precoEsta);
    printf("O gasto com pedagio por dia: ");
    scanf("%f", &gastoPeda);

    valorTotal = ((totalQuilo / mediaQuiloLitro) * custoLitro) + precoEsta + gastoPeda;

    printf("No total, eh gasto R$%.2f por dia.\n", valorTotal);
}