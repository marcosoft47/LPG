#include <stdio.h>
#include <stdlib.h>
int contador = 0;
int fatorial(int x){
    if (x == 0)
        return 1;
    else
        return x*fatorial(x-1);
    return 0;
}
int potenciacao(int x, int power){
    if (power == 0)
        return 1;
    else if (power < 0)
        potenciacao((1/x), power-1);
    else
        return x * potenciacao(x, power-1);
    return 0;
}
int fibonacci(int n){
    contador++;
    if (n <= 2){
        return 1;
    }
    else {
        return fibonacci(n-1) + fibonacci (n-2);
    }
}
int main(){
    int x, n;
    printf("X = ");
    scanf("%i", &x);
    printf("N = ");
    scanf("%i", &n);

    printf("\n");
    printf("%i! = %i\n", x, fatorial(x));
    printf("%i^%i = %i\n", x, n, potenciacao(x, n));
    printf("%i° termo da seq. de Fibonacci = %i\n", x, fibonacci(x));
    printf("Contador fibonacci: %i\n", contador);
}