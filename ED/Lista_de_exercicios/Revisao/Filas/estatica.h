#define MAX 100

typedef struct{
  int chave;
}tipo_elem;

typedef  struct {
  tipo_elem A[MAX];
  int Nelem;
}Lista;

void criar(Lista *L);
void inserir (Lista *L, tipo_elem v);
int vazia(Lista *L);
int cheia(Lista *L);
int primeiro(Lista *L);
void remover(Lista *L);
void reverso(Lista *L);
int numElem(Lista *L);