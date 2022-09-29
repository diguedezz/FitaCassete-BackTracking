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


#include <stdio.h>
#include <stdbool.h>

// declaracao de funcoes
void geraSequencias(int a[], int s[], int n, int i, int duracao);
bool valida(int s[],int i);
void imprima(int v[], int n, int duracao);


//função editada para devolver apenas uma permutação.
void geraSequencias(int a[], int s[], int n, int i, int duracao){
    if( i > n ){ // caso base
        return imprima(s,n,duracao);
        }
    else{
        for(int j=1; j <= n; j++){
            s[i] = a[j];
            if(valida(s,i)){
                return geraSequencias(a,s,n,i+1,duracao);
            }
        }
    }
}

bool valida(int s[],int i){
    for( int j=1; j < i; j++)
        if(s[i]==s[j])
            return false;

    return true;

}

void imprima(int v[], int n, int duracao){

    int soma = 0;
    int soma2 = 0;
    int metade = duracao/2;
    int j = 1;

    int contA = 0;
    int contB = 0;

    while( j <= n){
            if(soma + v[j] <= metade){
                soma += v[j];
                contA = contA + 1;
            }else{
                contB = contB + 1;
            }
        j++;
    }

    int vetorA[contA];
    int vetorB[contB];
    j = 0;
    contA = 0;
    contB = 1;
    soma = 0;

    while(j <= n){
        if(soma + v[j] <= metade){
            soma += v[j];
            vetorA[contA] = v[j];
            contA = contA + 1;
        }else{
            soma2 += v[j];
            vetorB[contB] = v[j];
            contB = contB + 1;
        }
        j++;
    }

    if(soma <= metade && soma2 <= metade){
        printf("\nParte A:\n");
        for(int i = 1; i < contA; i++){
            printf("%dm %ds\n", (vetorA[i])/60, vetorA[i]%60);
        }
        printf("\nParte B:\n");
        for(int i = 1; i < contB; i++){
            printf("%dm %ds\n", (vetorB[i])/60, vetorB[i]%60);
        }
        printf("\n");
    }else{
        printf("\nImpossivel gravar todas as musicas nessa fita!\n");
    }
}

