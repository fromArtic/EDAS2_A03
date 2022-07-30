//Redefinicao de racional para Racional
typedef struct racional Racional;

//Retorna um valor racional
Racional *criaR(int numerador, int *denominador);

//Imprime o valor racional
void imprimiR(Racional *R);

//Retorna a somatoria entre dois racionais
double somaR(Racional *R1, Racional *R2);

//Retorna a multiplicacao entre dois racionais
double multiplicaR(Racional *R1, Racional *R2);

//Testa se ha igualdade entre dois racionais
void checarIgualdade(Racional *R1, Racional *R2);
