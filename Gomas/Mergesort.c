#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy(int *a, int *b, int F, int L) {
    for (int i = F; i <= L; i++) {
        b[i] = a[i-F];
    }
}

void comb(int *v, int F, int M, int L) {
    int i = F, j = M + 1, k = 0;
    int *vaux;
    vaux = (int*) malloc(sizeof(int)*(L-F+1));

    while(i <= M && j<= L){
        if(v[i] < v[j])
            vaux[k] = v[i++];
        else
            vaux[k] = v[j++];
        k++;
    }
    while (i <= M)
        vaux[k++] = v[i++];
    while (j <= L)
        vaux[k++] = v[j++];
    copy(vaux, v, F, L);
}

void mergesort(int *v, int F, int L) {
    int M = (F+L)/2;
    if(F == L)
        return;
    else{
        mergesort(v, F, M);
        mergesort(v, M + 1, L);
        comb(v, F, M, L);
    }
}

int main(int argc, char const *argv[]) {
    int w[20];
    srand(time(NULL));
    for (int i = 0; i < 20; i++) {
        w[i] = rand()%20;
    }

    mergesort(w, 0, 19);
    for (int i = 0; i < 20; i++) {
        printf("%d ", w[i]);
    }
    printf("\n");

  return 0;
}
