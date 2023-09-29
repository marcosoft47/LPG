#include <stdio.h>
#include <stdlib.h>
void converter(int tempo, int *horas, int *minutos, int *segundos){
    *horas = tempo / 3600;
    *minutos = (tempo - (*horas)*3600) / 60;
    *segundos = tempo - (*horas)*3600 - (*minutos)*60;
}
int main(){
    int tempo = 0, hor = 0, min = 0, seg = 0;
    int *horas = &hor, *minutos = &min, *segundos = &seg;
    
    printf("Informe o tempo: ");
    scanf("%i", &tempo);
    converter(tempo, horas, minutos, segundos);
    printf("%d horas, %d minutos e %d segundos", *horas, *minutos, *segundos);
}