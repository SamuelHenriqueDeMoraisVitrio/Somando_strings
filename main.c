#include <stdio.h>

//criei função com 2 ponteiros para as strings que irei utilizar
void somaS(char *string1, const char *string2){

    while(*string1 != '\0'){
        string1++;
    }

    while (*string2 != '\0'){
        string1 = string2;
        string1++;
        string2++;
    }
}

int main(){

    printf("\nola mundo\n");
}