#include <stdio.h>
#include <stdbool.h>

// declaracao de funcoes
void geraSequencias(int a[], int s[], int n, int i, int duracao);
bool valida(int s[],int i);
void imprima(int v[], int n, int duracao);


void geraSequencias(int a[], int s[], int n, int i, int duracao){

    if( i > n ){ // caso base
        // imprima(s,n,duracao);
        return imprima(s,n,duracao);
        }
    else{
        for(int j=1; j <= n; j++){
            s[i] = a[j];
            if(valida(s,i)){
                // imprima(s,n,duracao);
                // break;
            // }else {
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


// imprime o vetor na tela
// void imprima(int v[], int n, int duracao){

//     int soma = 0;
//     int outrasoma = 0;
//     int metade = duracao/2;
//     int j = 1;
//     int vetorA[] = {};
//     int vetorB[] = {};

//     int contA = 0;
//     int contB = 0;


//     while( j <= n){
//         if(soma <= metade){
//             if(soma + v[j] <= metade){
//                 soma += v[j];
//                 vetorA[contA] = v[j];
//                 contA += 1;
//             }else{
//                 outrasoma += v[j];
//                 vetorB[contB] = v[j];
//                 contB += 1;
//             }
//         }else{
//             outrasoma += v[j];
//             vetorB[contB] = v[j];
//             contB += 1;
//         }
//         j++;
//     }

//     printf("\nParte A: %d\n", contA);
//     for(int i = 0; i < contA; i++){
//         printf("%d/%d\n", vetorA[i], v[i]);
//     }
//     printf("\nParte B: %d\n", contB);
//     for(int i = 0; i < contB; i++){
//         printf("%d/%d\n", vetorB[i], v[i]);
//     }
//     printf("\n");
// }

void imprima(int v[], int n, int duracao){

    int soma = 0;
    int soma2 = 0;
    int metade = duracao/2;
    int j = 1;

    int contA = 0;
    int contB = 0;

    while( j <= n){
        // if(soma <= metade){
            if(soma + v[j] <= metade){
                soma += v[j];
                // printf("A: %d ", v[j]);
                contA = contA + 1;
                // parteA[j] = v[j];
            }else{
                // printf("B: %d ", v[j]);
                // parteB[j] = v[j];
                contB = contB + 1;
            }
        j++;
    }
    // printf("\ncontA:%d\ncontB:%d\n\n",contA,contB);

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
            // printf("A: %d / %d ", v[j], vetorA[contA]);
            // contA = contA + 1;
            // parteA[j] = v[j];
        }else{
            soma2 += v[j];
            vetorB[contB] = v[j];
            contB = contB + 1;
            // printf("B: %d / %d ", v[j], vetorB[contB]);
            // parteB[j] = v[j];
            // contB = contB + 1;
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
        printf("\nImpossível gravar todas as músicas nessa fita!\n");
    }
}

