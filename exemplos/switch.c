#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%i", &n);

    switch (n)
    {
    case 1:
        printf("Um");
        break;
    case 2:
    case 3:
        printf("Dois ou Três");
        break;
    case 4 ... 10:
        printf("Entre Quatro e Dez");
        break;
    default:
        break;
    }
}