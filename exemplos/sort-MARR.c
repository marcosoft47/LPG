#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    //Em muitos momentos eu podia usar funções;
    //Imprimir o vetor, reiniciar ele, trocar valores...;
    //Mas só de pensar em usar ponteiros, prefiro redundancia do que passar raiva;
    //Escrever redundancia não apenas me incomoda, como também é redundante;

    srand(time(NULL));
    int n, i, j, valor, randomico, temp;
    int countloop1 = 0, countloop2 = 0;

    int v[10] = {10,5,3,4,1,9,8,7,6,2};
    int vOriginal[10] = {10,5,3,4,1,9,8,7,6,2};
    n = 10;
    /*
    printf("Informe o tamanho do vetor: ");
    scanf("%i", &n);
    for (i = 0; i < n; i++)
    {
        randomico = rand();
        valor = 1 + randomico % 50;
        v[i] = valor;
        vOriginal[i] = valor;
    }*/
    for (i = 0; i < n; i++){printf("%i ", v[i]);}
    printf("\n");
    printf("\n");

    //Bubble Sort Sem menos i
    printf("Bubble Sort nao otimizado\n");
    for (i = 0; i < n; i++){
        for(j = 0; j < (n-1); j++){
            if (v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j + 1] = temp;
            }
            countloop1++;
        }
        countloop2++;
    }

    for (i = 0; i < n; i++){printf("%i ", v[i]);}
    printf("\nInner loop: %i Outer loop: %i\n\n", countloop1, countloop2);
    countloop1 = 0;
    countloop2 = 0;
    //Reiniciar vetor
    for (i = 0; i < n; i++){v[i] = vOriginal[i];}

    //Bubble Sort
    printf("Bubble Sort otimizado\n");
    for (i = 0; i < n; i++){
        for(j = 0; j < (n-i-1); j++){
            if (v[j] > v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j + 1] = temp;
            }
            countloop1++;
        }
        countloop2++;
    }

    for (i = 0; i < n; i++){printf("%i ", v[i]);}
    printf("\nInner loop: %i Outer loop: %i\n\n", countloop1, countloop2);
    countloop1 = 0;
    countloop2 = 0;
    for (i = 0; i < n; i++){v[i] = vOriginal[i];}

    //Insert Sort
    printf("Insert Sort\n");
    //Começando em 1 pois é redundante começar por 0;
    //Lembrete para o Marco do futuro ficar só no bubble sort mesmo;
    i=1;
    while (i < n){
        valor = v[i];
        //j vai encontrar a posição do primeiro número menor que valor
        j = i;
        while((v[j-1] > valor) && j > 0){
            v[j] = v[j-1];
            countloop1++;
            j--;
        }
        //Vamos usar a posição j para colocar o valor
        v[j]=valor;
        countloop2++;
        i++;
    }
    for (i = 0; i < n; i++){printf("%i ", v[i]);}
    printf("\nInner loop: %i Outer loop: %i\n\n", countloop1, countloop2);
    countloop1 = 0;
    countloop2 = 0;

    for (i = 0; i < n; i++){v[i] = vOriginal[i];}

    //Selection Sort
    printf("Selection Sort\n");
    int posMenor;
    i=0;
    while (i < n){
        j=0;
        posMenor = i;
        while (j < (n-i)){
            if (v[posMenor] > v[i+j]){
                posMenor = i + j;
            }
            countloop1++;
            j++;
        }
        temp = v[i];
        v[i] = v[posMenor];
        v[posMenor] = temp;
        countloop2++;
        i++;
    }
    for (i = 0; i < n; i++){printf("%i ", v[i]);}
    printf("\nInner loop: %i Outer loop: %i\n\n", countloop1, countloop2);
}