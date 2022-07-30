#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "EDAS2_A03Ex07.h"

//Registro dos numeros complexos
struct complexo{
    float real;
    float img;
};

//Registro da lista
struct lista{
    Complexo complexos[MAX];
    int prox;
};

//Alocacao de memoria para a lista
Lista *criarLista(){
    Lista *l;
    l = (Lista*) malloc(sizeof(struct lista));

    if(l != NULL){
        l->prox = 0;
    }

    return l;
}

//Menu de entrada do sistema
int menu(){
    int escolha;

    system("CLS");

    printf("\n\tNUMEROS COMPLEXOS");
    printf("\t\t\t0 - Encerrar");
    printf("\n\n\t1 - Cadastrar numero complexo");
    printf("\n\n\t2 - Somar");
    printf("\n\t3 - Subtrair");
    printf("\n\t4 - Multiplicar");
    printf("\n\t5 - Dividir");
    printf("\n\n\t6 - Destruir numero complexo");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

//Query para entradas do usuario
void query(Lista *l, int escolha){
    //Cadastrar numero complexo
    if(escolha == 1){
        if(l->prox == MAX){
            printf("\nO total de numeros complexos (%d) foi atingido.\n", MAX);
            system("PAUSE");
            return 0;
        }

        Complexo c;

        printf("\n\n-- CADASTRO --\n\n");

        //Real
        printf("Parte real: ");
        scanf("%f", &c.real);

        //Imagem
        printf("Parte imaginaria: ");
        scanf("%f", &c.img);

        inserirFinal(l, c);
    }
    else if(escolha == 6){ //Destruir numero complexo
        if(l->prox > 0){ //Checa se ha ao menos um numero complexo registrado
            int n, check = 0;

            exibir(l);

            printf("Insira a posicao equivalente ao que deseja destruir: ");
            scanf("%d", &n);

            while((n > l->prox) || (n <= 0)){
                if(check == 0){
                    printf("ERRO: Posicao inserida inexistente. Utilize a lista acima e informe um posicao valida: ");
                    scanf("%d", &n);
                    check++;
                }else{
                    printf("ERRO: Posicao inserida inexistente. Informe uma posicao valida: ");
                    scanf("%d", &n);
                }
            }

            destruir(l, n);
        }else{
            printf("\nNao ha qualquer numero complexo registrado.\n");
            system("PAUSE");
            return 0;
        }
    }
    else if(l->prox > 1){ //Checa se ha ao menos dois numeros complexos registrados
        int a, b, check = 0;

        exibir(l);

        if(escolha == 2){ //Somar
            printf("Insira as posicoes equivalentes aos que deseja somar: ");
        }
        if(escolha == 3){ //Subtrair
            printf("Insira as posicoes equivalentes aos que deseja subtrair: ");
        }
        if(escolha == 4){ //Multiplicar
            printf("Insira as posicoes equivalentes aos que deseja multiplicar: ");
        }
        if(escolha == 5){ //Dividir
            printf("Insira as posicoes equivalentes aos que deseja dividir: ");
        }
        scanf("%d %d", &a, &b);

        while((a > l->prox) || (b > l->prox) || (a <= 0) || (b <= 0)){
            if(check == 0){
                printf("ERRO: Posicao inserida inexistente. Utilize a lista acima e informe duas posicoes validas (separadas por espaco): ");
                scanf("%d %d", &a, &b);
                check++;
            }else{
                printf("ERRO: Posicao inserida inexistente. Informe duas posicoes validas: ");
                scanf("%d %d", &a, &b);
            }
        }

        if(escolha == 2){ //Somar
            somar(l, a, b);
        }
        if(escolha == 3){ //Subtrair
            subtrair(l, a, b);
        }
        if(escolha == 4){ //Multiplicar
            multiplicar(l, a, b);
        }
        if(escolha == 5){ //Dividir
            dividir(l, a, b);
        }
    }else{
        printf("\nDevem haver ao menos dois numeros complexos registrados para se realizar operacoes.\n");
        system("PAUSE");
        return 0;
    }
}

//Cadastrar numero complexo
int inserirFinal(Lista *l, Complexo c){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->complexos[l->prox] = c;
    l->prox++;

    printf("\n- Numero complexo registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Exibe a lista de numeros complexos
void exibir(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i;

    system("CLS");
    printf("\nNUMEROS COMPLEXOS REGISTRADOS:");
    for(i = 0; i < l->prox; i++){
        printf("\n[%d] %.1f + %.1fi", i+1, l->complexos[i].real, l->complexos[i].img);
    }
    printf("\n\n");
}

//Exibe a somatoria entre dois numeros complexos
void somar(Lista *l, int a, int b){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double x, y;

    x = l->complexos[a-1].real + l->complexos[b-1].real;
    y = l->complexos[a-1].img + l->complexos[b-1].img;

    if(y >= 0){
        printf("\n-> RESULTADO: (%.1f + %.1fi) + (%.1f + %.1fi) = %.1f + %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }else{
        y *= -1;
        printf("\n-> RESULTADO: (%.1f + %.1fi) + (%.1f + %.1fi) = %.1f - %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }
    system("PAUSE");
}

//Exibe a subtracao entre dois numeros complexos
void subtrair(Lista *l, int a, int b){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double x, y;

    x = l->complexos[a-1].real - l->complexos[b-1].real;
    y = l->complexos[a-1].img - l->complexos[b-1].img;

    if(y >= 0){
        printf("\n-> RESULTADO: (%.1f + %.1fi) - (%.1f + %.1fi) = %.1f + %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }else{
        y *= -1;
        printf("\n-> RESULTADO: (%.1f + %.1fi) - (%.1f + %.1fi) = %.1f - %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }
    system("PAUSE");
}

//Exibe a multiplicacao entre dois numeros complexos
void multiplicar(Lista *l, int a, int b){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double x, y;

    x = l->complexos[a-1].real * l->complexos[b-1].real;
    y = l->complexos[a-1].img * l->complexos[b-1].img;

    if(y >= 0){
        printf("\n-> RESULTADO: (%.1f + %.1fi) . (%.1f + %.1fi) = %.1f + %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }else{
        y *= -1;
        printf("\n-> RESULTADO: (%.1f + %.1fi) . (%.1f + %.1fi) = %.1f - %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }
    system("PAUSE");
}

//Exibe a divisao entre dois numeros complexos
void dividir(Lista *l, int a, int b){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    double x, y;

    x = l->complexos[a-1].real / l->complexos[b-1].real;
    y = l->complexos[a-1].img / l->complexos[b-1].img;

    if(y >= 0){
        printf("\n-> RESULTADO: (%.1f + %.1fi) / (%.1f + %.1fi) = %.1f + %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }else{
        y *= -1;
        printf("\n-> RESULTADO: (%.1f + %.1fi) / (%.1f + %.1fi) = %.1f - %.1fi\n\n", l->complexos[a-1].real, l->complexos[a-1].img, l->complexos[b-1].real, l->complexos[b-1].img, x, y);
    }
    system("PAUSE");
}

//Apagar numero complexo do cadastro
void destruir(Lista *l, int n){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    while(n < l->prox){
        l->complexos[n-1] = l->complexos[n];
        n++;
    }
    l->prox--;

    printf("\n- Registro destruido com sucesso. -\n\n");
    system("PAUSE");
}
