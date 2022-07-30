#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex06.h"

int main(){
    Racional *R1, *R2;
    int a, b, x, y;
    double somatoria, multiplicacao;

    int escolha = 1;

    while(escolha == 1){
        //Recebe os valores da primeira fracao
        printf("\n\t- Primeira fracao -\n");
        printf("\tInforme o numerador: ");
        scanf("%d", &a);
        printf("\tAgora, o denominador: ");
        scanf("%d", &b);
        R1 = criaR(a, &b);

        //Recebe os valores da segunda fracao
        printf("\n\t- Segunda fracao -\n");
        printf("\tInforme o numerador: ");
        scanf("%d", &x);
        printf("\tAgora, o denominador: ");
        scanf("%d", &y);
        R2 = criaR(x, &y);

        //Exibicao dos valores racionais
        printf("\n\n\tPrimeira fracao: ");
        imprimiR(R1);
        printf("\n\tSegunda fracao: ");
        imprimiR(R2);

        //Somatoria
        somatoria = somaR(R1, R2);
        printf("\n\n\t- SOMATORIA: %.2f", somatoria);

        //Multiplicacao
        multiplicacao = multiplicaR(R1, R2);
        printf("\n\n\t- MULTIPLICACAO: %.2f", multiplicacao);

        //Checa por igualdade entre os valores racionais
        checarIgualdade(R1, R2);

        //Escolha do usuario entre recomecar ou encerrar o programa
        escolha = loop();
        printf("\n");
    }

    printf("\nEncerrando o programa . . .\n");
    system("PAUSE");
    return 0;
}
