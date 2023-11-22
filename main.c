#include <stdio.h>
#include <string.h>

//struct com shorts para utilizar na soma()
typedef struct{
    short numCS;
    short numSS;
    short num;
    short nunsAS;
} contagem;

//Função está sendo guardada em um struct para voltar valores do mesmo
contagem soma(char *st1, const char *st2){
    //constante que guarda a posição do primeiro caracter de st1
    const char *st1A = st1;
    
    //coloca o st1 na ultima posição de carcter
    while(*st1 != '\0'){
        st1++;
    }
    
    //Concatena st1 e st2(soma as strings)
    while(*st2 != '\0'){
        *st1 = *st2;
        st1++;
        st2++;
    }
    
    //coloca um fim em sua ultima posição para evitar problemas no console
    *st1 = '\0';
    //volta st1 para a primeira posição
    st1 = st1A;
    
    //estou colocando um valor nos shorts do struct para não dar erro na função
    contagem conta = {0, 0, 0, 0};
    //cria um short de valor 0 dentro da função
    short primeiroS = 0;
    //um loop para dar valores para os shorts de struct
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
    
    //retorna os valores obtidos por struct dentro da função com objetivo de tiralo do escopo
    return conta;
}

int main(){
    //a primeira palavra com um limite de caracters
    char palavraR[51];
    //o fim da string
    const char fim[] = " mundo";
    
    //manda msg para o console d titulo do jogo
    printf("************************************************");
    printf("\nescreva uma palavra com no max 50 caracters.\n");
    printf("************************************************\n\n");
    
    //lê o console e armazena a string no palaraR
    fgets(palavraR, sizeof(palavraR), stdin);
    //Tira a quebra de linha que é colocado ao armazenar a string
    palavraR[strcspn(palavraR,  "\n")] = '\0';

    //chama a função soma e armazna os valores obtidos no resultado que é a struct criada porem sem os valores por eles estarem armazenados dentro do escopo soma()
    contagem resultado = soma(palavraR, fim);
    //Escreve na tela os valores obtidos com a frase do cliente
    printf("\nSua frase foi '%s'.\nCom %d caracters.\n%d caracters tirando os espaços.\nE com %d caracters antes do primeiro espaço.\n\n", palavraR, resultado.num, resultado.numSS, resultado.nunsAS);
}