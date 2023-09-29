#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LSIZE 4
#define CSIZE 4
int main(){
    srand(time(NULL));
    int m[LSIZE][CSIZE], mTrans[CSIZE][LSIZE], m2[LSIZE][CSIZE], mSoma[LSIZE][CSIZE], soma = 0;
    for (int i = 0; i < LSIZE; i++){
        for (int j = 0; j < CSIZE; j++){
            m[i][j] = rand() % 50;
            m2[i][j] = rand() % 50;
        }
    }

    for (int i = 0; i < LSIZE; i++){
        for (int j = 0; j < CSIZE; j++){
            mTrans[j][i] = m[i][j];
            if (m[i][j] % 2 == 0)
                soma += m[i][j];
        }
    }

    for (int i = 0; i < LSIZE; i++){
        for (int j = 0; j < CSIZE; j++){
            mSoma [i][j] = m[i][j] + m2[i][j];
        }   
    }
    
    

    
    /*
    for (int i = 0; i < LSIZE; i++){
        for (int j = 0; j < CSIZE; j++){
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }*/
}