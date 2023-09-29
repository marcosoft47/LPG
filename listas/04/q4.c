#include <stdlib.h>
#include <stdio.h>
void calcula_hora(int minTotal, int *hora, int *min){
    //Quero garantir que não dê mais de 24 horas com o total de minutos.
    //Poderia tirar o while caso precisasse dar mais do que 24 horas
    //Um dia tem 1440 minutos
    while (minTotal >= 1440)
        minTotal -= 1440;
    *hora = minTotal / 60;
    *min = minTotal - (*hora*60);

}
int main(){
    int minTotal, min, hora;
    scanf("%i", &minTotal);
    calcula_hora(minTotal, &hora, &min);
    printf("%i:%i\n", hora, min);
}