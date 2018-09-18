#include <stdio.h>
#include <stdlib.h>

void FinnJake(int n){
    if (n % 2 == 0)
        printf("Finn\n");
    else
        printf("Jake\n");
}

void copy(int *a, int *b, int F, int L) {
    for (int i = F; i <= L; i++) {
        b[i] = a[i-F];
    }
}
int comb(int *v, int F, int M, int L) {
    int i = F, j = M + 1, k = 0;
    int *vaux;
    int counter = 0;
    vaux = (int*) malloc(sizeof(int)*(L-F+1));

    while(i <= M && j<= L){
        if(v[i] < v[j])
            vaux[k] = v[i++];
        else{
            vaux[k] = v[j++];
            counter = counter + M - i + 1;
        }
        k++;
    }
    while (i <= M)
        vaux[k++] = v[i++];
    while (j <= L)
        vaux[k++] = v[j++];
    copy(vaux, v, F, L);
    //printf("Counter cob:%d\n", counter);
    return counter;
}

int mergesort(int *v, int F, int L) {
    int counter = 0;
    int M = (F+L)/2;
    if(F == L)
        return 0;
    else{
        counter = mergesort(v, F, M);
        counter += mergesort(v, M + 1, L);
        counter += comb(v, F, M, L);
    }
    return counter;
}

void Fill(int *vec, int size){
    for (int i = 0; i < size; i++)
        scanf("%d", &vec[i]);

}

int main(int argc, char const *argv[]) {
    int size, *gomas;
    int Inv = 0;
    scanf("%d", &size);
    gomas = (int *) malloc(sizeof(int)*size);
    Fill(gomas,size);
    while (size > 0) {
        Inv = mergesort(gomas,0,size-1);
        FinnJake(Inv);
        free(gomas);
        scanf("%d", &size);
        gomas = (int *) malloc(sizeof(int)*size);
        Fill(gomas,size);
    }

  return 0;
}
