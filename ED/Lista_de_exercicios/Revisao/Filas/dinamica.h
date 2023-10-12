
typedef struct{
  int chave;
} tipo_elem;

typedef struct No{
  tipo_elem info;
  struct No *prox;
} No;

typedef struct {
  No* Inicio;
} Lista;

void criar(Lista *L);
void inserir (Lista *L, tipo_elem v);
int vazia(Lista *L);
int primeiro(Lista *L);
void remover_final(Lista *L);
void reverso(Lista *L);
int numElem(Lista *L);
void exibir_lista(Lista *L);