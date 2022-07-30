#include <stdio.h>
#include <stdlib.h>

#define MAX 50 //Maximo de objetos geometricos planos registrados

//Registro dos retangulos
typedef struct retangulo{
    float base;
    float altura;
    float area;
    int check;
}Retangulo;

//Registro dos triangulos
typedef struct triangulo{
    float base;
    float altura;
    float area;
    int check;
}Triangulo;

//Registro dos circulos
typedef struct circulo{
    float raio;
    float area;
    int check;
}Circulo;

//Registro da lista
typedef struct lista{
    Retangulo retangulos[MAX];
    Triangulo triangulos[MAX];
    Circulo circulos[MAX];
    int prox;
}Lista;

//Funcoes
Lista *criarLista();
int inserirFinal_R(Lista *l, Retangulo r);
int inserirFinal_T(Lista *l, Triangulo t);
int inserirFinal_C(Lista *l, Circulo c);
void exibir(Lista *l);
float calcularArea(Lista *l, int escolhaObjeto);

int main(){
    Lista *l = criarLista();
    int escolha, escolhaObjeto;

    do{
        escolha = menu();
        if((escolha < 0) || (escolha > 3)){
            printf("\nESCOLHA INVALIDA.\n");
            system("PAUSE");
        }
        switch(escolha){
            case 1: //Cadastrar objeto
                escolhaObjeto = escolherObjeto();
                query(l, escolhaObjeto);
                break;
            case 2: //Exibir lista de objetos cadastrados
                exibir(l);
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

    printf("\n\tREGISTRO DE OBJETOS GEOMETRICOS PLANOS");
    printf("\t\t\t0 - Encerrar");
    printf("\n\n\t1 - Cadastrar objeto");
    printf("\n\t2 - Exibir lista de objetos cadastrados");
    printf("\n\n\tInsira sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}

//Escolha do objeto por parte do usuario
int escolherObjeto(){
    int escolhaObjeto;

    printf("\n[1] Retangulo\n[2] Triangulo\n[3] Circulo\n\n");

    printf("Informe o numero correspondente ao tipo de objeto que deseja cadastrar: ");
    scanf("%d", &escolhaObjeto);

    while((escolhaObjeto > 3) || (escolhaObjeto <= 0)){
        printf("ERRO: Escolha invalida. Insira uma entrada valida: ");
        scanf("%d", &escolhaObjeto);
    }

    return escolhaObjeto;
}

//Query para os parametros do objeto
void query(Lista *l, int escolhaObjeto){
    if(l->prox == MAX){
        printf("\nO total de objetos registrados (%d) foi atingido.\n", MAX);
        system("PAUSE");
        return 0;
    }

    //Retangulo
    if(escolhaObjeto == 1){
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

        inserirFinal_R(l, r);
    }

    //Triangulo
    if(escolhaObjeto == 2){
        Triangulo t;

        printf("\n\n-- CADASTRO --\n\n");

        //Base
        printf("Base do triangulo (em metros): ");
        scanf("%f", &t.base);
        while(t.base <= 0){
            printf("ERRO: Medida invalida. Base do triangulo (em metros): ");
            scanf("%f", &t.base);
        }

        //Altura
        printf("Altura do triangulo (em metros): ");
        scanf("%f", &t.altura);
        while(t.altura <= 0){
            printf("ERRO: Medida invalida. Altura do triangulo (em metros): ");
            scanf("%f", &t.altura);
        }

        inserirFinal_T(l, t);
    }

    //Circulo
    if(escolhaObjeto == 3){
        Circulo c;

        printf("\n\n-- CADASTRO --\n\n");

        //Raio
        printf("Raio do circulo (em metros): ");
        scanf("%f", &c.raio);
        while(c.raio <= 0){
            printf("ERRO: Medida invalida. Raio do circulo (em metros): ");
            scanf("%f", &c.raio);
        }

        inserirFinal_C(l, c);
    }
}

//Cadastrar retangulo
int inserirFinal_R(Lista *l, Retangulo r){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->retangulos[l->prox] = r;
    l->retangulos[l->prox].area = calcularArea(l, 1);

    l->retangulos[l->prox].check = 1;
    l->triangulos[l->prox].check = 0;
    l->circulos[l->prox].check = 0;

    l->prox++;

    printf("\n- Retangulo registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Cadastrar triangulo
int inserirFinal_T(Lista *l, Triangulo t){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->triangulos[l->prox] = t;
    l->triangulos[l->prox].area = calcularArea(l, 2);

    l->retangulos[l->prox].check = 0;
    l->triangulos[l->prox].check = 1;
    l->circulos[l->prox].check = 0;

    l->prox++;

    printf("\n- Triangulo registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Cadastrar circulo
int inserirFinal_C(Lista *l, Circulo c){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }

    l->circulos[l->prox] = c;
    l->circulos[l->prox].area = calcularArea(l, 3);

    l->retangulos[l->prox].check = 0;
    l->triangulos[l->prox].check = 0;
    l->circulos[l->prox].check = 1;

    l->prox++;

    printf("\n- Circulo registrado com sucesso. -\n\n");
    system("PAUSE");

    return 1;
}

//Calcula a area dos objetos
float calcularArea(Lista *l, int escolhaObjeto){
    float A;

    if(escolhaObjeto == 1){ //Retangulo
        A = l->retangulos[l->prox].base * l->retangulos[l->prox].altura;
    }else if(escolhaObjeto == 2){ //Triangulo
        A = (l->triangulos[l->prox].base * l->triangulos[l->prox].altura) / 2;
    }else{ //Circulo
        A = 3.14 * (l->circulos[l->prox].raio * l->circulos[l->prox].raio);
    }

    return A;
}

//Exibir lista de objetos cadastrados
void exibir(Lista *l){
    if(l == NULL){
        printf("\nOcorreu um erro.\n");
        system("PAUSE");
        return 0;
    }
    if(l->prox == 0){
        printf("\nNao ha qualquer objeto registrado.\n");
        system("PAUSE");
        return 0;
    }

    int i;

    system("CLS");
    printf("\nOBJETOS REGISTRADOS:\n");

    for(i = 0; i < l->prox; i++){
        if(l->retangulos[i].check == 1){
            printf("\n[%d] Retangulo\nBase (b) = %.1f m\nAltura (h) = %.1f m\nArea (A) = %.1f m. quadrados\n", i+1, l->retangulos[i].base, l->retangulos[i].altura, l->retangulos[i].area);
        }else if(l->triangulos[i].check == 1){
            printf("\n[%d] Triangulo\nBase (b) = %.1f m\nAltura (h) = %.1f m\nArea (A) = %.1f m. quadrados\n", i+1, l->triangulos[i].base, l->triangulos[i].altura, l->triangulos[i].area);
        }else if(l->circulos[i].check == 1){
            printf("\n[%d] Circulo\nRaio (r) = %.1f m\nArea (A) = %.1f m. quadrados\n", i+1, l->circulos[i].raio, l->circulos[i].area);
        }
    }
    printf("\n");
    system("PAUSE");
}
