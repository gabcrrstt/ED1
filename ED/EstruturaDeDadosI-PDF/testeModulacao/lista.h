#define MAX 100
//tipo de dado

typedef struct{

    int chave;
    //colocar dados de client e etc...
}tipo_elem;

//Estrutura de dados

typedef struct{

    tipo_elem A[MAX];
    int nelem;
} Lista;

//Operacoes
void iniciar(Lista *L);

int vazia(Lista *L);

int cheia(Lista *L);

int inserir(Lista *L, tipo_elem v);

int inserir_final(Lista *L, tipo_elem v);

int inserir_ord(Lista *L, tipo_elem v);

int inserir_posi(Lista *L, tipo_elem v, int k);

int inserir_inicio(Lista *L, tipo_elem v);

int remover(Lista *L, int chave);

int tamanho(Lista *L);

void apagar(Lista *L);

void finalizar(Lista *L);

void exibir(Lista *L);

