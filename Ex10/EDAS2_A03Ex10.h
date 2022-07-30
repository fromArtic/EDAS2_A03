//Registro dos avioes
typedef struct tipoNo{
    int combRestante; //Porcentagem de combustivel restante no aviao
    struct tipoNo *prox;
}No;

//Registra avioes a lista (PRIORIDADE: combustivel disponivel < 25%)
void inserirComPrioridade(No **fila, int c);

//Exibe a fila ordenada de avioes
void imprimir(No *fila);

//Apos seu pouso, remove o aviao em primeira colocacao e avanca a fila
No *avancar(No **fila);
