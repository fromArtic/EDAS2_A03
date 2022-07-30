#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Maximo de retangulos registrados

//Registro dos retangulos
typedef struct retangulo{
    float base;
    float altura;
    float area;
}Retangulo;

//Registro da lista
typedef struct lista{
    Retangulo retangulos[MAX];
    int prox;
}Lista;

//Funcoes
Lista *criarLista();
int inserirFinal(Lista *l, Retangulo r);
void exibir(Lista *l);
void apagar(Lista *l, int n);
float calcularArea(Lista *l);

int main(){
    Lista *l = criarLista();
    int escolha;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 3)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Cadastrar retangulo
                query(l, escolha);
                break;
            case 2: //Exibir lista de retangulos cadastrados
                exibir(l);
                system("PAUSE");
                break;
            case 3: //Apagar retangulo do cadastro
                query(l, escolha);
                break;
            case 0: //Encerrar
                printf("\nEncerrando o programa . . .\n");
        }
    }while(escolha != 0);

    system("PAUSE");
    return 0;
}

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

    printf("\n\tREGISTRO DE RETANGULOS");
    printf("\t\t\t\t0 - Encerrar");
    printf("\n\n\t1 - Cadastrar retangulo");
    printf("\n\t2 - Exibir lista de retangulos cadastrados");
    printf("\n\t3 - Apagar retangulo do cadastro");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

//Query para entradas do usuario
void query(Lista *l, int escolha){
    //Cadastrar retangulo
    if(escolha == 1){
        if(l->prox == MAX){
            printf("\nO total de retangulos registrados (%d) foi atingido.\n", MAX);
            system("PAUSE");
            return 0;
        }

        Retangulo r;

        printf("\n\n-- CADASTRO --\n\n");

        //Base
        printf("Base do retangulo (em metros): ");
        scanf("%f", &r.base);
        while(r.base <= 0){
            printf("ERRO: Medida invalida. Base do retangulo (em metros): ");
            scanf("%f", &r.base);
        }

        //Altura
        printf("Altura do retangulo (em metros): ");
        scanf("%f", &r.altura);
        while(r.altura <= 0){
            printf("ERRO: Medida invalida. Altura do retangulo (em metros): ");
            scanf("%f", &r.altura);
        }

        inserirFinal(l, r);
    }
    //Apagar retangulo do cadastro
    else if(escolha == 3){
        if(l->prox > 0){ //Checa se ha ao menos um retangulo registrado
            int n, check = 0;

            exibir(l);

            printf("Insira a posicao equivalente ao que deseja apagar: ");
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

            apagar(l, n);
        }else{
            printf("\nNao ha qualquer retangulo registrado.\n");
            system("PAUSE");
            return 0;
        }
    }
}

//Cadastrar retangulo
int inserirFinal(Lista *l, Retangulo r){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->retangulos[l->prox] = r;
    l->retangulos[l->prox].area = calcularArea(l);
    l->prox++;

    printf("\n- Retangulo registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Calcula a area do retangulo
float calcularArea(Lista *l){
    float A;

    A = l->retangulos[l->prox].base * l->retangulos[l->prox].altura;

    return A;
}

//Exibe a lista de retangulos
void exibir(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == 0){
        printf("\nNao ha qualquer retangulo registrado.\n");
        return 0;
    }

    int i;

    system("CLS");
    printf("\nRETANGULOS REGISTRADOS:\n");
    for(i = 0; i < l->prox; i++){
        printf("\n[%d]\nBase (b) = %.1f m\nAltura (h) = %.1f m\nArea (A) = %.1f m. quadrados\n", i+1, l->retangulos[i].base, l->retangulos[i].altura, l->retangulos[i].area);
    }
    printf("\n");
}

//Apagar retangulo do cadastro
void apagar(Lista *l, int n){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    while(n < l->prox){
        l->retangulos[n-1] = l->retangulos[n];
        n++;
    }
    l->prox--;

    printf("\n- Retangulo apagado com sucesso. -\n\n");
    system("PAUSE");
}
