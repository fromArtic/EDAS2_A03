#define MAX 30000 //Maximo de produtos suportado pelo mercado

//Registro dos produtos
typedef struct produto{
    int codigo;
    char nome[50];
    char descricao[50];
    float valor;
    int quantEstoque;
    int diaUltimaCompra;
    int mesUltimaCompra;
}Produto;

//Redefinicao de lista para Lista
typedef struct lista Lista;

//Alocacao de memoria para a lista
Lista *criarLista();

//Menu de entrada do sistema
int menu();

//Query para entradas do usuario
void query(Lista *l, int escolha);

//Cadastro de produtos
int inserirFinal(Lista *l, Produto p);

//Buscar por menor preco
void buscaPorMenorPreco(Lista *l);

//Buscar produtos com estoque inferior ao valor informado
void buscaPorEstoqueInferiorAoInformado(Lista *l, int valor);

//Apagar produto do cadastro
void apagarProduto(Lista *l, int c);

//Atualizar cadastro de produto
void atualizarProduto(Lista *l, int c);

//Impressao de relatorios do estoque
void relatorio(Lista *l, int escolha);
