#include <stdio.h>
#include <stdlib.h> /* rand() e srand() */
#include <time.h> /* time() */

int main(void) {
    // Comentário #01
    int x, *p;
    x = 100;
    p = &x; // Qual é o erro nesta linha???
    printf("Valor de p: %d.\n", *p);

    // Comentário 02
    srand(time(NULL));
    int w, y, z;
    y = 100;
    z = 0;
    w = z + rand()%y; // valores entre 0 e 99
    printf("\n\nValor aleatório:\nw = %d\n", w);
    
    return 0;
}