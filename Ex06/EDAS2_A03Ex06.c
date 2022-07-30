#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EDAS2_A03Ex06.h"

//Registro dos numeros racionais
struct racional{
    int numerador;
    int denominador;
    int numeradorSimplificado;
    int denominadorSimplificado;
    int mdc;
    double fracao;
};

//Retorna um valor racional
Racional *criaR(int a, int *b){
    Racional *R = (Racional*) malloc(sizeof(Racional));

    if(R != NULL){
        while(*b == 0){
            printf("ERRO: O denominador deve ser diferente de zero. Insira um valor valido: ");
            scanf("%d", &*b);
        }

        int MDC = simplificar(a, (*b)); //Simplifica os valores

        R->numerador = a;
        R->denominador = (*b);
        R->mdc = MDC;
        if(MDC != 1){
            R->numeradorSimplificado = a/MDC;
            R->denominadorSimplificado = (*b)/MDC;
        }
        R->fracao = (double)a/(*b);

        return R;
    }else{
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
}

//Simplificacao do numerador e denominador
int simplificar(int numerador, int denominador){
    int backup;

    while(numerador > 0){
        if(denominador > numerador){
            backup = numerador;
            numerador = denominador;
            denominador = backup;
        }
        numerador -= denominador;
    }

    return denominador;
}

//Imprime o valor racional
void imprimiR(Racional *R){
    if(R == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    if(R->mdc != 1){
        printf("%d/%d = %d/%d = %.2f", R->numerador, R->denominador, R->numeradorSimplificado, R->denominadorSimplificado, R->fracao);
    }else{
        printf("%d/%d = %.2f", R->numerador, R->denominador, R->fracao);
    }
}

//Retorna a somatoria entre dois racionais
double somaR(Racional *R1, Racional *R2){
    if((R1 == NULL) || (R2 == NULL)){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double somatoria = R1->fracao + R2->fracao;
    return somatoria;
}

//Retorna a multiplicacao entre dois racionais
double multiplicaR(Racional *R1, Racional *R2){
    if((R1 == NULL) || (R2 == NULL)){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double multiplicacao = R1->fracao * R2->fracao;
    return multiplicacao;
}

//Testa se ha igualdade entre dois racionais
void checarIgualdade(Racional *R1, Racional *R2){
    if((R1 == NULL) || (R2 == NULL)){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    if(R1->fracao == R2->fracao){
        printf("\n\n\t- Os racionais informados sao iguais um ao outro.");
    }else{
        printf("\n\n\t- Os racionais informados sao diferentes um do outro.");
    }
}

//Escolha do usuario entre recomecar ou encerrar o programa
int loop(){
    char escolha[3];
    int SouN;

    printf("\n\n\n\tIntroduzir novos valores (S/N)? ");
    scanf("%s", &escolha);

    while((stricmp(escolha, "s") != 0) && (stricmp(escolha, "sim") != 0) && (stricmp(escolha, "n") != 0) && (stricmp(escolha, "nao") != 0)){
        printf("\tERRO: Entrada invalida.\n\tInsira somente S para introduzir novos valores, ou N para encerrar o programa: ");
        scanf("%s", &escolha);
    }

    if((stricmp(escolha, "s") == 0) || (stricmp(escolha, "sim") == 0)){
        SouN = 1;
    }else if((stricmp(escolha, "n") == 0) || (stricmp(escolha, "nao") == 0)){
        SouN = 0;
    }

    return SouN;
}
