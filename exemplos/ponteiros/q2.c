#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void calcularRaiz(int a, int b, int c, double *r1, double *r2){
    int raizDelta = sqrt(b*b - 4*a*c);
    *r1 = (-b + raizDelta)/(2*a);
    *r2 = (-b - raizDelta)/(2*a);
}
int main(){
    //raiz = 2 e 3;
    int a, b, c;
    double raiz1 = 0, raiz2 = 0;
    double *r1 = &raiz1, *r2 = &raiz2;
    printf("Informe a: ");
    scanf("%i", &a);
    printf("Informe b: ");
    scanf("%i", &b);
    printf("Informe c: ");
    scanf("%i", &c);

    calcularRaiz(a, b, c, r1, r2);

    printf("Raizes: %.2f e %.2f", *r1, *r2);
}