#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//criei função com 2 ponteiros para as strings que irei utilizar
void somas(char *string1, const char *string2){


    while(*string1 != '\0'){
        string1++;
    }

    while (*string2 != '\0'){
        *string1 = *string2;
        string1++;
        string2++;
    }
    
    *string1 = '\0';

    size_t primeirosCaracterSemEspaco = strcspn(string1, " ");

    string1 = 0;
    short numSemEspacos = 0;
    short numComEspacos = 0;

    while(*string1 != '\0'){

        if(*string1 != ' '){
            numComEspacos++;
        }else{
            numSemEspacos++;
        } 
    }
}

int main(){


    char st1[61];
    printf("Escreva uma frase\n\n");

    fgets(st1, sizeof(st1), stdin);


    //system("cls");
    //printf("\nSua frase foi '%s' \nCom %d caracters e %d tirando os espaços e com %d caracters antes do primeiro espaço.\n");
}