#include <stdlib.h>
#include <stdio.h>
void inc_dec (int *a, int *b){
    printf("%i %i\n", *a,*b);
    *a+=1;
    *b-=1;
}
int main(){
    int a = 2, b  = 4;
    int *pa = a, *pb = b;
    inc_dec(&a, &b);
    printf("%i %i\n", a, b);
}