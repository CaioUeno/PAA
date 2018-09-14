#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equivalent(char *string_1, char *string_2, int size){
    int flag1 = 0, flag2 = 0;
    //printf("String 1: %s\n", string_1);
    //printf("String 2: %s\n", string_2);
    if (size == 1)
        return *string_1 == *string_2;
    if (strncmp(string_1,string_2,size) == 0) //Verifica se são iguais
        return 1;
    else {
        flag1 = equivalent(string_1, string_2+(size/2), size/2);
        flag2 = equivalent(string_1+(size/2), string_2, size/2);
        if (flag1 == 1 && flag2 == 1)
            return 1;
    }
    return 0;
}

void answer(int R) {
    if(R)
        printf("SIM\n");
    else
        printf("NAO\n");
}

int main(int argc, char const *argv[]) {
    char *DNA1, *DNA2;
    int size = 1;
    //printf("Tamanho das strings a serem analisadas:\n");
    scanf("%d", &size);
    while(size > 0) {
        DNA1 = (char *) malloc(sizeof(char)*(size+1));
        DNA2 = (char *) malloc(sizeof(char)*(size+1));
        //printf("As cadeias a serem analisadas:\n");
        scanf("%s %s", DNA1, DNA2);

        answer(equivalent(DNA1,DNA2,size));
        //printf("Tamanho das strings a serem analisadas:\n");
        scanf("%d", &size);
    }

  return 0;
}
