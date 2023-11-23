#include <stdio.h>
#include <string.h>

int main(){
    char palavraR[51];
    const char fim[] = " mundo";
    
    printf("**********************************************");
    printf("\nescreva uma palavra com no max 50 caracters.\n");
    printf("**********************************************\n\n");
    
    fgets(palavraR, sizeof(palavraR), stdin);
    palavraR[strcspn(palavraR,  "\n")] = '\0';

    strcat(palavraR, fim);
    size_t tamanho = strlen(palavraR);

    printf("\nSua frase foi '%s'.\nCom %zu caracters.\n\n", palavraR, tamanho);
}