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
void copiarLista(Lista *original, Lista *copia);
void imprimirLista(Lista *l);
Lista limparLista(Lista *l);

int main(){
    Lista *l = criarLista();
    Lista *lCopia = criarLista();
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
            case 3: //Exibir lista reordenada de forma decrescente e sem valores repetidos
                copiarLista(l, lCopia);
                imprimirLista(lCopia);
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
    printf("\n\t3 - Exibir lista reordenada de forma decrescente e sem valores repetidos");
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

void copiarLista(Lista *original, Lista *copia){
    if(original == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i, j, k;

    //Copia uma lista na outra
    copia->prox = original->prox;
    for(i = 0; i < original->prox; i++){
        copia->inteiros[i] = original->inteiros[i];
    }

    //Remove valores repetidos da copia
    for(i = 0; i < copia->prox; i++){
        for(j = i + 1; j < copia->prox; j++){
            if(copia->inteiros[j] == copia->inteiros[i]){
                for(k = j; k < copia->prox; k++){
                    copia->inteiros[k] = copia->inteiros[k+1];
                }
                copia->prox--;
                j--;
            }
        }
    }

    //Reordena os valores da copia de forma decrescente
    for(int i = 0; i < copia->prox; i++){
        for(int j = i; j < copia->prox; j++){
             if(copia->inteiros[i] < copia->inteiros[j]){
                int backup = copia->inteiros[i];
                copia->inteiros[i] = copia->inteiros[j];
                copia->inteiros[j] = backup;
            }
        }
    }
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

Lista limparLista(Lista *l){
    if(l != NULL){
        if(l->prox != 0){
            l = NULL;
            l = criarLista();

            printf("\n- A lista foi limpa com sucesso. -\n\n");
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
