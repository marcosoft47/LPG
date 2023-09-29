#include <stdio.h>
#include <stdlib.h>

int tipo_triangulo (float a, float b, float c){
    //Não foi pedido, mas vou colocar condição de existência de triangulos
    if ((a + b < c) || (a + c < b) || (b + c < a)){
        return 0; //Não é triangulo
    } else {
        if (a == b && b == c)
            return 1; //Equilatero
        else if (a == b || b == c || c == a)
            return 2; // Isosceles
        else
           return 3; // Escaleno
        
    }
    return 0;
}

int main(){
    float a, b, c;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    int tipo = tipo_triangulo(a, b, c);
    switch (tipo)
    {
    case 1:
        printf("Equilatero");
        break;
    case 2:
        printf("Isosceles");
        break;
    case 3:
        printf("Escaleno");
        break;
    default:
        break;
    }
    printf("\n");
}