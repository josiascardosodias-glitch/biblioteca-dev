#include<stdio.h>

#define TAM 10


main() {
    float vet[TAM], med;
    le_Vetor(vet);
    med = media_Vetor(vet);
    escreve_vetor(vet);
    printf("media = %.2f", med);
    
    return 0;
}