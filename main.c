#include <stdio.h>
#include <string.h>

int soma(char *st1, const char *st2){
    const char *st1A = st1;
    
    while(*st1 != '\0'){
        st1++;
    }
    
    while(*st2 != '\0'){
        *st1 = *st2;
        st1++;
        st2++;
    }
    
    short comprimento = st1;
    *st1 = '\0';
    
    return comprimento;
}

int main(){

    char palavraR[51];
    const char fim[] = " mundo";
    
    printf("****************");
    printf("\nescreva uma palavra com no max 50 caracters.\n");
    printf("****************\n\n");
    
    fgets(palavraR, sizeof(palavraR), stdin);
    palavraR[strcspn(palavraR,  "\n")] = '\0';
    printf(" \n%s\n\n", palavraR);
    int comp = soma(palavraR, fim);
    
    printf("\n %d\n\n", comp);
    //printf("\nSua frase foi '%s' \nCom %d caracters e %d tirando os espaços e com %d caracters antes do primeiro espaço.\n");
}