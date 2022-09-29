/********************************************************************/
/*              Universidade Presbiteriana Mackenzie                */
/*                                                                  */        
/*              Ciência da Computação                               */
/*              Projeto e Análise de Algoritmos II                  */
/*                                                                  */
/*              Turma 04N                                           */
/*              Diego Guedes de Moraes - (TIA: 32148127)            */
/*                                                                  */
/*              Data: 28 de setembro de 2022.                       */
/*                                                                  */
/********************************************************************/



// ENTRADA
// N conjuntos de teste
// T indica tempo total em min da fita
// L inidica quantas musicas serao avaliadas
// M S indica minutos e segundos da musica
// 0 <= M,S <= 59
// SAÍDA
// soma minutos lado A + lado B
// lado A + musicas lado B + musicas
#include <stdio.h>
#include <unistd.h>
#include "geraPermutacao.c"


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
        
        int store[atoi(L)];
        int aux[atoi(L)];
        int duracao = atoi(T)*60;

        for(int j = 1; j <= atoi(L); j++){
            fscanf(inputFile,"%s %s", M, S);
            store[j] = (atoi(S)+ atoi(M)*60);
        }


    geraSequencias(store,aux,atoi(L),1,duracao);
    }
    
    printf("\n\n%s",enfeite1);
    fclose(inputFile);
    return 0;
}