/********************************************************************/
/*              Universidade Presbiteriana Mackenzie                */
/*                                                                  */        
/*              Ciência da Computação                               */
/*              Projeto e Análise de Algoritmos II                  */
/*                                                                  */
/*              Turma 04N                                           */
/*              Diego Guedes de Moraes - (TIA: 32148127)            */
/*                                                                  */
/*              Data: 21 de outubro de 2022.                        */
/*                                                                  */
/********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// declaracao de funcoes
int geraSequencias(int a[], int s[], int n, int i, int duracao, int teste);
int valida(int s[],int i);
int imprima(int v[], int n, int duracao,int teste);
// ENTRADA
// N conjuntos de teste
// T indica tempo total em min da fita
// L inidica quantas musicas serao avaliadas
// M S indica minutos e segundos da musica
// 0 <= M,S <= 59
// SAÍDA
// soma minutos lado A + lado B
// lado A + musicas lado B + musicas

int main(){

    FILE *inputFile;
    char filename[50];
    char row[10];
    char *output;
    char T[5], L[5], M[10], S[10];
    char enfeite1[31] = "==============================";
    
    printf("\n\nInsira o nome de um arquivo:\n");
    scanf("%s", filename);

    inputFile = fopen(filename, "r"); //linha de comando (fopen = open file, retorna ponteiro, por isso podemos criar a condição de tratamento abaixo)
    while (inputFile == NULL) //null é retornado quando não foi encontrado nenhum arquivo
    {
        printf("Não foi encontrado nenhum arquivo!\n\nInsira o nome de um arquivo válido:\n");
        scanf("%s", filename); 
        inputFile = fopen(filename, "r");
    }

    output = fgets(row, 10 ,inputFile);
    int out = atoi(output);
    printf("\n\nIniciando...");
    for(int i = 0; i < out; i++){
        sleep(1);
        fscanf(inputFile,"%s %s", T, L);
        printf("\n\n%s\n\nTeste %d\n%d minutos\n\n",enfeite1,i+1,atoi(T));
        
        int *store = (int*) (calloc(atoi(L),sizeof(int)));
        int *aux = (int*) (calloc(atoi(L),sizeof(int)));
        int duracao = atoi(T)*60;
        int combinatoria = 0;

        for(int j = 0; j < atoi(L); j++){
            fscanf(inputFile,"%s %s", M, S);
            store[j] = (atoi(S)+ atoi(M)*60);
        }

        for(int j = 0; j < atoi(L); j++){
            for(int k = 0; k < atoi(L) -1; k++){
                if(store[j] == store[k]){
                    combinatoria++;            
                }
            }
        }

    combinatoria = combinatoria - atoi(L);
    if(geraSequencias(store,aux,atoi(L),0,duracao,combinatoria)!= 1){
        printf("\nImpossivel gravar todas as musicas nessa fita!\n");}
    }

    printf("\n\n%s",enfeite1);
    fclose(inputFile);
    return 0;
}

//função editada para devolver apenas uma permutação.
int geraSequencias(int a[], int s[], int n, int i, int duracao, int teste){
    if(teste < 0){ //UTILIZANDO PERMUTAÇÃO PARA MUSICAS DE DURACAO DIFERENTE
        if( i == n ){ // caso base
            if(imprima(s,n,duracao,teste) != -1){
                return 1;
            }
        }else{
            for(int j=0; j < n; j++){
                s[i] = a[j];
                if(valida(s,i) == 1){
                    if (geraSequencias(a,s,n,i+1,duracao,teste) == 1){
                        return 1;
                    }
                }
            }
        }
    }else{ //UTILIZANDO COMBINAÇÃO PARA MUSICAS DE DURACAO IGUAIS, APENAS REMOVI A FUNÇÃO VALIDAÇÃO E O LAÇO FOR
        if( i == n ){ // caso base
            if(imprima(s,n,duracao,teste) != -1)
                return 1;
            }else{
                s[i] = a[i];
                if (geraSequencias(a,s,n,i+1,duracao,teste) == 1)
                    return 1;
        }
    }
}

//A FUNÇÃO VALIDA SO SERA UTILIZADA PARA PERMUTAÇÃO
int valida(int s[],int i){
    for( int j=0; j < i; j++)
        if(s[i]==s[j])
            return 0;
    return 1;

}

int imprima(int v[], int n, int duracao, int teste){

    int soma = 0;
    int soma2 = 0;
    int metade = duracao/2;

    int j = 0, auxJ;

    if(teste < 0){
        while(j < n){
            if(soma + v[j] <= metade && soma2 == 0){
                soma += v[j];
            }else{
                if(soma2 + v[j] <= metade){
                    if(soma2 == 0){
                        auxJ = j-1;
                    }
                    soma2 += v[j];
                }else{
                return -1;
                }
            }
            j++;
        }

        int i = 0;

        printf("\nParte A:\n");
        while(i<n){
            if(i <= auxJ){
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }else if(i == auxJ+1){
                printf("\nParte B:\n");
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }else if(i > auxJ+1){
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }
            i++;
        }
    }
    
    
    else{ //IMPRIMA USADO PARA COMBINAÇÃO

        while(j < n){
            if(soma + v[j] <= metade){
                soma += v[j];
            }else{
                if(soma2 + v[j] <= metade){
                    if(soma2 == 0){
                        auxJ = j-1;
                    }
                    soma2 += v[j];
                }else{
                    return -1;
                }
            }
            j++;
        }

        int i = 0;

        printf("\n%d Parte A:\n", auxJ);
        while(i<n){
            if(i <= auxJ){
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }else if(i == auxJ+1){
                printf("\nParte B:\n");
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }else if(i > auxJ+1){
                printf("%dm %ds\n", (v[i])/60, v[i]%60);
            }
            i++;
        }
    }
    return 1;
}
