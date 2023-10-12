
#define MAX 100

typedef struct {
  int chave;
}tipo_elem;

typedef struct {
  tipo_elem A[MAX];
  int ult; // SE ULT APONTA PARA O ULTIMO ELEMENTO, ENTAO ELE É A QUANTIDADE DE ELEMENTOS, POSTO QUE ESTÁ EM INTEIRO.
}Lista;



void inserir(Lista *L, tipo_elem v);
int cheia(Lista *L);
int vazia(Lista *L);
void iniciar(Lista *L);
int verificar_item(Lista *L, tipo_elem v);
void elimina(Lista *L, tipo_elem v);
int busca(Lista *L, tipo_elem v);