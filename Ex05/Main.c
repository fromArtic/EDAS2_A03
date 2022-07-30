#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex05.h"

int main(){
    Lista *l = criarLista();
    int escolha;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 7)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Cadastrar produto
                query(l, escolha);
                break;
            case 2: //Buscar por menor preco
                buscaPorMenorPreco(l);
                break;
            case 3: //Buscar produtos com estoque inferior ao valor informado
                query(l, escolha);
                break;
            case 4: //Apagar produto do cadastro
                query(l, escolha);
                break;
            case 5: //Atualizar cadastro de produto
                query(l, escolha);
                break;
            case 6: //Gerar relatorio do estoque por ordem CRESCENTE de reserva
                relatorio(l, escolha);
                break;
            case 7: //Gerar relatorio do estoque por ordem DECRESCENTE de reserva
                relatorio(l, escolha);
                break;
            case 0: //Encerrar
                printf("\nEncerrando o programa . . .\n");
        }
    }while(escolha != 0);

    system("PAUSE");
    return 0;
}
