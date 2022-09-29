#include <stdio.h>
#include <stdbool.h>

// declaracao de funcoes
void geraSequencias(int a[], int s[], int n, int i, int duracao);
bool valida(int s[],int i);
void imprima(int v[], int n, int duracao);


void geraSequencias(int a[], int s[], int n, int i, int duracao){

    if( i > n ){ // caso base
        imprima(s,n,duracao,);
        }
    else{
        for(int j=1; j <= n; j++){
            s[i] = a[j];
            if(valida(s,i))
                geraSequencias(a,s,n,i+1,duracao);
        }
    }
}

bool valida(int s[],int i){
    for( int j=1; j < i; j++)
        if(s[i]==s[j])
            return false;

    return true;

}

// imprime o vetor na tela
void imprima(int v[], int n, int duracao){

    int soma = 0;
    int outrasoma = 0;
    int metade = duracao/2;
    int j = 1;

    while( j <= n){
        if(soma <= metade){
            if(soma + v[j] <= metade){
                soma += v[j];
                printf("A: %d ", v[j]);
                // parteA[j] = v[j];
            }else{
                outrasoma += v[j];
                printf("B: %d ", v[j]);
                // parteB[j] = v[j];
            }
        }else{
            outrasoma += v[j];
            printf("B: %d ", v[j]);
            // parteB[j] = v[j];
        }
        j++;
    }
    printf("\n");
}