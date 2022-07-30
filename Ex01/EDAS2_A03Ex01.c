#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Maximo de valores na lista

//Registro da lista
typedef struct lista{
    int inteiros[MAX];
    int prox;
}Lista;

//Funcoes
int menu();
Lista *criarLista();
int inserirFinal(Lista *l, int n);
void imprimirLista(Lista *l);
void checarOrdem(Lista *l);
Lista limparLista(Lista *l);

int main(){
    Lista *l = criarLista();
    int n, escolha;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 4)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Registrar valor
                printf("\n\nInsira o inteiro que deseja adicionar a lista: ");
                scanf("%d", &n);
                inserirFinal(l, n);
                break;
            case 2: //Exibir lista
                imprimirLista(l);
                break;
            case 3: //Verificar ordenacao da lista
                checarOrdem(l);
                break;
            case 4: //Limpar lista
                *l = limparLista(l);
                break;
            case 0: //Encerrar
                printf("\nEncerrando o programa . . .\n");
        }
    }while(escolha != 0);

    system("PAUSE");
    return 0;
}

int menu(){
    int escolha;

    system("CLS");

    printf("\n\tREGISTRO DE INTEIROS");
    printf("\t\t0 - Encerrar");
    printf("\n\n\t1 - Registrar valor");
    printf("\n\t2 - Exibir lista");
    printf("\n\t3 - Verificar ordenacao da lista");
    printf("\n\t4 - Limpar lista");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

Lista *criarLista(){
    Lista *l;
    l = (Lista*) malloc(sizeof(struct lista));

    if(l != NULL){
        l->prox = 0;
    }

    return l;
}

int inserirFinal(Lista *l, int n){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == MAX){
        printf("\nO total de valores registrados (%d) foi atingido.\n", MAX);
        system("PAUSE");
        return 0;
    }

    l->inteiros[l->prox] = n;
    l->prox++;

    printf("\n- Valor registrado a lista com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

void imprimirLista(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i;

    printf("\n\n\t---------------------------------------- LISTA ----------------------------------------\n\t");
    for(i = 0; i < l->prox; i++){
        printf("%d ", l->inteiros[i]);
    }
    printf("\n\t----------------------------------------       ----------------------------------------\n\n\n");
    system("PAUSE");
}

void checarOrdem(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == 0){
        printf("\nA lista ainda nao possui qualquer valor registrado a ela.\n\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == 1){ //Checa se ha somente um valor registrado a lista
        printf("\nHa somente um inteiro registrado a lista.\n\n");
        system("PAUSE");
        return 0;
    }

    int i, check = 0;

    //Checa se todos os valores sao iguais
    for(i = 0; i < l->prox; i++){
        if(l->inteiros[i] != l->inteiros[i+1]){
            break;
        }
        if(i == l->prox - 2){
            printf("\nTodos os inteiros registrados possuem o mesmo valor.\n\n");
            check++;
            system("PAUSE");
            break;
        }
    }
    //Checa por ordem crescente
    if(check == 0){
        for(i = 0; i < l->prox; i++){
            if(l->inteiros[i] > l->inteiros[i+1]){
                break;
            }
            if(i == l->prox - 2){
                printf("\nA lista esta ordenada crescentemente.\n\n");
                check++;
                system("PAUSE");
                break;
            }
        }
    }
    //Checa por ordem decrescente
    if(check == 0){
        for(i = 0; i < l->prox; i++){
            if(l->inteiros[i] < l->inteiros[i+1]){
                printf("\nA lista nao esta ordenada de forma crescente ou decrescente.\n\n");
                system("PAUSE");
                break;
            }
            if(i == l->prox - 2){
                printf("\nA lista esta ordenada decrescentemente.\n\n");
                system("PAUSE");
                break;
            }
        }
    }
}

Lista limparLista(Lista *l){
    if(l != NULL){
        if(l->prox != 0){
            l = NULL;
            l = criarLista();

            printf("\n- A lista de inteiros foi limpa com sucesso. -\n\n");
            system("PAUSE");

            return *l;
        }else{
            printf("\nA lista ainda nao possui qualquer valor registrado a ela.\n\n");
            system("PAUSE");
        }
    }else{
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
    }
}
