#include <stdio.h>
#include <stdbool.h>

// variavel global
int seq = 1;
// declaracao de funcoes
void geraSequencias(int a[], int s[], int n, int i);
bool valida(int s[],int i);
void imprima(int v[], int n);

int main(){

    int a[] = {0,1,2,3};
    int s[] = {0,0,0,0};
    geraSequencias(a, s, 3, 1);
    return 0;

}
/*
Enumerar todas as sequ�ncias poss�veis de 3 d�gitos,
*/
void geraSequencias(int a[], int s[], int n, int i){
    if( i > n ) // caso base
        imprima(s,n);
    else{
        for(int j=1; j <=n; j++){
            s[i] = a[j];
            if(valida(s,i))
                geraSequencias(a,s,n,i+1);
        }
    }

}
// verifica se o elemento de s[i] j� foi inserido no vetor s[1..i-1],
// caso s[i]==s[1..i-1] retorna false
// caso contrario retorna true
bool valida(int s[],int i){
    for( int j=1; j < i; j++)
        if(s[i]==s[j])
            return false;

    return true;

}
// imprime o vetor na tela
void imprima(int v[], int n){
    printf("%03d: ",seq++);
    for( int i = 1; i <= n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

