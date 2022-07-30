#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Maximo de valores na lista

//Registro da lista
typedef struct lista{
    int inteiros[MAX];
    int prox;
    int n;
}Lista;

//Funcoes
int menu();
Lista *criarLista();
int inserirFinal(Lista *l, int num);
void imprimirLista(Lista *l);
void merge(Lista *l1, Lista *l2);

int main(){
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();
    int num, escolha;

    l1->n = 1;
    l2->n = 2;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 5)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Registrar valor em L1
                printf("\n\nInsira o inteiro que deseja adicionar a L1: ");
                scanf("%d", &num);
                inserirFinal(l1, num);
                break;
            case 2: //Registrar valor em L2
                printf("\n\nInsira o inteiro que deseja adicionar a L2: ");
                scanf("%d", &num);
                inserirFinal(l2, num);
                break;
            case 3: //Exibir L1
                imprimirLista(l1);
                break;
            case 4: //Exibir L2
                imprimirLista(l2);
                break;
            case 5: //Realizar merge
                merge(l1, l2);
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
    printf("\n\n\t1 - Registrar valor em L1");
    printf("\n\t2 - Registrar valor em L2");
    printf("\n\n\t3 - Exibir L1");
    printf("\n\t4 - Exibir L2");
    printf("\n\n\t5 - Realizar merge");
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

int inserirFinal(Lista *l, int num){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == MAX){
        if(l->n == 1){
            printf("\nO total de valores registrados (%d) em L1 foi atingido.\n", MAX);
        }else if(l->n == 2){
            printf("\nO total de valores registrados (%d) em L2 foi atingido.\n", MAX);
        }
        system("PAUSE");
        return 0;
    }

    l->inteiros[l->prox] = num;
    l->prox++;

    if(l->n == 1){
        printf("\n- Valor registrado em L1 com sucesso. -\n\n");
    }else if(l->n == 2){
        printf("\n- Valor registrado em L2 com sucesso. -\n\n", MAX);
    }
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

    if(l->n == 1){
        printf("\n\n\t---------------------------------------- L1 ----------------------------------------\n\t");
    }else if(l->n == 2){
        printf("\n\n\t---------------------------------------- L2 ----------------------------------------\n\t");
    }else if(l->n == 3){
        printf("\n\n\t---------------------------------------- L3 ----------------------------------------\n\t");
    }
    for(i = 0; i < l->prox; i++){
        printf("%d ", l->inteiros[i]);
    }
    printf("\n\t----------------------------------------    ----------------------------------------\n\n\n");
    system("PAUSE");
}

void merge(Lista *l1, Lista *l2){
    if((l1 == NULL) || (l2 == NULL)){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l1->prox + l2->prox >= MAX){
        printf("\nA operacao nao pode ser efetuada, pois as duas listas combinadas superam o limite de valores registrados (%d).\n\n", MAX);
        system("PAUSE");
    }else{
        Lista *l3 = criarLista();
        l3->n = 3;

        int i, j, k;

        l3->prox = l1->prox + l2->prox;
        for(i = 0; i < l1->prox; i++){ //Copia l1 em l3
            l3->inteiros[i] = l1->inteiros[i];
        }
        for(j = 0; j < l3->prox; j++){ //Copia l2 em l3
            l3->inteiros[l1->prox + j] = l2->inteiros[j];
        }

        //Remove valores repetidos de l3
        for(i = 0; i < l3->prox; i++){
            for(j = i + 1; j < l3->prox; j++){
                if(l3->inteiros[j] == l3->inteiros[i]){
                    for(k = j; k < l3->prox; k++){
                        l3->inteiros[k] = l3->inteiros[k+1];
                    }
                    l3->prox--;
                    j--;
                }
            }
        }


        imprimirLista(l3);
    }
}
