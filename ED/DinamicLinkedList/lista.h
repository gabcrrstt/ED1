#define MAX 100

// tipo de dado
typedef struct
{
  int chave;
} tipo_elem;

// Estrutura de dados
typedef struct No
{
  tipo_elem info;
  struct No *prox;
} No;

typedef struct
{
  No* Inicio;
} Lista;

// Operacoes
void iniciar(Lista *L);
int vazia(Lista *L);
int inserir(Lista *L, tipo_elem v);
int inserir_final(Lista *L, tipo_elem v);
int inserir_ord(Lista *L, tipo_elem v);
int inserir_inicio(Lista *L, tipo_elem v);
int inserir_apos(Lista *L, tipo_elem v, No *K);
int remover(Lista *L, int chave);
//int remover_apos(Lista *l, No*K);
int tamanho(Lista *L);
void Destruir(Lista *L);
void exibir(Lista *L);
No* buscaSequencial(Lista *L, int chave);
int exibirUmElem(Lista *L, No *k);