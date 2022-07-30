#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex07.h"

int main(){
    Lista *l = criarLista();
    int escolha;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 6)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Cadastrar numero complexo
                query(l, escolha);
                break;
            case 2: //Somar
                query(l, escolha);
                break;
            case 3: //Subtrair
                query(l, escolha);
                break;
            case 4: //Multiplicar
                query(l, escolha);
                break;
            case 5: //Dividir
                query(l, escolha);
                break;
            case 6: //Destruir numero complexo
                query(l, escolha);
                break;
            case 0: //Encerrar
                printf("\nEncerrando o programa . . .\n");
        }
    }while(escolha != 0);

    system("PAUSE");
    return 0;
}
