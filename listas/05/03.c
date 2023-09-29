#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int *busca(int *v, int n, int chave){
    for (int i = 0; i < n; i++){
        if (v[i] == chave)
            return i;
    }
    return -1;
}
int main(){
    srand(time(NULL));
    int n = 5;
    int i, v[n];

    for (i = 0; i < n; i++)
        v[i] = rand() % (n * 2);
    int x = v[rand() % n];
    int pos = busca(v, n, x);
    printf("%i\n", pos);
}