#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    float v[3], a, b, c;
    int temp;
    scanf("%f%f%f", &v[0], &v[1], &v[2]);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            if (v[j] < v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j + 1] = temp;
            }
        }
    }
    //printf("%f %f %f", v[0], v[1], v[2]);
    a = v[0];
    b = v[1];
    c = v[2];
    if (a >= b +c)
        printf("Nao forma triangulo\n");
    else{
        if (a*a == b*b + c*c)
            printf("Triangulo Retangulo\n");
        else if (a*a > b*b + c*c)
            printf("Triangulo Obtusangulo\n");
        else if (a*a < b*b + c*c)
            printf("Triangulo Acutangulo\n");
        
        if (a == b && b == c)
            printf("Triangulo Equilatero\n");
        else if (a == b || b == c)
            printf("Triangulo Isosceles\n");
    }
}