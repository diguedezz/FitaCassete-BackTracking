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

int main(){

    FILE *inputFile;
    char filename[50];
    char row[10];
    char *output;
    char T[5], L[5], M[10], S[10];
    // int duracao, qntd, min, sec, N;
    int sec;

    printf("\n\nInsira o nome de um arquivo:\n");
    scanf("%s", filename);

    inputFile = fopen(filename, "r"); //linha de comando (fopen = open file, retorna ponteiro, por isso podemos criar a condição de tratamento abaixo)
    while (inputFile == NULL) //null é retornado quando não foi encontrado nenhum arquivo
    {
        printf("Não foi encontrado nenhum arquivo!\n\nInsira o nome de um arquivo válido:\n");
        scanf("%s", filename); 
        inputFile = fopen(filename, "r");
    }

    // while(feof(inputFile) == 0) //linha de comando (a função feof serve como controle para verificar se o arquivo ainda tem linhas a serem lidas)
    // {
    output = fgets(row, 10 ,inputFile);
    // N = atoi(output);
    printf("\n\nIniciando...");
    for(int i = 0; i < atoi(output); i++){
        fscanf(inputFile,"%s %s", T, L);
        // duracao = atoi(T);
        // qntd = atoi(L);
        printf("\n\n%d minutos\n", atoi(T));
        printf("\nLado A:\n");
        for(int j = 0; j< atoi(L); j++){
            fscanf(inputFile,"%s %s", M, S);
            // min = atoi(M);
            // sec = atoi(S);
            sec = (atoi(S) + atoi(M)*60);
            printf("%sm %ss // %dsec\n", M, S, sec);
        }
        printf("\nLado B:\ngood night!\n");
    }
    // printf("%d", N);
    // if (output)
        // printf("%s", row);

    fclose(inputFile);
    return 0;
}