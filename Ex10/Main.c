/*
JUSTIFICATIVA:
A prioridade eh dada a avioes abaixo de determinada porcentagem de combustivel disponivel, posicionando-os a frente daqueles com combustivel excedente.

Assim, ha dois criterios quanto a ordenacao geral da fila: o momento de chegada do aviao ao aeroporto e seu nivel disponivel de combustivel.
Dessa forma, enquanto avioes com quantias adequadas de combustivel sao ordenados por ordem de chegada, avioes que necessitam da liberacao do pouso
com urgencia recebem prioridade.

Ha tres niveis de prioridade, sobrepondo uns aos outros:
- PRIORIDADE I: menos de 5% de combustivel restante.
- PRIORIDADE II: menos de 15% de combustivel restante.
- PRIORIDADE III: menos de 25% de combustivel restante.
*/

#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex10.h"

int menu();

int main(){
    No *fila = NULL;
    No *r = NULL;
    int escolha, c;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 3)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Registrar aviao
                printf("\nInforme a porcentagem de combustivel ainda disponivel no aviao: ");
                scanf("%d", &c);
                while((c <= 0) || (c > 100)){
                    printf("ERRO: Valor invalido. Insira uma porcentagem valida: ");
                    scanf("%d", &c);
                }
                inserirComPrioridade(&fila, c);
                break;
            case 2: //Exibir fila
                imprimir(fila);
                break;
            case 3: //Avancar fila
                r = avancar(&fila);
                if(r){
                    printf("\n- O aviao em primeira colocacao foi removido da fila. -\n\n");
                    system("PAUSE");
                    free(r);
                }
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

    printf("\n\tCONTROLE DE POUSO");
    printf("\t\t0 - Encerrar");
    printf("\n\n\t1 - Registrar aviao");
    printf("\n\t2 - Exibir fila");
    printf("\n\t3 - Avancar fila");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}
