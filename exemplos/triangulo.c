#include <stdlib.h>
#include <stdio.h>
int main(){
    float a, b, c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    //Não foi pedido, mas vou colocar condição de existência de triangulos
    if ((a + b < c) || (a + c < b) || (b + c < a)){
        printf("Nao é triangulo.");
    } else {
        if (a == b && b == c){
            printf("Equilatero");
        }else if (a == b || b == c || c == a){
            printf("Isosceles");}
        else{
            printf("Escaleno");
        }
    }
}