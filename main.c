#include <stdio.h>
#include <string.h>

struct contagem{
    short numCS;
    short numSS;
    short num;
    short nunsAS;
};

struct contagem soma(char *st1, const char *st2){
    const char *st1A = st1;
    
    while(*st1 != '\0'){
        st1++;
    }
    
    while(*st2 != '\0'){
        *st1 = *st2;
        st1++;
        st2++;
    }
    
    *st1 = '\0';
    
    //return (st1 - st1A);
    
    st1 = st1A;
    
    struct contagem conta = {0, 0, 0, 0};
    short primeiroS = 0;    
    while(*st1 != '\0'){
        if(*st1 != ' '){
            conta.numSS++;
            st1++;
            
            if(primeiroS == 0){
                conta.nunsAS++;
            }
        }else{
            conta.numCS++;
            st1++;
            primeiroS++;
        }
        conta.num++;
    }
    
    return conta;
}

int main(){

    char palavraR[51];
    const char fim[] = " mundo";
    
    printf("******");
    printf("\nescreva uma palavra com no max 50 caracters.\n");
    printf("******\n\n");
    
    fgets(palavraR, sizeof(palavraR), stdin);
    palavraR[strcspn(palavraR,  "\n")] = '\0';
    printf(" \n%s\n\n", palavraR);
    struct contagem resultado = soma(palavraR, fim);
    
    printf("\n %s\n\n", palavraR);
    printf(" %d\n", resultado.nunsAS);
    printf("\nSua frase foi '%s'.\nCom %d caracters.\nE %d caracters tirando os espaços.\nE com %d caracters antes do primeiro espaço.\n\n", palavraR, resultado.num, resultado.numSS, resultado.nunsAS);
}