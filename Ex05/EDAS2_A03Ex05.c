#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A03Ex05.h"

//Registro da lista
struct lista{
    Produto produtos[MAX];
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

    printf("\n\tGERENCIAMENTO DE PRODUTOS");
    printf("\t\t\t\t\t0 - Encerrar");
    printf("\n\n\t1 - Cadastrar produto");
    printf("\n\n\t2 - Buscar por menor preco");
    printf("\n\t3 - Buscar produtos com estoque inferior ao valor informado");
    printf("\n\n\t4 - Apagar produto do cadastro");
    printf("\n\t5 - Atualizar cadastro de produto");
    printf("\n\n\t6 - Gerar relatorio do estoque por ordem CRESCENTE de reserva");
    printf("\n\t7 - Gerar relatorio do estoque por ordem DECRESCENTE de reserva");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

//Query para entradas do usuario
void query(Lista *l, int escolha){
    //Cadastrar produto
    if(escolha == 1){
        if(l->prox == MAX){
            printf("\nO total de produtos registrados (%d) foi atingido.\n", MAX);
            system("PAUSE");
            return 0;
        }

        Produto p;

        //Codigo
        p.codigo = certificarCodigo(l);

        //Nome
        printf("Comunique o nome do produto: ");
        scanf("%s", &p.nome);

        //Descricao
        printf("E agora, sua descricao: ");
        scanf("%s", &p.descricao);

        //Valor
        printf("Informe o valor do produto: R$ ");
        scanf("%f", &p.valor);
        while(p.valor < 0){
            printf("ERRO: Insira uma quantia valida. Valor do produto: R$ ");
            scanf("%f", &p.valor);
        }

        //Quantidade em estoque
        printf("Ha quantas unidades em estoque? ");
        scanf("%d", &p.quantEstoque);
        while(p.quantEstoque < 0){
            printf("ERRO: Insira uma quantia valida. Unidades em estoque: ");
            scanf("%d", &p.quantEstoque);
        }

        //Data da ultima compra
        printf("Informe o dia e mes da ultima compra do produto (separados por espaco, somente digitos): ");
        scanf("%d %d", &p.diaUltimaCompra, &p.mesUltimaCompra);
        while((p.diaUltimaCompra <= 0) || (p.diaUltimaCompra > 31) || (p.mesUltimaCompra <= 0) || (p.mesUltimaCompra > 12)){
            printf("ERRO: Insira uma data valida. Dia e mes da ultima compra (separados por espaco, somente digitos): ");
            scanf("%d %d", &p.diaUltimaCompra, &p.mesUltimaCompra);
        }

        inserirFinal(l, p);
    }

    //Buscar produtos com estoque inferior ao valor informado
    if(escolha == 3){
        int valor;

        printf("\n\nInforme o valor (em unidades): ");
        scanf("%d", &valor);
        while(valor < 0){
            printf("ERRO: Insira uma quantia valida. Valor (em unidades): ");
            scanf("%d", &valor);
        }

        buscaPorEstoqueInferiorAoInformado(l, valor);
    }

    //Apagar produto do cadastro
    if(escolha == 4){
        int c;

        printf("\n\nInforme o codigo do produto que deseja apagar: ");
        scanf("%d", &c);

        apagarProduto(l, c);
    }

    //Atualizar cadastro de produto
    if(escolha == 5){
        int c;

        printf("\n\nInforme o codigo do produto que deseja atualizar: ");
        scanf("%d", &c);

        atualizarProduto(l, c);
    }
}

//Certifica-se de que o codigo de cada produto seja unico
int certificarCodigo(Lista *l){
    int codigo, i;

    printf("\n\nInsira o codigo unico do respectivo produto: ");
    scanf("%d", &codigo);

    for(i = 0; i < l->prox; i++){
        while(codigo == l->produtos[i].codigo){
            printf("ERRO: O codigo inserido ja esta cadastrado. Informe uma combinacao valida: ");
            scanf("%d", &codigo);
            i = 0;
        }
    }

    return codigo;
}

//Cadastro de produtos
int inserirFinal(Lista *l, Produto p){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->produtos[l->prox] = p;
    l->prox++;

    printf("\n- Produto registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Buscar por menor preco
void buscaPorMenorPreco(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox != 0){
        float menorValor = l->produtos[0].valor;
        int i;

        //Busca pelo menor preco
        for(i = 0; i < l->prox; i++){
            if(l->produtos[i].valor < menorValor){
                menorValor = l->produtos[i].valor;
            }
        }

        //Imprime os produtos com preco igual ao encontrado
        printf("\n\n-- RESULTADOS DA BUSCA --\n\n");
        printf("Menor preco registrado: R$ %.2f\n\nLista de produtos com o valor informado:", menorValor);
        for(i = 0; i < l->prox; i++){
            if(l->produtos[i].valor == menorValor){
                printf("\n- %s [%d], %d unidades em estoque", l->produtos[i].nome, l->produtos[i].codigo, l->produtos[i].quantEstoque);
            }
        }
        printf("\n\n");
    }else{
        printf("\nNao ha qualquer registro de produtos em estoque.\n\n");
    }
    system("PAUSE");
}

//Buscar produtos com estoque inferior ao valor informado
void buscaPorEstoqueInferiorAoInformado(Lista *l, int valor){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i, check = 0;

    printf("\n\n-- RESULTADOS DA BUSCA (%d unidades) --\n\n", valor);
    for(i = 0; i < l->prox; i++){
        if(l->produtos[i].quantEstoque < valor){
            if(check == 0){
                printf("Produtos com estoque abaixo do valor informado:\n");
            }
            printf("- %s [%d], %d unidades em estoque\n", l->produtos[i].nome, l->produtos[i].codigo, l->produtos[i].quantEstoque);
            check++;
        }
    }
    if(check == 0){
        printf("Nao ha registro de produtos com estoque abaixo do valor informado.");
    }
    printf("\n\n");
    system("PAUSE");
}

//Apagar produto do cadastro
void apagarProduto(Lista *l, int c){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i, check = 0;

    for(i = 0; i < l->prox; i++){
        if(l->produtos[i].codigo == c){
            while(i < l->prox){
                l->produtos[i] = l->produtos[i + 1];
                i++;
            }
            l->prox--;
            check++;
            printf("\n- Produto apagado com sucesso. -\n\n");
            break;
        }
    }
    if(check == 0){
        printf("\nNao foram encontrados registros associados ao codigo informado.\n\n");
    }

    system("PAUSE");
}

//Atualizar cadastro de produto
void atualizarProduto(Lista *l, int c){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i, check = 0;

    for(i = 0; i < l->prox; i++){
        if(l->produtos[i].codigo == c){
            printf("\n-- ATUALIZAR CADASTRO --\n\n");

            //Informacoes atuais
            printf("Informacoes do produto:\n");
            printf("- Nome: %s\n", l->produtos[i].nome);
            printf("- Descricao: %s\n", l->produtos[i].descricao);
            printf("- Valor: R$ %.2f\n", l->produtos[i].valor);
            printf("- Quantidade em estoque: %d unidades\n", l->produtos[i].quantEstoque);
            printf("- Data da ultima compra: ");
                    if(l->produtos[i].diaUltimaCompra < 10){
                        printf("0");
                    }
                    printf("%d/", l->produtos[i].diaUltimaCompra);
                    if(l->produtos[i].mesUltimaCompra < 10){
                        printf("0");
                    }
                    printf("%d\n\n", l->produtos[i].mesUltimaCompra);

            //Codigo (inalteravel)
            printf("Codigo [%d]\n", l->produtos[i].codigo);

            //Nome
            printf("Novo nome: ");
            scanf("%s", &l->produtos[i].nome);

            //Descricao
            printf("Nova descricao: ");
            scanf("%s", &l->produtos[i].descricao);

            //Valor
            printf("Novo valor: R$ ");
            scanf("%f", &l->produtos[i].valor);
            while(l->produtos[i].valor < 0){
                printf("ERRO: Insira uma quantia valida. Valor do produto: R$ ");
                scanf("%f", &l->produtos[i].valor);
            }

            //Quantidade em estoque
            printf("Unidades em estoque: ");
            scanf("%d", &l->produtos[i].quantEstoque);
            while(l->produtos[i].quantEstoque < 0){
                printf("ERRO: Insira uma quantia valida. Unidades em estoque: ");
                scanf("%d", &l->produtos[i].quantEstoque);
            }

            //Data da ultima compra
            printf("Dia e mes da ultima compra do produto (separados por espaco, somente digitos): ");
            scanf("%d %d", &l->produtos[i].diaUltimaCompra, &l->produtos[i].mesUltimaCompra);
            while((l->produtos[i].diaUltimaCompra <= 0) || (l->produtos[i].diaUltimaCompra > 31) || (l->produtos[i].mesUltimaCompra <= 0) || (l->produtos[i].mesUltimaCompra > 12)){
                printf("ERRO: Insira uma data valida. Dia e mes da ultima compra (separados por espaco, somente digitos): ");
                scanf("%d %d", &l->produtos[i].diaUltimaCompra, &l->produtos[i].mesUltimaCompra);
            }

            check++;
            printf("\n- Produto atualizado com sucesso. -\n\n");
            break;
        }
    }
    if(check == 0){
        printf("\nNao foram encontrados registros associados ao codigo informado.\n\n");
    }

    system("PAUSE");
}

//Impressao de relatorios do estoque
void relatorio(Lista *l, int escolha){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    int i, j;

    Lista *copia = criarLista();

    //Copia uma lista na outra
    copia->prox = l->prox;
    for(i = 0; i < l->prox; i++){
        copia->produtos[i] = l->produtos[i];
    }


    if(escolha == 6){ //Reordena os valores da copia de forma CRESCENTE
        for(i = 0; i < copia->prox; i++){
            for(j = i; j < copia->prox; j++){
                 if(copia->produtos[i].quantEstoque > copia->produtos[j].quantEstoque){
                    Produto backup = copia->produtos[i];
                    copia->produtos[i] = copia->produtos[j];
                    copia->produtos[j] = backup;
                 }
            }
        }
    }else{ //Reordena os valores da copia de forma DECRESCENTE
        for(i = 0; i < copia->prox; i++){
            for(j = i; j < copia->prox; j++){
                 if(copia->produtos[i].quantEstoque < copia->produtos[j].quantEstoque){
                    Produto backup = copia->produtos[i];
                    copia->produtos[i] = copia->produtos[j];
                    copia->produtos[j] = backup;
                }
            }
        }
    }

    system("CLS");
    if(escolha == 6){
        printf("\n\t---------------------------------------- ESTOQUE CRESCENTE ----------------------------------------\n\n\t");
    }else{
        printf("\n\t---------------------------------------- ESTOQUE DECRESCENTE ----------------------------------------\n\n\t");
    }
    for(i = 0; i < l->prox; i++){
        printf("%s [%d]\n\t", copia->produtos[i].nome, copia->produtos[i].codigo);
        printf("- Descricao: %s\n\t", copia->produtos[i].descricao);
        printf("- Valor: R$ %.2f\n\t", copia->produtos[i].valor);
        printf("- Quantidade em estoque: %d unidades\n\t", copia->produtos[i].quantEstoque);
        printf("- Data da ultima compra: ");
                if(copia->produtos[i].diaUltimaCompra < 10){
                    printf("0");
                }
                printf("%d/", copia->produtos[i].diaUltimaCompra);
                if(copia->produtos[i].mesUltimaCompra < 10){
                    printf("0");
                }
                printf("%d\n\n\t", copia->produtos[i].mesUltimaCompra);
    }
    printf("----------------------------------------                   ----------------------------------------\n\n\n");
    system("PAUSE");
}
