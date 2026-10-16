#include <stdio.h>

int men(int a, int b) {

    int menor;

    menor = a;
    if(b < menor) {
        menor = b; 
    }

    return menor;
}

int main() {

int v1, v2, menor;

printf("Digite um numero: "); scanf("%d\n", &v1);
printf("Digite um segundo numero: "); scanf("%d\n", &v2);

menor = men(v1, v2);

printf("O menor valor foi o: %d\n", menor);
    return 0;
}