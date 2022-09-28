#include <stdio.h>
#include <stdbool.h>

// variavel global
int seq = 1;
// declaracao de funcoes
int geraSequencias(int a[], int s[], int n, int i, int duracao);
bool valida(int s[],int i);
bool imprima(int v[], int n, int duracao);

// int main(){

//     int a[] = {0,1,2,3};
//     int s[] = {0,0,0,0};
//     geraSequencias(a, s, 3, 1);
//     return 0;

// }
/*
Enumerar todas as sequ�ncias poss�veis de 3 d�gitos,
*/

// class Permutation{
//     private:
//         int seq = 1;
//     public:
//         void geraSequencias(int a[], int s[], int n, int i){

//         }
// }

int geraSequencias(int a[], int s[], int n, int i, int duracao){

    if( i > n ){ // caso base
        if(imprima(s,n,duracao)){
            return 0;
        }
    }
    else{
        for(int j=1; j <=n; j++){
            s[i] = a[j];
            if(valida(s,i))
                geraSequencias(a,s,n,i+1,duracao);
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
bool imprima(int v[], int n, int duracao){
    int soma = 0;
    int outrasoma = 0;
    int metade = duracao/2;
    int j = 1;
    int count = 0;
    int x1[] = {};
    int x2[] = {};

    while( j <= n){
        if(soma <= metade){
            if(soma + v[j] <= metade){
                soma += v[j];
                
            }else{
                outrasoma += v[j];
            }
        }else{
            outrasoma += v[j];
        }
        j++;
    }
    
    for( int i = 1; i <= n; i++){
        if(soma <= metade){
            if(outrasoma <= metade){
                count += 1;
                printf("%d\n",v[i]);
            }
        }else{
            break;
        }
    }

    if(count == 0){
        return true;
    }else return false;
}

