#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex10.h"

//Registra avioes a lista
void inserirComPrioridade(No **fila, int c){
    No *aux, *novo = malloc(sizeof(No)); //Alocacao de memoria das variaveis

    if(novo){
        novo->combRestante = c;
        novo->prox = NULL;
        if(*fila == NULL){ //Caso a fila esteja vazia, o no ocupara a primeira posicao
            *fila = novo;
        }else{ //Caso contrario, checa a prioridade do no
            if(c < 5){ //PRIORIDADE I: menos de 5% de combustivel restante
                if((*fila)->combRestante > 4){ //Checa se eh a primeira prioridade
                    novo->prox = *fila; //Se for, o no aponta para o inicio da fila
                    *fila = novo; //Insere o no no inicio da fila
                }else{ //Se nao for, busca sua posicao respectiva
                    aux = *fila;
                    while(aux->prox && aux->prox->combRestante < 5){ //Procura, enquanto houver um proximo elemento, por nos prioritarios
                        aux = aux->prox;
                    }
                    novo->prox= aux->prox; //Insere o no apos a ultima prioridade
                    aux->prox = novo; //Aponta aux para a nova ultima prioridade
                }
            }else if(c < 15){ //PRIORIDADE II: menos de 15% de combustivel restante
                if((*fila)->combRestante > 14){
                    novo->prox = *fila;
                    *fila = novo;
                }else{
                    aux = *fila;
                    while(aux->prox && aux->prox->combRestante < 15){
                        aux = aux->prox;
                    }
                    novo->prox= aux->prox;
                    aux->prox = novo;
                }
            }else if(c < 25){ //PRIORIDADE III: menos de 25% de combustivel restante
                if((*fila)->combRestante > 24){
                    novo->prox = *fila;
                    *fila = novo;
                }else{
                    aux = *fila;
                    while(aux->prox && aux->prox->combRestante < 25){
                        aux = aux->prox;
                    }
                    novo->prox= aux->prox;
                    aux->prox = novo;
                }
            }else{ //Caso nao passe pelo if, nao eh prioridade
                aux = *fila;
                while(aux->prox){
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }
        printf("\n- Aviao registrado a fila com sucesso. -\n\n");
        system("PAUSE");
    }else{
        printf("\nErro ao alocar memoria.\n");
        system("PAUSE");
    }
}

//Exibe a fila ordenada de avioes
void imprimir(No *fila){
    printf("\n\n\t-------------------- FILA --------------------\n\t");
    while(fila){
        printf("%d ", fila->combRestante);
        fila = fila->prox;
    }
    printf("\n\t--------------------      --------------------\n\t");
    printf("Prioridade para avioes com escassez de\n\tcombustivel em estoque.\n\n\t");
    printf("- PRIORIDADE I: menos de 5 porcento.\n\t");
    printf("- PRIORIDADE II: menos de 15 porcento.\n\t");
    printf("- PRIORIDADE III: menos de 25 porcento.\n\n\n");
    system("PAUSE");
}

//Apos seu pouso, remove o aviao em primeira colocacao e avanca a fila
No *avancar(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->prox;
    }else{
        printf("\nNao ha avioes na fila.\n\n");
        system("PAUSE");
    }

    return remover;
}
