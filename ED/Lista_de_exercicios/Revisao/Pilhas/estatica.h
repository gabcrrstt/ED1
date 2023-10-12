#define MAX 100

typedef struct{
  char chave;
}tipo_elem;

typedef  struct {
  tipo_elem A[MAX];
  int Nelem;
}Lista;

void criar(Lista *L);
void push(Lista *L, tipo_elem v);
int vazia(Lista *L);
int topo(Lista *L);
void pop(Lista *L);
void destruir(Lista *L);
void transformar_tradicional_polonesa(char *s);

